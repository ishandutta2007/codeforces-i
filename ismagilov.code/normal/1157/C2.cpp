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

class C2VozrastayushayaPodposledovatelnostUslozhnennayaVersiya {
public:
    void solve(std::istream &in, std::ostream &out) {
        int n;
        in >> n;
        vc<int> a(n);
        in >> a;
        int counts1 = 1, counts2 = 1;
        while (counts1 < n && a[counts1] > a[counts1 - 1]) {
            counts1++;
        }
        while (counts2 < n && a[n - counts2 - 1] > a[n - counts2]) {
            counts2++;
        }
        string ans;
        int pos1 = 0;
        int pos2 = n - 1;
        while (pos1 <= pos2) {
            if (pos1 + 1 > counts1 && n - pos2 > counts2)
                break;
            if (pos1 + 1 <= counts1 && n - pos2 <= counts2) {
                if (a[pos1] == a[pos2]) {
                    if (counts2 - (n - pos2) > counts1 - (pos1 + 1)) {
                        ans.push_back('R');
                        pos2--;
                        counts1 = 0;
                    } else {
                        ans.push_back('L');
                        pos1++;
                        counts2 = 0;
                    }
                } else if (a[pos1] < a[pos2]) {
                    ans.push_back('L');
                    pos1++;
                } else {
                    ans.push_back('R');
                    pos2--;
                }
                continue;
            }
            if (pos1 + 1 <= counts1) {
                ans.push_back('L');
                pos1++;
            } else {
                ans.push_back('R');
                pos2--;
            }
        }
        out << len(ans) << '\n' << ans;
    }
};


main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    C2VozrastayushayaPodposledovatelnostUslozhnennayaVersiya solver;
    std::istream &in(std::cin);
    std::ostream &out(std::cout);
    solver.solve(in, out);
    return 0;
}