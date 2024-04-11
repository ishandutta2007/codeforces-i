#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
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
#define pre pre1234
#define re return
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef double ld;
typedef pair<ll, ll> lpii;
const ll INF = 1e18 + 1;
const int MAX = 200001;
const ll MOD = 1000000007;
struct trio{
    int first;
    int second;
    int third;
};
struct long_trio{
    ll first;
    ll second;
    ll third;
};
double dist_point_line(double x1, double y1, double x2, double y2, double x3, double y3)
{
    double distance = abs((y3 - y1) * x2 - (x3 - x1) * y2 + x3 * y1 - x1 * y3) / (2 * sqrt(sqr(x3 - x1) + sqr(y3 - y1)));
    return distance;
}
double dist(double x1, double y1, double x2, double y2)
{
    double distance = sqrt(sqr(x1 - x2) + sqr(y1 - y2));
    return distance;
}
double triangle_s(double x1, double y1, double x2, double y2, double x3, double y3)
{
    double a1 = dist(x1, y1, x2, y2);
    double a2 = dist(x1, y1, x3, y3);
    double a3 = dist(x3, y3, x2, y2);
    //cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << endl;
    //(author:IgorI)cout << a1 << " " << a2 << " " << a3 << endl;
    return sqrt((a1 + a2 + a3) / 2 * (a1 + a2 - a3) / 2 * (a1 - a2 + a3) / 2 * (-a1 + a2 + a3) / 2); 
}
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
    if (abs(q) == INF)
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
ll dsumm(ll x)
{
    ll y = 1;
    ll z = 0;
    for (int i = 0; i < 18; i++)
    {
        z += x / y % 10;
        y *= 10;
    }
    return z;
}
ll dsumm2(ll x)
{
    ll y = 1;
    ll z = 0;
    for (int i = 0; i < 60; i++)
    {
        z += x / y % 2;
        y *= 2;
    }
    return z;
}
//hero_start_here
void check_(vi checked)
{
    return;
}
void perms(vi perm, vi used, int n, int k)
{
    if (k == 0)
    {
        check_(perm);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (used[i] == 0)
        {
            used[i] = 1;
            perm.push_back(i);
            perms(perm, used, n, k - 1);
            perm.pop_back();
            used[i] = 0;
        }
    }
    return;
}
void bins(vi bin, int k)
{
    if (k == 0)
    {
        check_(bin);
        return;
    }
    bin.pb(0);
    bins(bin, k - 1);
    bin.pop_back();

    bin.pb(1);
    bins(bin, k - 1);
    bin.pop_back();

    return;
}
string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
ll fact[13] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362280, 3622800, 39916800, 479001600};
int cx[6] = {1, -1, 0, 0, 0, 0};
int cy[6] = {0, 0, 1, -1, 0, 0};
int cz[6] = {0, 0, 0, 0, 1, -1};
//___________BAZE_________________
ll n, a, b;
ll x[200000];
int e[200000];
map<ll, int> mm;
map<ll, int> pos;
//possible - ans/-1
//correct - in array

int main()
{
    cin >> n;
    forn(i, n)
    {
        cin >> x[i];
        mm[x[i]]++;
        while (mm[x[i]] > 1)
        {
            mm[x[i]]-=2;
            mm[2 * x[i]]++;
            e[pos[x[i]]] = 1;
            a++;
            x[i] = 2 * x[i];
        }
        pos[x[i]] = i;
    }
    cout << n - a << endl;
    forn(i, n)
    {
        if (e[i] == 0)
        {
            cout << x[i] << " ";
        }
    }
}