/*
    Author: isaf27 (Ivan Safonov)
*/

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0)
#define nul point(0, 0)
#define str_to_int(stroka) atoi(stroka.c_str())
#define str_to_ll(stroka) atoll(stroka.c_str())
#define str_to_double(stroka) atof(stroka.c_str())
#define what_is(x) cerr << #x << " is " << x << endl
#define solve_system int number; cin >> number; for (int i = 0; i < number; i++) solve()
#define solve_system_scanf int number; scanf("%d", &number); for (int i = 0; i < number; i++) solve()

//permanent constants
const ld pi = 3.141592653589793238462643383279;
const ld log23 = 1.58496250072115618145373894394781;
const ld eps = 1e-8;
const ll INF = 1e18 + 239;
const ll prost = 239;
const int two = 2;
const int th = 3;
const ll MOD = 1e9 + 7; // 998244353
const ll MOD2 = MOD * MOD;
const int BIG = 1e9 + 239;
const int alf = 26;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int dig = 10;
const string str_alf = "abcdefghijklmnopqrstuvwxyz";
const string str_alf_big = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int bt = 31;
const int fr = 4;

//easy functions
template< typename T >
inline T gcd(T a, T b) { return a ? gcd(b % a, a) : b; }
template< typename T >
inline T lcm(T a, T b) { return (a / gcd(a, b)) * b; }
inline bool is_down(char x) { return ('a' <= x && x <= 'z'); }
inline bool is_upper(char x) { return ('A' <= x && x <= 'Z'); }
inline bool is_digit(char x) { return ('0' <= x && x <= '9'); }
inline int power(ll a, int b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

//random
mt19937 rnd(239);

//constants
const int M = 2 * 1e5 + 239;
const int N = 3 * 1e3 + 239;
const int L = 19;
const int T = (1 << 20);
const int B = trunc(sqrt(M)) + 1;
const int X = 1e4 + 239;

bool used[N];
int n, m, p[N], pos[N], kol[N], sz[N];
ll c[N];
vector<pair<ll, int> > al;

int main()
{
    #ifdef ONPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    fastIO;
    memset(sz, 0, sizeof(sz));
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i] >> c[i];
        p[i]--;
        sz[p[i]]++;
    }
    for (int i = 0; i < n; i++)
        if (p[i] != 0)
            al.push_back(make_pair(c[i], i));
    sort(al.begin(), al.end());
    for (int i = 0; i < (int)al.size(); i++)
        pos[al[i].second] = i;
    ll ans = INF;
    for (int i = 1; i <= n; i++)
    {
        for (int x = 0; x < m; x++) kol[x] = sz[x];
        for (int x = 0; x < (int)al.size(); x++) used[x] = false;
        ll now = 0;
        int has = sz[0];
        for (int x = 0; x < (int)al.size(); x++)
        {
            int j = al[x].second;
            if (kol[p[j]] >= i)
            {
                used[x] = true;
                kol[p[j]]--;
                has++;
                now += al[x].first;
            }
        }
        for (int x = 0; x < (int)al.size(); x++)
            if (!used[x])
            {
                int j = al[x].second;
                if (has < i)
                {
                    used[x] = true;
                    kol[p[j]]--;
                    has++;
                    now += al[x].first;
                }
            }
        ans = min(ans, now);
    }
    cout << ans;
    return 0;
}