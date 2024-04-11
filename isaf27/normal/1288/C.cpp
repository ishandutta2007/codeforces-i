//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define prev _prev
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
const int dig = 10;
const int two = 2;
const int th = 3;
const ll prost = 239;
const ll btc = 30;
const ld eps = 1e-10;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = 1e9 + 7; //(int)(1e9 + 7); //998244353;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(1e3 + 239);
const int L = 20;
const int T = (1 << 20);
const int B = 500;
const int X = 12;

int dp[X][N], n, m;

int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        dp[1][i] = 1;
    for (int i = 2; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = 0;
            for (int l = 1; l <= j; l++)
            {
                dp[i][j] += 1LL * (j - l + 1) * dp[i - 1][l] % MOD;
                if (dp[i][j] >= MOD)
                    dp[i][j] -= MOD;
            }
        }
    int ans = 0;
    for (int l = 1; l <= n; l++)
    {
        ans += 1LL * dp[m][l] * (n - l + 1) % MOD;
        if (ans >= MOD)
            ans -= MOD;
    }
    cout << ans;
    return 0;
}