#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <vector>
#include <queue>
#include <bitset>
#include <cmath>
#include <time.h>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stdlib.h>
#include <deque>
#include <iomanip>
#include <complex>
//#include <ext/rope>

using namespace std;
//using namespace __gnu_cxx;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define fast_read cin.sync_with_stdio(0)
#define PREX(number) cout << fixed << setprecision(number)
#define nul point(0, 0)
#define all(v) v.begin(), v.end()
#define random srand(time(NULL))
#define rand_int ((rand() << 15) | rand())
#define do_zero(massiv) memset(massiv, 0, sizeof(massiv))
#define forn(i, l, r) for (int i = l; i < r; i++)
#define str_to_int(stroka) atoi(stroka.c_str())
#define str_to_ll(stroka) atoll(stroka.c_str())
#define str_to_double(stroka) atof(stroka.c_str())
#define read_int(number) scanf("%d", &number)
#define what_is(x) cerr << #x << " is " << x << endl
#define solve_system int number; cin >> number; forn(i, 0, number) solve()
#define ones(v) v.resize(unique(all(v)) - v.begin())

//easy functions
ll gcd_ll(ll a, ll b) { return a ? gcd_ll(b % a, a) : b; }
ll lcm_ll(ll a, ll b) { return (a / gcd_ll(a, b)) * b; }
int gcd(int a, int b) { return a ? gcd(b % a, a) : b; }
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }
string int_to_str_easy(ll n) { return n ? "" : int_to_str_easy(n / 10) + (char)('0' + n % 10); }
ll sum(vector<ll> v) {ll ans = 0; for (ll i : v) ans += i; return ans; }
bool is_down(char x) { return ('a' <= x && x <= 'z'); }
bool is_upper(char x) { return ('A' <= x && x <= 'Z'); }
bool is_digit(char x) { return ('0' <= x && x <= '9'); }
string follow(string s) { for (int i = 0; i < s.length(); i++) if (is_upper(s[i])) s[i] += 'a' - 'A'; return s; }

//constants
const ld pi = 3.141592653589793238462643383279;
const ld log23 = 1.58496250072115618145373894394781;
const ld eps = 1e-8;
const ld zero = 0;
const ll INF = 1e18;
const int COUT = 30;
const int prost = 239;
const ll prost64 = 239;
const ll MOD = 1000000007;
const int BIG = 1e9;
const int alf = 26;
const int MAX_N = 1e5 + 1;
const int MAX_M = 501;
const int km = (1 << 18) - 1;
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

// Code starts here

void solve()
{
    return;
}

ll number(ll x)
{
    ll d = 1 + 8 * x;
    if (sqrt(d) != trunc(sqrt(d)))
        return -1;
    d = trunc(sqrt(d));
    return (1 + d) / 2;
}

void fail()
{
    cout << "Impossible";
    exit(0);
}

void go(string s)
{
    cout << s;
    exit(0);
}

int main()
{   //*
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif /**/
    fast_read;
    //solve_system;
    ll a00, a01, a10, a11;
    cin >> a00 >> a01 >> a10 >> a11;
    if (a00 == 0 && a01 == 0 && a10 == 0 && a11 == 0)
        go("0");
    if (a00 == 0 && a11 == 0)
    {
        if (a10 != 0 && a01 != 0)
            fail();
        if (a01 > 1)
            fail();
        if (a10 > 1)
            fail();
        if (a01 == 1)
            go("01");
        else
            go("10");
    }
    if (a01 == 0 && a10 == 0)
    {
        if (a11 != 0 && a00 != 0)
            fail();
        if (number(a00) == -1)
            fail();
        if (number(a11) == -1)
            fail();
        if (a00 == 0)
        {
            ll kol = number(a11);
            for (int i = 0; i < kol; i++)
                cout << 1;
            return 0;
        }
        else
        {
            ll kol = number(a00);
            for (int i = 0; i < kol; i++)
                cout << 0;
            return 0;
        }
    }
    if (a00 == 0)
    {
        ll kol = a01 + a10;
        if (a11 != (kol * (kol - 1)) / 2)
            fail();
        for (int i = 0; i < a10; i++)
            cout << 1;
        cout << 0;
        for (int i = 0; i < a01; i++)
            cout << 1;
        return 0;
    }
    if (a11 == 0)
    {
        ll kol = a01 + a10;
        if (a00 != (kol * (kol - 1)) / 2)
            fail();
        for (int i = 0; i < a01; i++)
            cout << 0;
        cout << 1;
        for (int i = 0; i < a10; i++)
            cout << 0;
        return 0;
    }
    ll k0 = number(a00);
    ll k1 = number(a11);
    if (a01 == 0)
    {
        if (a10 != k1 * k0)
            fail();
        for (int i = 0; i < k1; i++)
            cout << 1;
        for (int i = 0; i < k0; i++)
            cout << 0;
        return 0;
    }
    if (a10 == 0)
    {
        if (a01 != k1 * k0)
            fail();
        for (int i = 0; i < k0; i++)
            cout << 0;
        for (int i = 0; i < k1; i++)
            cout << 1;
        return 0;
    }
    ll n = k0 + k1;
    if (a01 + a10 + a00 + a11 != (n * (n - 1)) / 2)
        fail();
    if (a01 + a10 != k0 * k1)
        fail();
    string s;
 /*   for (int i = 0; i < k0; i++)
        s += '0';
    for (int i = 0; i < k1; i++)
        s += '1';
    while (true)
    {
        for (int i = 0; i < n; i++)
    }*/
    while (k0 + k1)
    {
        if (a01 >= k1)
        {
            cout << 0;
            a01 -= k1;
            k0--;
        }
        else
        {
            cout << 1;
            a10 -= k0;
            k1--;
        }
    }
    return 0;
}