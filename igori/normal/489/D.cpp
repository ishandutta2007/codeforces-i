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
        return (l * l) % MOD * k % MOD;
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
//______________________
ll n, m;
vector<int> graph[4000], graph2[4000];
ll ans;
ll d[5000];
ll f[4000];
ll ff[4000];

int main()
{
    cin >> n >> m;
    forn(i, m)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        graph[x].pb(y);
        graph2[y].pb(x);
    }
    ll it = 2;
    for (int b = 0; b < n; b++)
    {
        for (int c = b + 1; c < n; c++)
        {
            ll x = 0;
            ll y = 0;
            ll z = 0;
            for (int i = 0; i < graph[b].sz; i++)
            {
                d[graph[b][i]] = it;
            }
            for (int i = 0; i < graph[c].sz; i++)
            {
                if (d[graph[c][i]] == it)
                {
                    x++;
                }
            }
            it++;
            for (int i = 0; i < graph2[b].sz; i++)
            {
                d[graph2[b][i]] = it;
            }
            for (int i = 0; i < graph2[c].sz; i++)
            {
                if (d[graph2[c][i]] == it)
                {
                    y++;
                }
            }
            it++;
            for (int i = 0; i < graph[b].sz; i++)
            {
                ff[graph[b][i]] = it * 7;
            }
            for (int i = 0; i < graph[c].sz; i++)
            {
                if (ff[graph[c][i]] == it * 7)
                    ff[graph[c][i]]++;
                else
                    ff[graph[c][i]] = 0;
            }
            for (int i = 0; i < graph2[b].sz; i++)
            {
                if (ff[graph2[b][i]] == it * 7 + 1)
                    ff[graph2[b][i]]++;
                else
                    ff[graph2[b][i]] = 0;
            }
            for (int i = 0; i < graph2[c].sz; i++)
            {
                if (ff[graph2[c][i]] == it * 7 + 2)
                {
                    //cout << graph2[c][i] << " ";
                    z++;
                    ff[graph2[c][i]] = 0;
                }
            }
            //cout << endl;
            //cout << b << " " << c << " " << x << " " << y << " " << z << endl;
            ans += (x - z) * (y - z) + z * (z - 1) + z * (x - z) + z * (y - z);
        }
    }
    cout << ans;
}