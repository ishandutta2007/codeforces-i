#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

#ifdef imeimi
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
typedef long long llong;
typedef long double lf;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<lf, lf> pff;

int n, x;
int deg[1001];
bool solve() {
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) deg[i] = 0;
    for (int i = 2; i < n + n; ++i) {
        int a;
        cin >> a;
        ++deg[a];
    }
    if (deg[x] <= 1) return 1;
    return n + 1 & 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) printf(solve() ? "Ayush\n" : "Ashish\n");
    return 0;
}