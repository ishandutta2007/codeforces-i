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

class presentnadcandys {
public:
    void solve(std::istream &in, std::ostream &out) {
        int n, m;
        in >> n >> m;
        vc<int> b(n);
        in >> b;
        vc<int> g(m);
        in >> g;
        int mini = INF;
        int ans = 0;
        int maxi = -INF;
        for (auto v : b) {
            maxi = max(maxi, v);
            ans += v * m;
        }
        sort(all(b));
        sort(all(g));
        for (auto v : g) {
            mini = min(mini, v);
        }
        if (maxi > mini) {
            out << -1;
            return;
        }
        vc<int> usagecount(n);
        for (auto v : g) {
            auto it = prev(upper_bound(all(b), v)) - b.begin();
            if (it >= 0 && b[it] != v) {
                while (it >= 0 && usagecount[it] >= m - 1) {
                    it--;
                }
                if (it < 0) {
                    out << -1;
                    return;
                }
                usagecount[it]++;
                ans += v - b[it];
            }
        }
        out << ans;
    }
};


main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    presentnadcandys solver;
    std::istream &in(std::cin);
    std::ostream &out(std::cout);
    solver.solve(in, out);
    return 0;
}