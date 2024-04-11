/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author Azat Ismagilov
 */

#include <fstream>

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <numeric>
#include <set>
#include <map>

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

const int MAXN = 3e5;
const int INF = 1e9;
const int MOD = 1e9 + 7;

class C1SbalansirovannieUdaleniyaPoproshe {
public:
    void solve(std::istream &in, std::ostream &out) {
        int n;
        in >> n;
        vc<pr<pr<int, int>, pr<int, int>>> mems(n);
        for (int i = 0; i < n; i++) {
            in >> mems[i].fs.fs >> mems[i].fs.sc >> mems[i].sc.fs;
            mems[i].sc.sc = i;
        }
        vc<bool> used(n);
        set<pr<pr<int, int>, pr<int, int>>> keks;
        for (int i = 0; i < n; i++) {
            keks.insert(mems[i]);
        }
        for (int i = 0; i < n / 2; i++) {
            auto it = *keks.begin();
            keks.erase(it);
            auto nows = *keks.lower_bound(it);
            {
                auto nows1 = keks.lower_bound({{nows.fs.fs, it.fs.sc},
                                               {-INF,       0}});
                if (nows1 == keks.end() || (*nows1).fs.fs > nows.fs.fs) {
                    nows1--;
                }
                nows = *nows1;
            }
            {
                auto nows1 = keks.lower_bound({{nows.fs.fs, nows.fs.sc},
                                               {it.sc.fs,   0}});
                if (nows1 == keks.end() || (*nows1).fs > nows.fs) {
                    nows1--;
                }
                nows = *nows1;
            }
            out << it.sc.sc + 1 << ' ' << nows.sc.sc + 1 << '\n';
            keks.erase(nows);
        }

    }
};


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    C1SbalansirovannieUdaleniyaPoproshe solver;
    std::istream &in(std::cin);
    std::ostream &out(std::cout);
    solver.solve(in, out);
    return 0;
}