//#pragma GCC optimize("O3")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define y0 _y0
#define kill _kill

//permanent constants
const ld pi = acosl(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int alf = 26;
const ld eps = 1e-8;
const ll INF = (ll)(2e18) + 239;
const int BIG = (int)(1e9) + 239;
const int MOD = 998'244'353; // 1'000'000'007  998'244'353
const ll MOD2 = (ll)MOD * (ll)MOD;

namespace math {
    int sum(int a, int b) {
        a += b - MOD;
        a += (a >> 31) & MOD;
        return a;
    }

    int sub(int a, int b) {
        a -= b;
        a += (a >> 31) & MOD;
        return a;
    }

    int mul(int a, int b) {
        return 1LL * a * b % MOD;
    }

    int power(int a, int k) {
        int ans = 1;
        int pw = a;
        while (k) {
            if (k & 1) {
                ans = mul(ans, pw);
            }
            pw = mul(pw, pw);
            k >>= 1;
        }
        return ans;
    }

    int inv(int a) {
        return power(a, MOD - 2);
    }
}

//random
#ifdef ONPC
mt19937_64 rnd(239);
#else
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 10);
const int L = 21;
const int T = (1 << 19) + 239;
const int B = 500;
const int X = 110;

int fact[M], inv[M];

int getC(int n, int k) {
    if (n < k || k < 0) {
        return 0;
    }
    return math::mul(fact[n], math::mul(inv[k], inv[n - k]));
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll s = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] *= 2;
        s += a[i];
    }
    if (s == 0) {
        cout << math::power(2, n - 1) << "\n";
        return;
    }
    map<ll, int> cnt1, cnt2;
    ll p = 0;
    for (int i = 0; i < n; i++) {
        p += a[i];
        if (p > (s / 2)) {
            break;
        }
        cnt1[p]++;
    }
    p = 0;
    for (int i = n - 1; i >= 0; i--) {
        p += a[i];
        if (p > (s / 2)) {
            break;
        }
        cnt2[p]++;
    }
    int ans = math::power(2, cnt1[s / 2]);
    for (const auto& t : cnt1) {
        if (t.first == (s / 2)) {
            continue;
        }
        int A = t.second;
        int B = cnt2[t.first];
        if (A > 0 && B > 0) {
            int cur = 0;
            for (int k = 0; k <= min(A, B); k++) {
                cur = math::sum(cur, math::mul(getC(A, k), getC(B, k)));
            }
            ans = math::mul(ans, cur);
        }
    }
    cout << ans << "\n";
}

int32_t main() {
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    fact[0] = 1;
    for (int i = 1; i < M; i++) {
        fact[i] = math::mul(fact[i - 1], i);
    }
    inv[M - 1] = math::power(fact[M - 1], MOD - 2);
    for (int i = M - 2; i >= 0; i--) {
        inv[i] = math::mul(inv[i + 1], i + 1);
    }

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}