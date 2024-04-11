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
 
 
 
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int tt;
	cin >> tt;
	while(tt --){
		int n;
		string s;
		cin >> n >> s;
		map<int, vi> q;
		vi qq(n + 1);
		int p = 0, pp = 0;
		q[0].push_back(0);
		for(int i = 0; i < n; ++ i){
			if(s[i] == 'L'){
				++ p;
			}
			if(s[i] == 'R'){
				-- p;
			}
			if(s[i] == 'U'){
				++ pp;
			}
			if(s[i] == 'D'){
				-- pp;
			}
			q[p].push_back(i + 1);
			qq[i + 1] = pp;
		}
		pii res{-1, 2e9};
		for(auto [__, v]: q){
			sort(all(v), [&](int i, int j){ return qq[i] < qq[j]; });
			for(int indi = 0; indi < sz(v); ){
				int indj = indi;
				vi t;
				while(indj < sz(v) && qq[v[indi]] == qq[v[indj]]){
					t.push_back(v[indj ++]);
				}
				sort(all(t));
				for(int i = 1; i < sz(t); ++ i){
					if(res.second - res.first > t[i] - t[i - 1]){
						res = {t[i - 1], t[i]};
					}
				}
				indi = indj;
			}
		}
		if(res.first == -1) cout << "-1\n";
		else cout << res.first + 1 << " " << res.second << "\n";
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