// Code it, hate me?
// .................
// WA 138 or TL 109?
// Hope, Accepted...

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
#include <stdio.h>
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
#define pre pre1234
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef double ld;
typedef pair<ll, ll> lpii;
const int INF = 1e9;
const ll INFLL = 1e18 + 1;
const int MAX = 200001;
const ll MOD = 1000000007;
ll inq(ll k, ll q)
{
    if (q == 0)
        return 1;
    ll l = inq(k, q / 2);
    if (q % 2 == 0)
        return l * l % MOD;
    else
        return l * l * k % MOD;
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
    if (x == 0)
        return 0;
    return lg10(x / 10) + 1;
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

#define cnks(l) for (int i = 0; i < l; i++) cnk[i][0] = 1; for (int i = 0; i < l; i++) cnk[0][i] = 1; for (int i = 0; i < l; i++) for (int j = 1; j < i; j++) cnk[i][j] = cnk[i - 1][j] + cnk[i - 1][j - 1];
#define facts(l) fact[0] = 1; for (int i = 1; i < l; i++) fact[i] = fact[i - 1] * i;
#define stirling_2s(l) stirling_2[0][0] = 1; for (int i = 1; i < l; i++) stirling_2[i][0] = 0; for (int i = 0; i < l; i++) for (int j = 1; j <= i; j++) stirling_2[i][j] = stirling_2[i - 1][j - 1] + j * stirling_2[i - 1][j];

string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vi cx, cy;
//______________________
ll n, q, non_zero, is_zero = -1, is_q = -1;
ll a[500000];
vector<ll> b[500000];
ll c[500000];
ll frst[500000];
ll last[500000];

int main()
{
    fill(frst, frst + 500000, INF);
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > 0)
            non_zero = 1;
        if (a[i] == 0)
            is_zero = i;
        frst[a[i]] = min(frst[a[i]], i);
        last[a[i]] = max(last[a[i]], i);
    }
    if (non_zero == 0)
    {
        cout << "YES\n";
        for (int i = 0; i < n; i++)
        {
            printf("%lld ", q);
        }
        return 0;
    }
    for (int i = 1; i <= q; i++)
    {
        ll start = frst[i];
        ll end1 = last[i];
        if (start == INF)
        {
            continue;
        }
        else
        {
            b[start].pb(i);
            b[end1].pb(-i);
        }
    }
    set<int> num;
    for (int i = 0; i < n; i++)
    {
        //cout << i << endl << endl;
        for (int j = 0; j < b[i].sz; j++)
        {
            if (b[i][j] > 0)
            {
                num.incert(b[i][j]);
            }
        }
        if (num.sz == 0)
        continue;
        auto it = num.end();
        it--;
        ll kk = *it;
        c[i] = kk;
        for (int j = b[i].sz - 1; j >= 0; j--)
        {
            if (b[i][j] < 0)
            {
                if (num.sz == 0)
                {
                    r_NO;
                }
                if (num.find(-b[i][j]) == num.end())
                {
                    r_NO;
                }
                else
                {
                    num.erace(-b[i][j]);
                }
            }
        }
    }
    int lst = 0;
    for (int i = 0; i < n; i++)
    {
        if (c[i] == 0)
        {
            c[i] = lst;
        }
        else
        {
            lst = c[i];
        }
    }
    lst = 0;
    for (int i = n; i >= 0; i--)
    {
        if (c[i] == 0)
        {
            c[i] = lst;
        }
        else
        {
            lst = c[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] != c[i] && a[i] != 0)
        {
            r_NO;
        }
        if (c[i] == q)
        {
            is_q = i;
        }
    }
    if (is_q == -1 && is_zero == -1)
    {
        r_NO;
    }
    if (is_q == -1 && is_zero != -1)
    {
        c[is_zero] = q;
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++)
    {
        printf("%lld ", c[i]);
    }
}