// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

namespace debug {
    const char yellow[] = "\x1b[33m";
    const char magenta[] = "\x1b[35m";
    const char blue[] = "\x1b[36m";
    const char green[] = "\x1b[32m";
    const char reset[] = "\x1b[0m";
    const char bold[] = "\x1b[1m";

    template<class T>
    auto debug(const T& x) -> decltype(cerr << x, 0) {
        return cerr << green << x << reset, 0; 
    }

    int debug(const string& x) {
        return cerr << yellow << '"' << x << '"' << reset, 0;
    }

    template<size_t i, class T>
    int debug_tuple(const T& x) {
        constexpr size_t n = tuple_size<T>::value;
        if (i == 0) {
            cerr << '(';
        }
        debug(get<i>(x));
        if constexpr (i == n - 1) {
            cerr << ')';
        } else {
            cerr << ", ";
            debug_tuple<i+1>(x);
        }
        return 0;
    }

    template<class T>
    auto debug(const T& x) -> decltype(debug(get<0>(x))) {
        return debug_tuple<0>(x);
    }

    template<class T>
    auto debug(const T& x) -> decltype(debug(*x.begin())) {
        cerr << '{';
        auto it = x.begin();
        while (1) {
            if (it == x.end()) {
                cerr << '}';
                return 0;
            } else {
                debug(*it);
                if (next(it) != x.end()) {
                    cerr << ", ";
                }
                ++it;
            }
        }
    }

    template<class T>
    void debug(int l, const T& x, const char* n) {
        cerr << magenta << "Line " << l << ": " << blue << bold << n << reset << " = ";
        debug(x);
        cerr << '\n';
    }
}

#ifdef LOCAL
    #define dbg(x) (debug::debug(__LINE__, x, #x))
#else
    #define dbg(x)
#endif


const int inf = 1123123123;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        for (auto& s : a) cin >> s;

        int q[4] = {-inf, -inf, -inf, -inf};

        for (int i : ra(0, n)) {
            for (int j : ra(0, m)) {
                for (int dx : {-1, 1}) {
                    for (int dy : {-1, 1}) {
                        int w = i*dx + j*dy;
                        int g = (dx+1) + (dy+1)/2;
                        if (a[i][j] == 'B') {
                            q[g] = max(q[g], w);
                        }
                    }
                }
            }
        }
        
        int sol = inf, sx=-1, sy=-1;
        for (int i : ra(0, n)) {
            for (int j : ra(0, m)) {
                int z = -inf;
                for (int dx : {-1, 1}) {
                    for (int dy : {-1, 1}) {
                        int w = i*dx + j*dy;
                        int g = (dx+1) + (dy+1)/2;
                        int d = q[g] - w;
                        z = max(d, z);
                    }
                }

                if (z < sol) {
                    sol = z;
                    sx = i;
                    sy = j;
                }
            }
        }

        cout << sx+1 << ' ' << sy+1 << '\n';
    }
}