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


vc<int> t;

void upd(int v, int news) {
    for (; v < len(t); v = (v + 1) | v) {
        t[v] = min(t[v], news);
    }
}

int gets(int v) {
    int ans = INF;
    for (; v >= 0; v = ((v + 1) & v) - 1) {
        ans = min(ans, t[v]);
    }
    return ans;
}

class DSbalansirovanniiPleilist {
public:
    void solve(std::istream &in, std::ostream &out) {
        int n;
        in >> n;
        vc<int> a(n);
        in >> a;
        map<int, int> keks;
        for (auto v : a) {
            keks[v] = 0;
        }
        int lasts = 0;
        for (auto &v : keks) {
            v.sc = lasts++;
        }
        t.assign(lasts, INF);
        vc<int> c(3 * n + 1, INF);
        for (int i = 2 * n - 1; i >= 0; i--) {
            upd(keks[a[i % n]], i + n);
            auto it = keks.lower_bound((int) ((a[i % n] + 1) / 2));
            if (it != keks.begin()) {
                it--;
                c[i + n] = gets((*it).sc) - (i + n);
            }
            if (c[i + n] > 2 * n) {
                c[i + n] = INF;
            }
            c[i + n] = min(c[i + n], c[i + n + 1] + 1);
        }
        for (int i = n - 1; i >= 0; i--) {
            upd(keks[a[i]], i);
            auto it = keks.lower_bound((int) ((a[i] + 1) / 2));
            if (it != keks.begin()) {
                it--;
                c[i] = gets((*it).sc) - i;
            }
            c[i] = min(c[i], c[i + 1] + 1);
        }
        for (int i = 0; i < n; i++) {
            if (c[i] >= INF) {
                c[i] = -1;
            }
            out << c[i] << ' ';
        }
    }
};


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    DSbalansirovanniiPleilist solver;
    std::istream &in(std::cin);
    std::ostream &out(std::cout);
    solver.solve(in, out);
    return 0;
}