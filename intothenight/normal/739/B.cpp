#include <bits/stdc++.h>
using namespace std;

// DEBUG BEGIN
#ifdef LOCAL
template<class L, class R> ostream &operator<<(ostream &out, const pair<L, R> &p){
	return out << "(" << p.first << ", " << p.second << ")";
}
template<class Tuple, size_t N> struct TuplePrinter{
	static ostream &print(ostream &out, const Tuple &t){ return TuplePrinter<Tuple, N-1>::print(out, t) << ", " << get<N-1>(t); }
};
template<class Tuple> struct TuplePrinter<Tuple, 1>{
	static ostream &print(ostream &out, const Tuple& t){ return out << get<0>(t); }
};
template<class... Args> ostream &print_tuple(ostream &out, const tuple<Args...> &t){
	return TuplePrinter<decltype(t), sizeof...(Args)>::print(out << "(", t) << ")";
}
template<class ...Args> ostream &operator<<(ostream &out, const tuple<Args...> &t){
	return print_tuple(out, t);
}
template<class T> ostream &operator<<(enable_if_t<!is_same<T, string>::value, ostream> &out, const T &arr){
	out << "{"; for(auto &x: arr) out << x << ", ";
	return out << (arr.size() ? "\b\b" : "") << "}";
}
template<size_t S> ostream &operator<<(ostream &out, const bitset<S> &b){
	for(int i = 0; i < S; ++ i) out << b[i];
	return out;
}
void debug_out(){ cerr << "\b\b " << endl; }
template<class Head, class... Tail>
void debug_out(Head H, Tail... T){ cerr << H << ", ", debug_out(T...); }
void debug2_out(){ cerr << "-----DEBUG END-----\n"; }
template<class Head, class... Tail>
void debug2_out(Head H, Tail... T){ cerr << "\n"; for(auto x: H) cerr << x << "\n"; debug2_out(T...); }
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#define debug2(...) cerr << "----DEBUG BEGIN----\n[" << #__VA_ARGS__ << "]:", debug2_out(__VA_ARGS__)
#else
#define debug(...) 42
#define debug2(...) 42
#endif
// DEBUG END

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> val(n);
	for(auto u = 0; u < n; ++ u){
		cin >> val[u];
	}
	vector<vector<pair<int, long long>>> par(__lg(n) + 1, vector<pair<int, long long>>(n, {-1, 0}));
	vector<vector<int>> adj(n);
	for(auto u = 1; u < n; ++ u){
		int p, w;
		cin >> p >> w, -- p;
		par[0][u] = {p, w};
		adj[p].push_back(u);
	}
	for(auto bit = 1; bit <= __lg(n); ++ bit){
		for(auto u = 0; u < n; ++ u){
			auto [p, w] = par[bit - 1][u];
			if(~p){
				par[bit][u] = {
					par[bit - 1][p].first
					, w + par[bit - 1][p].second
				};
			}
		}
	}
	vector<int> cnt(n);
	for(auto u = 0; u < n; ++ u){
		if(~par[0][u].first){
			++ cnt[par[0][u].first];
			int p = u;
			long long x = val[u];
			for(auto bit = __lg(n); bit >= 0; -- bit){
				if(~par[bit][p].first && par[bit][p].second <= x){
					x -= par[bit][p].second;
					p = par[bit][p].first;
				}
			}
			if(~par[0][p].first){
				-- cnt[par[0][p].first];
			}
		}
	}
	debug(cnt);
	function<void(int)> dfs = [&](int u){
		for(auto v: adj[u]){
			dfs(v);
			cnt[u] += cnt[v];
		}
	};
	dfs(0);
	for(auto x: cnt){
		cout << x << " ";
	}
	cout << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////