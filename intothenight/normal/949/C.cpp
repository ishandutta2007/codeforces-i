#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template<class L, class R> istream &operator>>(istream &in, pair<L, R> &p){ return in >> p.first >> p.second; }
template<class Tuple, size_t ...Is> void read_tuple(istream &in, Tuple &t, index_sequence<Is...>){ ((in >> get<Is>(t)), ...); }
template<class ...Args> istream &operator>>(istream &in, tuple<Args...> &t){ read_tuple(in, t, index_sequence_for<Args...>{}); return in; }
template<class ...Args, template<class...> class T> istream &operator>>(enable_if_t<!is_same_v<T<Args...>, string>, istream> &in, T<Args...> &arr){ for(auto &x: arr) in >> x; return in; }
template<class L, class R> ostream &operator<<(ostream &out, const pair<L, R> &p){ return out << "(" << p.first << ", " << p.second << ")"; }
//template<class L, class R> ostream &operator<<(ostream &out, const pair<L, R> &p){ return out << p.first << " " << p.second << "\n"; }
template<class Tuple, size_t ...Is> void print_tuple(ostream &out, const Tuple &t, index_sequence<Is...>){ ((out << (Is ? " " : "") << get<Is>(t)), ...); }
template<class ...Args> ostream &operator<<(ostream &out, const tuple<Args...> &t){ print_tuple(out, t, index_sequence_for<Args...>{}); return out << "\n"; }
template<class ...Args, template<class...> class T> ostream &operator<<(enable_if_t<!is_same_v<T<Args...>, string>, ostream> &out, const T<Args...> &arr){ for(auto &x: arr) out << x << " "; return out << "\n"; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngll(chrono::steady_clock::now().time_since_epoch().count());
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
typedef long long ll;
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<double> vd; typedef vector<string> vs;
typedef pair<int, int> pii; typedef pair<ll, ll> pll; typedef pair<int, ll> pil; typedef pair<ll, int> pli;
typedef vector<pii> vpii; typedef vector<pil> vpil; typedef vector<pli> vpli; typedef vector<pll> vpll;
template<class T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<class T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef tuple<int, int, int> tpl; typedef vector<tpl> vtpl;

template<class G, class F>
int scc(const G &g, F f){
	int n = sz(g);
	vi val(n, 0), comp(n, -1), z, cur;
	int Time = 0, ncomps = 0;
	auto dfs = [&](int u, auto &dfs)->int{
		int low = val[u] = ++ Time, v;
		z.push_back(u);
		for(auto v: g[u]) if(comp[v] < 0) low = min(low, val[v] ?: dfs(v, dfs));
		if(low == val[u]){
			do{
				v = z.back(); z.pop_back();
				comp[v] = ncomps;
				cur.push_back(v);
			}while(v != u);
			f(cur); // Process SCCs in reverse topological order
			cur.clear();
			ncomps ++;
		}
		return val[u] = low;
	};
	for(int u = 0; u < n; ++ u) if(comp[u] < 0) dfs(u, dfs);
	return ncomps;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m, h;
	cin >> n >> m >> h;
	vi time(n);
	cin >> time;
	vector<vi> adj(n);
	for(int i = 0; i < m; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		if((time[u] + 1) % h == time[v]){
			adj[u].push_back(v);
		}
		if((time[v] + 1) % h == time[u]){
			adj[v].push_back(u);
		}
	}
	vector<vi> comp;
	vi ind(n);
	scc(adj, [&](const vi &c){
		for(auto u: c){
			ind[u] = sz(comp);
		}
		comp.push_back(c);
	});
	vi outdeg(sz(comp));
	for(int u = 0; u < n; ++ u){
		for(auto v: adj[u]){
			if(ind[u] != ind[v]){
				++ outdeg[ind[u]];
			}
		}
	}
	pii res{2e9, 2e9};
	for(int i = 0; i < sz(comp); ++ i){
		if(!outdeg[i]){
			ctmin(res, pii{sz(comp[i]), i});
		}
	}
	cout << sz(comp[res.second]) << "\n";
	for(auto u: comp[res.second]){
		cout << u + 1 << " ";
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