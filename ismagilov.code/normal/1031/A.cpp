/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author Azat Ismagilov
 */

#include <fstream>

#include <bits/stdc++.h>

#define int long long
#define ld long double
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define len(v) ((int)v.size())
#define vc vector
#define pr pair
#define all(v) v.begin(), v.end()
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize("unroll-loops")

using namespace std;

template<typename T, typename U>
inline ostream &operator<<(ostream &_out, const pair<T, U> &_p) {
	_out << _p.first << ' ' << _p.second;
	return _out;
}

template<typename T, typename U>
inline istream &operator>>(istream &_in, pair<T, U> &_p) {
	_in >> _p.first >> _p.second;
	return _in;
}

template<typename T>
inline ostream &operator<<(ostream &_out, const vector<T> &_v) {
	if (_v.empty()) { return _out; }
	_out << _v.front();
	for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) { _out << ' ' << *_it; }
	return _out;
}

template<typename T>
inline istream &operator>>(istream &_in, vector<T> &_v) {
	for (auto &_i : _v) { _in >> _i; }
	return _in;
}

const int MAXN = 1e5;
const int INF = 1e9;
const int MOD = 1e9 + 7;


class BGermes {
public:
	void solve(std::istream &in, std::ostream &out) {
		int w, h, k;
		in >> w >> h >> k;
		int ans = 0;
		for (int i = 0; i < k; i++){
			ans += 2 * max(1ll, w + h - 2);
			w -= 4;
			h -= 4;
		}
		out << ans;
	}
};


signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	BGermes solver;
#ifndef ONLINE_JUDGE
	std::ifstream in("c:\\Users\\10a\\Desktop\\Azat\\input.txt");
	std::ofstream out("c:\\Users\\10a\\Desktop\\Azat\\output.txt");
#else
	istream &in(cin);
	ostream &out(cout);
#endif
	solver.solve(in, out);
	return 0;
}