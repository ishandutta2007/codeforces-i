/*
    Author: isaf27 (Ivan Safonov)
*/

//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0)
#define nul point(0, 0)
#define what_is(x) cerr << #x << " is " << x << endl
#define solve_system int number; cin >> number; for (int i = 0; i < number; i++) solve()
#define solve_system_scanf int number; scanf("%d", &number); for (int i = 0; i < number; i++) solve()

//permanent constants
const ld pi = acos(-1.0);
const ld log23 = 1.58496250072115618145373894394781;
const ld eps = 1e-8;
const ll INF = 1e18 + 239;
const ll prost = 239;
const int two = 2;
const int th = 3;
const ll MOD = 1e9 + 7;
const ll MOD2 = MOD * MOD;
const int BIG = 1e9 + 239;
const int alf = 26;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int dig = 10;
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int bt = 31;

//easy functions
template< typename T >
inline T gcd(T a, T b)
{
    while (a)
    {
        b %= a;
        swap(a, b);
    }
    return b;
}
template< typename T >
inline T lcm(T a, T b) { return (a / gcd(a, b)) * b; }
inline bool is_down(char x) { return ('a' <= x && x <= 'z'); }
inline bool is_upper(char x) { return ('A' <= x && x <= 'Z'); }
inline bool is_digit(char x) { return ('0' <= x && x <= '9'); }
inline ll power(ll a, int b)
{
    if (b == 0) return 1;
    ll t = power(a, b >> 1);
    t = (t * t) % MOD;
    if (b & 1) t = (t * a) % MOD;
    return t;
}

//random
mt19937 rnd(239);

//constants
const int M = 2 * 1e5 + 239;
const int N = 2 * 1e3 + 239;
const int L = 20;
const int T = (1 << 18);
const int B = trunc(sqrt(M)) + 1;
const int X = 2e6 + 1e4;

int n, m, a[N], b[N], c, x, nx, p, was, ck;
pair<int, int> ar[X];
pair<int, int> tr[N];
int mx[N];

int main()
{
    #ifdef ONPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    fastIO;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    cin >> x;
    c = 0;
    for (int i = 0; i < m; i++)
    {
        int s = 0;
        for (int j = i; j < m; j++)
        {
            s += b[j];
            ar[c++] = make_pair(s, j - i + 1);
        }
    }
    sort(ar, ar + c);
    ck = 0;
    was = 0;
    for (int i = 0; i < c; i++)
        if (was < ar[i].second)
        {
            tr[ck++] = ar[i];
            was = ar[i].second;
        }
    c = ck;
    mx[0] = 0;
    for (int i = 0; i < c; i++)
        mx[i + 1] = max(mx[i], tr[i].second);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int s = 0;
        for (int j = i; j < n; j++)
        {
            s += a[j];
            nx = (x / s);
            p = lower_bound(tr, tr + c, make_pair(nx + 1, 0)) - tr;
            ans = max(ans, (j - i + 1) * mx[p]);
        }
    }
    cout << ans;
    return 0;
}