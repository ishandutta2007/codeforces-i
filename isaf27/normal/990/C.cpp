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
#define str_to_int(stroka) atoi(stroka.c_str())
#define str_to_ll(stroka) atoll(stroka.c_str())
#define str_to_double(stroka) atof(stroka.c_str())
#define what_is(x) cerr << #x << " is " << x << endl
#define solve_system int number; cin >> number; for (int i = 0; i < number; i++) solve()
#define solve_system_scanf int number; scanf("%d", &number); forn(i, 0, number) solve()

//permanent constants
const ld pi = 3.141592653589793238462643383279;
const ld log23 = 1.58496250072115618145373894394781;
const ld eps = 1e-11;
const ll INF = 1e18 + 239;
const ll prost = 239;
const int two = 2;
const int th = 3;
const ll MOD = 1e9 + 7;
const ll MOD2 = MOD * MOD;
const int BIG = 2 * 1e9 + 239;
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

//easy functions
template< typename T >
inline T gcd(T a, T b) { return a ? gcd(b % a, a) : b; }
template< typename T >
inline T lcm(T a, T b) { return (a / gcd(a, b)) * b; }
inline bool is_down(char x) { return ('a' <= x && x <= 'z'); }
inline bool is_upper(char x) { return ('A' <= x && x <= 'Z'); }
inline bool is_digit(char x) { return ('0' <= x && x <= '9'); }
ll power(ll a, int k)
{
    ll ans = 1;
    while (k)
    {
        if (k & 1) ans = (ans * a) % MOD;
        ans = (ans * ans) % MOD;
        k >>= 1;
    }
    return ans;
}

//random
mt19937 rnd(239);

//constants
const int M = 3 * 1e5 + 239;
const int N = 2 * 1e3 + 239;
const int L = 20;
const int T = (1 << 20);
const int B = trunc(sqrt(M)) + 1;
const int X = 1e6 + 239;

string s[M];
int n;
ll kol[two][M];

void init(int c)
{
    for (int i = 0; i < n; i++)
    {
        int b = 0;
        bool ch = true;
        for (int x = 0; x < s[i].size(); x++)
        {
            if (s[i][x] == '(') b++;
            else b--;
            if (b < 0)
            {
                ch = false;
                break;
            }
        }
        if (ch)
            kol[c][b]++;
    }
}

int main()
{
    #ifdef ONPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    fastIO;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    memset(kol, 0, sizeof(kol));
    init(0);
    for (int i = 0; i < n; i++)
        reverse(s[i].begin(), s[i].end());
    for (int i = 0; i < n; i++)
    {
        for (int x = 0; x < s[i].size(); x++)
        {
            if (s[i][x] == '(')
                s[i][x] = ')';
            else
                s[i][x] = '(';
        }
    }
    init(1);
    ll ans = 0;
    for (int i = 0; i < M; i++)
        ans += kol[0][i] * kol[1][i];
    cout << ans;
    return 0;
}