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
#include <random>

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
const int INF = 1e12;
const int MOD = 1e9 + 7;

mt19937 rnd(228);

class BProizvedeniyaStepeni {
public:
    void solve(std::istream &in, std::ostream &out) {
        int n, k;
        in >> n >> k;
        vc<int> prost;
        for (int i = 2; i < MAXN; i++) {
            bool prav = 1;
            for (auto v : prost) {
                if (v * v > i) {
                    break;
                }
                if (i % v == 0) {
                    prav = 0;
                    break;
                }
            }
            if (prav) {
                prost.pb(i);
            }
        }
        vc<int> leks(k);
        for (auto &v : leks) {
            v = rnd() % 300;
        }
        leks[0] = 0;
        map<int, int> sex;
        set<int> sexx;
        vc<int> a(n);
        in >> a;
        map<int, int> keks;
        int ans = 0;
        for (auto v : a) {
            map<int, int> meks;
            for (int i = 0; i < len(prost); i++) {
                if (prost[i] * prost[i] > v) {
                    break;
                }
                while (v % prost[i] == 0) {
                    meks[prost[i]]++;
                    v /= prost[i];
                }
            }
            if (v > 1) {
                meks[v]++;
            }
            int sums = 0;
            int sums1 = 0;
            for (auto v : meks) {
                if (sex.find(v.fs) == sex.end()) {
                    int vv = rnd() % INF;
                    while (sexx.find(vv) != sexx.end()) {
                        vv = rnd() % INF;
                    }
                    sexx.insert(vv);
                    sex[v.fs] = vv;
                }
                sums += leks[(v.sc % k)] * sex[v.fs];
                sums1 += leks[((k - (v.sc % k)) % k)] * sex[v.fs];
            }
            ans += keks[sums1];
            keks[sums]++;
        }
        out << ans;
    }
};


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    BProizvedeniyaStepeni solver;
    std::istream &in(std::cin);
    std::ostream &out(std::cout);
    solver.solve(in, out);
    return 0;
}