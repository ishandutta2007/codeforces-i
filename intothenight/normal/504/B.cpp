#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template<typename L, typename R> istream &operator>>(istream &in, pair<L, R> &p){ return in >> p.first >> p.second; }
template<typename Tuple, size_t ...Is> void read_tuple(istream &in, Tuple &t, index_sequence<Is...>){ ((in >> get<Is>(t)), ...); }
template<typename ...Args> istream &operator>>(istream &in, tuple<Args...> &t){ read_tuple(in, t, index_sequence_for<Args...>{}); return in; }
template<typename ...Args, template<typename...> typename T> istream &operator>>(enable_if_t<!is_same_v<T<Args...>, string>, istream> &in, T<Args...> &arr){ for(auto &x: arr) in >> x; return in; }
template<typename L, typename R> ostream &operator<<(ostream &out, const pair<L, R> &p){ return out << "(" << p.first << ", " << p.second << ")"; }
//template<typename L, typename R> ostream &operator<<(ostream &out, const pair<L, R> &p){ return out << p.first << " " << p.second << "\n"; }
template<typename Tuple, size_t ...Is> void print_tuple(ostream &out, const Tuple &t, index_sequence<Is...>){ ((out << (Is ? " " : "") << get<Is>(t)), ...); }
template<typename ...Args> ostream &operator<<(ostream &out, const tuple<Args...> &t){ print_tuple(out, t, index_sequence_for<Args...>{}); return out << "\n"; }
template<typename ...Args, template<typename...> typename T> ostream &operator<<(enable_if_t<!is_same_v<T<Args...>, string>, ostream> &out, const T<Args...> &arr){ for(auto &x: arr) out << x << " "; return out << "\n"; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngll(chrono::steady_clock::now().time_since_epoch().count());
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
typedef long long ll;
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<double> vd; typedef vector<string> vs;
typedef pair<int, int> pii; typedef pair<ll, ll> pll; typedef pair<int, ll> pil; typedef pair<ll, int> pli;
typedef vector<pii> vpii; typedef vector<pil> vpil; typedef vector<pli> vpli; typedef vector<pll> vpll;
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef tuple<int, int, int> tpl; typedef vector<tpl> vtpl;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vi p(n), q(n);
	cin >> p >> q;
	Tree<int> tp, tq;
	vi r(n);
	for(int i = n - 1, carry = 0; i >= 0; -- i){
		int x = carry + tp.order_of_key(p[i]) + tq.order_of_key(q[i]);
		carry = x / (n - i);
		r[i] = x % (n - i);
		tp.insert(p[i]), tq.insert(q[i]);
	}
	Tree<int> tr;
	for(int i = 0; i < n; ++ i){
		tr.insert(i);
	}
	for(int i = 0; i < n; ++ i){
		int x;
		cout << (x = *tr.find_by_order(r[i])) << " ";
		tr.erase(x);
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