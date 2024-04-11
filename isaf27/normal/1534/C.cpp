/*
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
*/

#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define y0 _y0
#define kill _kill

//permanent constants
const ld pi = acos(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int alf = 26;
const ld eps = 1e-10;
const ll INF = (ll)(4e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = 1e9 + 7;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
#ifdef ONPC
mt19937_64 rnd(239);
#else
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

//constants
const int M = (int)(4e5 + 239);
const int N = (int)(2e3 + 10);
const int L = 21;
const int T = (1 << 18) + 239;
const int B = 510;
const int X = 55;

int par[M];
int rg[M];
int cnt;

void init(int n) {
    for (int i = 0; i < n; i++) {
        par[i] = i;
        rg[i] = 0;
    }
    cnt = n;
}

int find_set(int i) {
    if (i == par[i]) {
        return i;
    }
    return (par[i] = find_set(par[i]));
}

void merge(int i, int j) {
    i = find_set(i);
    j = find_set(j);
    if (i == j) {
        return;
    }
    if (rg[i] > rg[j]) {
        swap(i, j);
    }
    par[i] = j;
    if (rg[i] == rg[j]) {
        rg[j]++;
    }
    cnt--;
}

int n, a[M], b[M];

void solve() {
    cin >> n;
    init(n);
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        p--;
        a[p] = i;
    }
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        p--;
        b[p] = i;
    }
    for (int i = 0; i < n; i++) {
        merge(a[i], b[i]);
    }
    int ans = 1;
    for (int i = 0; i < cnt; i++) {
        ans = (ans + ans) % MOD;
    }
    cout << ans << "\n";
}

int32_t main() {
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}