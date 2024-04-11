#include <bits/stdc++.h>
using namespace std;

template<class F>
struct y_combinator_result{
	F f;
	template<class T> explicit y_combinator_result(T &&f): f(forward<T>(f)){ }
	template<class ...Args> decltype(auto) operator()(Args &&...args){ return f(ref(*this), forward<Args>(args)...); }
};
template<class F>
decltype(auto) y_combinator(F &&f){
	return y_combinator_result<decay_t<F>>(forward<F>(f));
}

template<class T, class F>
struct treap_query{
	vector<int> pv, left, right, priority, internal_size;
	vector<T> data, subtr_data;
	F TT; // monoid operation (always adjacent)
	T T_id; // monoid identity
	treap_query(F TT, T T_id): TT(TT), T_id(T_id){ }
	void refresh(int u){
		pv[u] = -1;
		internal_size[u] = 1;
		subtr_data[u] = T_id;
		if(auto v = left[u]; ~v){
			pv[v] = u;
			internal_size[u] += internal_size[v];
			subtr_data[u] = subtr_data[v];
		}
		subtr_data[u] = TT(subtr_data[u], data[u]);
		if(auto w = right[u]; ~w){
			pv[w] = u;
			internal_size[u] += internal_size[w];
			subtr_data[u] = TT(subtr_data[u], subtr_data[w]);
		}
	}
	void heapify(int u){
		if(~u){
			int v = u;
			if(~left[u] && priority[left[u]] > priority[v]) v = left[u];
			if(~right[u] && priority[right[u]] > priority[v]) v = right[u];
			if(u != v) swap(priority[u], priority[v]), heapify(v);
		}
	}
	int size(int u){
		return ~u ? internal_size[u] : 0;
	}
	// Assuming v lies in the subtree of u, find the position of v in the preorder traversal of subtree of u
	// O(log n)
	int position(int u, int v){
		assert(0 <= u && 0 <= v && u < (int)pv.size() && v < (int)pv.size());
		int pos = size(left[v]);
		for(; ~pv[v]; v = pv[v]) if(left[pv[v]] != v) pos += size(left[pv[v]]) + 1;
		assert(u == v);
		return pos;
	}
	// Split to [0, x), [x, inf), data must be sorted
	// O(log n)
	template<class Compare = less<>>
	pair<int, int> split_by_key(int u, T x, Compare cmp = less<>()){
		if(!~u) return {-1, -1};
		if(cmp(data[u], x)){
			auto [a, b] = split_by_key(right[u], x, cmp);
			right[u] = a, refresh(u);
			return {u, b};
		}
		else{
			auto [a, b] = split_by_key(left[u], x, cmp);
			left[u] = b, refresh(u);
			return {a, u};
		}
	}
	// Split into [0, pos), [pos, inf)
	// O(log n)
	pair<int, int> split_by_order(int u, int pos){
		if(!~u) return {-1, -1};
		if(size(left[u]) < pos){
			auto [a, b] = split_by_order(right[u], pos - size(left[u]) - 1);
			right[u] = a, refresh(u);
			return {u, b};
		}
		else{
			auto [a, b] = split_by_order(left[u], pos);
			left[u] = b, refresh(u);
			return {a, u};
		}
	}
	// Split to [True segment], [False segment]
	// Data must be sorted
	// O(log n)
	pair<int, int> split_by_pred(int u, auto pred){
		if(!~u) return {-1, -1};
		if(pred(u)){
			auto [a, b] = split_by_pred(right[u], pred);
			right[u] = a, refresh(u);
			return {u, b};
		}
		else{
			auto [a, b] = split_by_pred(left[u], pred);
			left[u] = b, refresh(u);
			return {a, u};
		}
	}
	// Split into [0, l), [l, r), [r, inf)
	// O(log n)
	array<int, 3> split_to_three(int u, int l, int r){
		assert(0 <= l && l <= r && r <= size(u));
		if(!~u) return {-1, -1, -1};
		int a, b, c;
		tie(a, b) = split_by_order(u, l);
		tie(b, c) = split_by_order(b, r - l);
		return {a, b, c};
	}
	// Split into [0, pos[0]), [pos[0], pos[1]), ..., [pos[k - 1], inf)
	// O(k log n)
	template<size_t k>
	array<int, k + 1> split(int u, array<int, k> pos){
		assert(is_sorted(pos.begin(), pos.end()));
		if(!~u){
			array<int, k + 1> res;
			res.fill(-1);
			return res;
		}
		array<int, k + 1> res;
		res[0] = u;
		int last = 0;
		for(auto i = 0; i < k; ++ i){
			tie(res[i], res[i + 1]) = split_by_order(res[i], pos[i] - last);
			last = pos[i];
		}
		return res;
	}
	// Append u and v
	// O(log n)
	int append(int u, int v){
		if(!~u || !~v) return ~u ? u : v;
		if(priority[v] < priority[u]){
			right[u] = append(right[u], v), refresh(u);
			return u;
		}
		else{
			left[v] = append(u, left[v]), refresh(v);
			return v;
		}
	}
	// Append treaps in order
	// O((list length) * log n)
	int append(initializer_list<int> list){
		return accumulate(list.begin(), list.end(), -1, [&](int u, int v){ return append(u, v); });
	}
	// Data must be sorted
	// O(log n)
	template<class Compare = less<>>
	int insert_by_key(int u, int v, Compare cmp = less<>()){
		if(!~u) return v;
		auto [a, b] = split_by_key(u, data[v], cmp);
		return append(append(a, v), b);
	}
	// O(log n)
	int insert_by_order(int u, int v, int pos){
		if(!~u) return v;
		auto [a, b] = split_by_order(u, pos);
		return append(append(a, v), b);
	}
	// Erase the smallest element >= x and returns a pair of {new root, erased element}
	// Data must be sorted
	// O(log n)
	template<class Compare = less<>>
	pair<int, int> erase_by_key(int u, T x, Compare cmp = less<>()){
		if(!~u) return {-1, -1};
		int a, b, c;
		tie(a, b) = split_by_key(u, x, cmp);
		tie(b, c) = split_by_order(b, 1);
		return {append(a, c), b};
	}
	// O(log n)
	pair<int, int> erase_by_order(int u, int pos){
		if(!~u) return {-1, -1};
		auto [a, b, c] = split_to_three(u, pos, pos + 1);
		return {append(a, c), b};
	}
	// Data must be sorted
	// O(min(size(u), size(v)) * log(size ratio))
	template<class Compare = less<>>
	int unite_by_key(int u, int v, Compare cmp = less<>()){
		if(!~u || !~v) return ~u ? u : v;
		if(priority[u] < priority[v]) swap(u, v);
		auto [a, b] = split_by_key(v, data[u], cmp);
		left[u] = unite_by_key(left[u], a, cmp);
		right[u] = unite_by_key(right[u], b, cmp);
		refresh(u);
		return u;
	}
	void traverse(int u, auto f){
		if(~u){
			traverse(left[u], f);
			f(u);
			traverse(right[u], f);
			refresh(u);
		}
	}
	template<class output_stream>
	output_stream &print(output_stream &out, int u){
		#ifdef LOCAL
		out << "[";
		traverse(u, [&](int u){ out << data[u] << ", "; });
		out << "\b\b]\n";
		#endif
		return out;
	}
	int new_node(T x, int v = -1, int w = -1){
		static mt19937 rng(1564);
		int u = (int)data.size();
		pv.push_back(-1);
		left.push_back(v);
		right.push_back(w);
		priority.push_back(rng());
		internal_size.push_back(1);
		data.push_back(x);
		subtr_data.push_back(x);
		heapify(u);
		refresh(u);
		return u;
	}
	int build(int n){
		return build(vector<T>(n, T_id));
	}
	int build(int n, T init){
		return build(vector<T>(n, init));
	}
	int build(const vector<T> &a){
		auto recurse = [&](auto self, int l, int r)->int{
			if(l == r) return -1;
			int m = l + (r - l >> 1);
			return new_node(a[m], self(self, l, m), self(self, m + 1, r));
		};
		return recurse(recurse, 0, (int)a.size());
	}
	// Return the node representing the k-th element
	// O(log n)
	int find_by_order(int u, int k){
		assert(0 <= k && k < size(u));
		auto [a, b, c] = split_to_three(u, k, k + 1);
		int res = b;
		append(append(a, b), c);
		return res;
	}
	// Data must be sorted
	// O(log n)
	template<class Compare = less<>>
	int order_of_key(int u, T x, Compare cmp = less<>()){
		auto [a, b] = split_by_key(u, x, cmp);
		int res = size(a);
		append(a, b);
		return res;
	}
	// Data must be [T, T, ..., T, F, F, ..., F]
	// O(log n)
	int pref_length(int u, auto pred){
		auto [a, b] = split_by_pred(u, pred);
		int res = size(a);
		append(a, b);
		return res;
	}
	// O(log n)
	T query(int u, int l, int r){
		assert(0 <= l && l <= r && r <= size(u));
		if(l == r) return T_id;
		auto [a, b, c] = split_to_three(u, l, r);
		T res = subtr_data[b];
		append(append(a, b), c);
		return res;
	}
	// pred(sum[ql, r)) is T, T, ..., T, F, F, ..., F
	// Returns max r with T
	// O(log n)
	int max_pref(int u, int ql, auto pred){
		int n = size(u);
		assert(0 <= ql && ql <= n && pred(T_id));
		if(ql == n) return n;
		T sum = T_id;
		auto recurse = [&](auto self, int u, int l)->int{
			int r = l + size(u);
			if(!~u || r <= ql) return n;
			if(ql <= l && pred(TT(sum, subtr_data[u]))){
				sum = TT(sum, subtr_data[u]);
				return n;
			}
			if(auto p = self(self, left[u], l); p < n) return p;
			l += size(left[u]);
			return ql <= l && !pred(sum = TT(sum, data[u])) ? l : self(self, right[u], l + 1);
		};
		return recurse(recurse, u, 0);
	}
	// pred(sum[l, qr)) is F, F, ..., F, T, T, ..., T
	// Returns min l with T
	// O(log n)
	int max_suff(int u, int qr, auto pred){
		int n = size(u);
		assert(0 <= qr && qr <= n && pred(T_id));
		if(qr == 0) return 0;
		T sum = T_id;
		auto recurse = [&](auto self, int u, int r)->int{
			int l = r - size(u);
			if(!~u || qr <= l) return 0;
			if(r <= qr && pred(TT(subtr_data[u], sum))){
				sum = TT(subtr_data[u], sum);
				return 0;
			}
			if(auto p = self(self, right[u], r); p > 0) return p;
			r -= size(right[u]);
			return r <= qr && !pred(sum = TT(data[u], sum)) ? r : self(self, left[u], r - 1);
		};
		return recurse(recurse, u, n);
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, qn;
	cin >> n >> qn;
	vector<vector<int>> adj(n);
	for(auto u = 0; u < n; ++ u){
		int m;
		cin >> m;
		for(auto i = 0; i < m; ++ i){
			int v;
			cin >> v, -- v;
			adj[u].push_back(v);
		}
	}
	vector<int> pos(n), end(n), order, pv(n, -1);
	y_combinator([&](auto self, int u)->void{
		pos[u] = (int)order.size();
		order.push_back(u);
		for(auto v: adj[u]){
			pv[v] = u;
			self(v);
		}
		order.push_back(~u);
		end[u] = (int)order.size();
	})(0);
	// sum
	// min prefix sum (only for start)
	// max prefix sum (only for start)
	// min prefix sum (only for end)
	// max prefix sum (only for end)
	// node corresponding to the min prefix sum of end pos
	using T = array<int, 6>;
	vector<T> init(n << 1);
	for(auto i = 0; i < n << 1; ++ i){
		init[i] = {
			order[i] >= 0 ? 1 : -1,
			order[i] >= 0 ? 1 : numeric_limits<int>::max() / 3,
			order[i] >= 0 ? 1 : numeric_limits<int>::min() / 3,
			order[i] < 0 ? -1 : numeric_limits<int>::max() / 3,
			order[i] < 0 ? -1 : numeric_limits<int>::min() / 3,
			max(order[i], ~order[i])
		};
	}
	auto TT = [&](const T &x, const T &y)->T{
		return{
			x[0] + y[0],
			min(x[1], x[0] + y[1]),
			max(x[2], x[0] + y[2]),
			min(x[3], x[0] + y[3]),
			max(x[4], x[0] + y[4]),
			x[3] < x[0] + y[3] ? x[5] : y[5]
		};
	};
	T T_id{
		0,
		numeric_limits<int>::max() / 3,
		numeric_limits<int>::min() / 3,
		numeric_limits<int>::max() / 3,
		numeric_limits<int>::min() / 3,
		-1
	};
	treap_query trp(TT, T_id);
	int root = trp.build(init);
	vector<int> starting_node(n, -1);
	vector<int> ending_node(n, -1);
	trp.traverse(root, [&](int x){
		static int cnt = 0;
		if(order[cnt] >= 0){
			starting_node[order[cnt]] = x;
		}
		else{
			ending_node[~order[cnt]] = x;
		}
		++ cnt;
	});
	auto depth = [&](int u)->int{
		return trp.query(root, 0, trp.position(root, starting_node[u]))[0];
	};
	auto lca = [&](int u, int v)->int{
		int ul = trp.position(root, starting_node[u]);
		int ur = trp.position(root, ending_node[u]);
		int vl = trp.position(root, starting_node[v]);
		int vr = trp.position(root, ending_node[v]);
		if(ul > vl){
			swap(u, v);
			swap(ul, vl);
			swap(ur, vr);
		}
		int w = vr <= ur ? u : pv[trp.query(root, ul, vl + 1)[5]];
		return w;
	};
	auto dist = [&](int u, int v)->int{
		return depth(u) + depth(v) - 2 * depth(lca(u, v));
	};
	for(auto qi = 0; qi < qn; ++ qi){
		int type;
		cin >> type;
		if(type == 1){
			int u, v;
			cin >> u >> v, -- u, -- v;
			cout << dist(u, v) << "\n";
		}
		else if(type == 2){
			int u, h;
			cin >> u >> h, -- u;
			h = depth(u) - h;
			int r = trp.position(root, starting_node[u]);
			int sum = trp.query(root, 0, r)[0];
			int v = trp.data[trp.find_by_order(root, trp.max_suff(root, r, [&](const auto &suff){
				return sum - suff[0] + suff[1] > h + 1 || sum - suff[0] + suff[2] < h + 1;
			}) - 1)][5];
			int a = r;
			int b = trp.position(root, ending_node[u]) + 1;
			int c = trp.position(root, ending_node[v]);
			assert(a <= b && b <= c);
			auto [x, y, z, w] = trp.split(root, array{a, b, c});
			root = trp.append({x, z, y, w});
			pv[u] = v;
		}
		else{
			int h;
			cin >> h;
			cout << trp.data[trp.find_by_order(root, trp.max_suff(root, n << 1, [&](const auto &suff){
				return -suff[0] + suff[3] > h || -suff[0] + suff[4] < h;
			}) - 1)][5] + 1 << "\n";
		}
	}
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////