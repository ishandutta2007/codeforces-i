/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author Azat Ismagilov
 */

#include <fstream>

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

#define int long long
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

class DKrasiviiMassiv {
public:
    void solve(std::istream &in, std::ostream &out) {
        int n, x;
        in >> n >> x;
        vc<int> a(n);
        in >> a;
        vc<int> prefixsum(n + 1, 0);
        int maxans = 0;
        int maxprefixsum = 0;
        for (int i = 0; i < n; i++) {
            maxprefixsum += a[i];
            maxprefixsum = max(0ll, maxprefixsum);
            maxans = max(maxprefixsum, maxans + x * a[i]);
            prefixsum[i + 1] = maxans;
        }
        maxprefixsum = 0;
        int ans = max(0ll, maxans);
        for (int j = n - 1; j >= 0; j--) {
            maxprefixsum += a[j];
            maxprefixsum = max(0ll, maxprefixsum);
            ans = max(ans, maxprefixsum + prefixsum[j]);
        }
        out << ans;
    }
};


main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    DKrasiviiMassiv solver;
    std::istream &in(std::cin);
    std::ostream &out(std::cout);
    solver.solve(in, out);
    return 0;
}