/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author Azat Ismagilov
 */

#include <bits/stdc++.h>

#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define len(v) ((int)v.size())
#define vc vector
#define pr pair
#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef long double ld;

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

class TaskC {
public:
    void solve(std::istream &in, std::ostream &out) {
        int k;
        in >> k;
        string s, a, b;
        in >> s >> a >> b;
        int n = len(s);
        map<char, char> d;
        unordered_set<char> fres;
        for (char c = 'a'; c < 'a' + k; c++) {
            fres.insert(c);
            d[c] = 0;
        }
        int pos = 0;
        for (int i = 0; i < n && a[i] == b[i]; i++, pos++) {
            if (d[s[i]] == 0) {
                if (fres.find(a[i]) == fres.end()) {
                    out << "NO\n";
                    return;
                }
                d[s[i]] = a[i];
                fres.erase(a[i]);
            } else {
                if (d[s[i]] != a[i]) {
                    out << "NO\n";
                    return;
                }
            }
        }
        if (pos == n) {
            out << "YES\n";
            for (auto &v : d) {
                if (v.sc == 0) {
                    v.sc = *fres.begin();
                    fres.erase(fres.begin());
                }
                out << v.sc;
            }
            out << "\n";
            return;
        }
        {
            auto x = d;
            auto frex = fres;
            for (int i = pos; i < n; i++) {
                if (x[s[i]] == 0) {
                    if (i == pos) {
                        for (char c = a[i] + 1; c < b[i]; c++) {
                            if (frex.find(c) != frex.end()) {
                                out << "YES\n";
                                x[s[i]] = c;
                                frex.erase(c);
                                for (auto &v : x) {
                                    if (v.sc == 0) {
                                        v.sc = *frex.begin();
                                        frex.erase(frex.begin());
                                    }
                                    out << v.sc;
                                }
                                out << "\n";
                                return;
                            }
                        }
                    }
                    else{
                        for (char c = a[i] + 1; c < 'a' + k; c++) {
                            if (frex.find(c) != frex.end()) {
                                out << "YES\n";
                                x[s[i]] = c;
                                frex.erase(c);
                                for (auto &v : x) {
                                    if (v.sc == 0) {
                                        v.sc = *frex.begin();
                                        frex.erase(frex.begin());
                                    }
                                    out << v.sc;
                                }
                                out << "\n";
                                return;
                            }
                        }

                    }
                    if (frex.find(a[i]) == frex.end()) {
                        break;
                    }
                    x[s[i]] = a[i];
                    frex.erase(a[i]);
                } else {
                    if (a[i] < x[s[i]] && (i != pos || x[s[i]] < b[i])) {
                        out << "YES\n";
                        for (auto &v : x) {
                            if (v.sc == 0) {
                                v.sc = *frex.begin();
                                frex.erase(frex.begin());
                            }
                            out << v.sc;
                        }
                        out << "\n";
                        return;
                    }
                    if (a[i] != x[s[i]]) {
                        break;
                    }
                }
                if (i == n - 1) {
                    out << "YES\n";
                    for (auto &v : x) {
                        if (v.sc == 0) {
                            v.sc = *frex.begin();
                            frex.erase(frex.begin());
                        }
                        out << v.sc;
                    }
                    out << "\n";
                    return;
                }
            }
        }
        {
            auto x = d;
            auto frex = fres;
            for (int i = pos; i < n; i++) {
                if (x[s[i]] == 0) {
                    if (i == pos) {
                        for (char c = a[i] + 1; c < b[i]; c++) {
                            if (frex.find(c) != frex.end()) {
                                out << "YES\n";
                                x[s[i]] = c;
                                frex.erase(c);
                                for (auto &v : x) {
                                    if (v.sc == 0) {
                                        v.sc = *frex.begin();
                                        frex.erase(frex.begin());
                                    }
                                    out << v.sc;
                                }
                                out << "\n";
                                return;
                            }
                        }
                    }
                    else{
                        for (char c = 'a'; c < b[i]; c++) {
                            if (frex.find(c) != frex.end()) {
                                out << "YES\n";
                                x[s[i]] = c;
                                frex.erase(c);
                                for (auto &v : x) {
                                    if (v.sc == 0) {
                                        v.sc = *frex.begin();
                                        frex.erase(frex.begin());
                                    }
                                    out << v.sc;
                                }
                                out << "\n";
                                return;
                            }
                        }

                    }
                    if (frex.find(b[i]) == frex.end()) {
                        break;
                    }
                    x[s[i]] = b[i];
                    frex.erase(b[i]);
                } else {
                    if (b[i] > x[s[i]] && (i != pos || x[s[i]] > a[i])) {
                        out << "YES\n";
                        for (auto &v : x) {
                            if (v.sc == 0) {
                                v.sc = *frex.begin();
                                frex.erase(frex.begin());
                            }
                            out << v.sc;
                        }
                        out << "\n";
                        return;
                    }
                    if (b[i] != x[s[i]]) {
                        break;
                    }
                }
                if (i == n - 1) {
                    out << "YES\n";
                    for (auto &v : x) {
                        if (v.sc == 0) {
                            v.sc = *frex.begin();
                            frex.erase(frex.begin());
                        }
                        out << v.sc;
                    }
                    out << "\n";
                    return;
                }
            }
        }
        out << "NO\n";
    }
};


main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	TaskC solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	int n;
in >> n;
for(int i = 0; i < n; ++i) {
	solver.solve(in, out);
}

	return 0;
}