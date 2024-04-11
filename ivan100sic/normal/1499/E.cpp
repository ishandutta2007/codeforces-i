// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

template<int m>
struct modint {
    unsigned x;

    modint() : x(0) {}
    modint(long long arg) : x((arg %= m) < 0 ? arg + m : arg) {}

    modint operator+ (const modint& b) const {
        auto t = *this; t.x = (t.x += b.x) >= m ? t.x-m : t.x; return t;
    }

    modint operator- (const modint& b) const {
        auto t = *this; t.x = (t.x += m-b.x) >= m ? t.x-m : t.x; return t;
    }

    modint operator* (const modint& b) const {
        auto t = *this; t.x = ll(t.x) * b.x % m; return t;
    }

    modint operator/ (const modint& b) const {
        return *this * b.inv();
    }

    template<class T> modint operator^ (T n) const {
        modint t;
        if (n == 0) return t.x = 1, t;
        if (n == 1) return t.x = x, t;
        t = *this ^ (n >> 1); t *= t;
        return n & 1 ? *this * t : t;
    }

    modint& operator+= (const modint& b) { return *this = *this + b; }
    modint& operator-= (const modint& b) { return *this = *this - b; }
    modint& operator*= (const modint& b) { return *this = *this * b; }
    modint& operator/= (const modint& b) { return *this = *this / b; }
    modint& operator++ () { if (++x == m) x = 0; return *this; }
    modint& operator-- () { if (x-- == 0) x = m-1; return *this; }
    modint operator++ (int) { modint tmp = *this; ++*this; return tmp; }
    modint operator-- (int) { modint tmp = *this; --*this; return tmp; }
    bool operator== (const modint& other) const { return x == other.x; }
    bool operator!= (const modint& other) const {	return x != other.x; }
    int operator() () const { return x; }
    template<class T> modint operator^= (T n) { return *this = *this ^ n; }
    modint inv() const { return *this ^ (m-2); }
};

const int mod = 998'244'353;
typedef modint<mod> mint;

string x, y;
mint dp[1005][1005][2];
int n, m;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> x >> y;
    n = x.size();
    m = y.size();

    mint sol = 0;
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=m; j++) {
            for (int f : {0, 1}) {
                if ((f ? i : j) == 0) continue;
                dp[i][j][f] += 1;
                sol += dp[i][j][f];
                char c = f ? x[i-1] : y[j-1];

                if (i < n && x[i] != c) {
                    dp[i+1][j][1] += dp[i][j][f];
                }

                if (j < m && y[j] != c) {
                    dp[i][j+1][0] += dp[i][j][f];
                }
            }
        }
    }

    for (int i=0; i<n; i++) {
        sol -= m + 1;
        for (int r=i+1; r<n; r++) {
            if (x[r] == x[r-1]) break;
            sol -= m + 1;
        }
    }

    for (int j=0; j<m; j++) {
        sol -= n + 1;
        for (int r=j+1; r<m; r++) {
            if (y[r] == y[r-1]) break;
            sol -= n + 1;
        }
    }

    cout << sol() << '\n';
}