//Updated 29.09.18
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
#include <stdio.h>
#include <time.h>
#include <iomanip>
#include <bitset>
using namespace std;
#define sqr(z) (z) * (z)
#define ch_NO(x) cout << "NO\n"; x = 1 - x;
#define b_NO cout << "NO\n"; break;
#define r_NO cout << "NO\n"; return 0;
#define c_NO cout << "NO\n"; continue;
#define ch_YES(x) cout << "YES\n"; x = 1 - x;
#define b_YES cout << "YES\n"; break;
#define r_YES cout << "YES\n"; return 0;
#define c_YES cout << "YES\n"; continue;
#define sz size()
#define pb push_back
#define int_ "%d",
#define fi first
#define se second
#define mm(k) memset((k), -1, sizeof(k));
#define all(k) (k).begin(), (k).end()
#define forn(i, n) for (int (i) = 0; (i) != (n); i++)
#define nfor(i, n) for (int (i) = (n) - 1; (i) != -1; i--)
#define do_nothing cout << " Work_Error ";
#define erace erase
#define incert insert
#define reverce reverse
#define re return
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef double ld;
typedef pair<ll, ll> lpii;
typedef unsigned long long ull;
const int INF = 1e9;
const ll INFLL = 1e18 + 1;
const int MAX = 200001;
const ll MOD = 1000000007;
const int SZ = 300100;
const double PI = 3.14159265358979323846264338327;
ll inq(ll k, ll q, ll mod)
{
    if (q == 0)
        return 1;
    ll l = inq(k, q / 2, mod);
    if (q % 2 == 0)
        return l * l % mod;
    else
        return l * l % mod * k % mod;
}
ll gcd(ll a, ll b)
{
    if (a < b)
        swap(a, b);
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll cubr(ll a)
{
    ll l = -1, r = 1e6 + 2;
    while (l < r - 1)
    {
        ll mid = (l + r) / 2;
        if (mid * mid * mid > a)
            r = mid;
        else
            l = mid;
    }
    return l;
}
ll max(ll a, ll b)
{
    if (a > b)
        return a;
    return b;
}
ll min(ll a, ll b)
{
    return -1 * max(-a, -b);
}
ll possible(ll q)
{
    if (q == INF)
        return -1;
    return q;
}
bool correct(int x, int xx)
{
    if (x < 0)
        return 0;
    if (x >= xx)
        return 0;
    return 1;
}
ll dsumm(ll x, ll k)
{
    ll y = 1;
    ll z = 0;
    for (int i = 0; y < 1e18; i++)
    {
        z += x / y % k;
        y *= k;
    }
    return z;
}
ll dcount(ll x)
{
    ll y = 1;
    ll z = 0;
    int c[100];
    for (int i = 0; i < 10; i++)
    c[i] = 0;
    for (int i = 0; x > 0; i++)
    {
        if (c[x / y % 10] == 0)
        z++;
        c[x / y % 10] = 1;
        x /= 10;
    }
    return z;
}
ll lg10(ll x)
{
    if (10000 <= x && x < 100000)
        re 5;
    if (x == 0)
        return 0;
    return lg10(x / 10) + 1;
}
ll g(ll x, ll mod)
{
    if (x == 0)
        re 0;
    return x / mod + g(x / mod, mod);
}
bool is_digit(char c)
{
    re ('0' <= c && c <= '9');
}

#define bitcount __builtin_popcount
#define bitcountl __builtin_popcountll

#define RA(n, arr) cin >> n; forn(i, n) cin >> (arr)[i];
#define WA(n, arr) cout << n << "\n"; forn(i, n) cout << (arr)[i] << " ";
#define WWA(n, arr) forn(i, n) cout << (arr)[i] << " ";
#define RSA(n, arr) cin >> n; forn(i, n) cin >> (arr)[i]; sort(arr, arr + n);
#define WSA(n, arr) cout << n << "\n"; sort(arr, arr + n); forn(i, n) cout << (arr)[i] << " ";
#define WWSA(n, arr) sort(arr, arr + n); forn(i, n) cout << (arr)[i] << " ";
#define WSV(vec) cout << vec.size() << "\n"; sort(all(vec)); forn(i, vec.sz) cout << (vec)[i] << " ";
#define WWSV(vec) sort(all(vec)); forn(i, vec.sz) cout << (vec)[i] << " ";
//string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
//int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//vi cx, cy;
//______________________
#include <deque>
#define endl "\n"
#define int long long

string s;
string t;
ll prefAS[500000];
ll prefAT[500000];
ll suffA1[500000];
ll suffA2[500000];

signed main()
{
    //freopen("in.in", "r", stdin);
    //freopen("out.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> s;
    cin >> t;
    forn(i, s.sz)
    {
        if (s[i] == 'C')
            s[i] = 'B';
        if (i > 0)
            prefAS[i] = prefAS[i - 1];
        prefAS[i] += (s[i] == 'A');
    }
    forn(i, t.sz)
    {
        if (t[i] == 'C')
            t[i] = 'B';
        if (i > 0)
            prefAT[i] = prefAT[i - 1];
        prefAT[i] += (t[i] == 'A');
    }
    ll aa = 0;
    forn(i, s.sz)
    {
    	if (s[i] == 'A')
    	aa++;
    	else
    	aa = 0;
    	suffA1[i] = aa;
    }
    aa = 0;
    forn(i, t.sz)
    {
    	if (t[i] == 'A')
    	aa++;
    	else
    	aa = 0;
    	suffA2[i] = aa;
    }
    ll q;
    cin >> q;
    while (q--)
    {
        ll l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        l1--;
        r1--;
        l2--;
        r2--;
        ll cntA1 = prefAS[r1] - (l1 > 0 ? prefAS[l1 - 1] : 0);
        ll cntA2 = prefAT[r2] - (l2 > 0 ? prefAT[l2 - 1] : 0);
        ll cntB1 = r1 - l1 + 1 - cntA1;
        ll cntB2 = r2 - l2 + 1 - cntA2;
        ll suffA1q = min(suffA1[r1], r1 - l1 + 1);
        ll suffA2q = min(suffA2[r2], r2 - l2 + 1);
        if (suffA1q % 3 != suffA2q % 3 || (suffA1q == r1 - l1 + 1 && suffA2q != r2 - l2 + 1))
        {
        	suffA1q--;
        	cntB1+=2;
        }
        if (cntB1 % 2 != cntB2 % 2 || cntB1 > cntB2 || suffA1q < suffA2q)
        {
            cout << 0;
        }
        else
        {
            cout << 1;
        }
    }
}