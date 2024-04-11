/*
    Author: isaf27 (Ivan Safonov)
*/

#pragma GCC optimize("O3")
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
const ld eps = 1e-8;
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
    if (k == 0) return 1;
    ll t = power(a, k >> 1);
    t = (t * t) % MOD;
    if (k & 1) t = (t * a) % MOD;
    return t;
}

//random
mt19937 rnd(239);

//constants
const int M = 1e6 + 239;
const int N = 2 * 1e3 + 239;
const int L = 20;
const int T = (1 << 20);
const int B = trunc(sqrt(M)) + 1;
const int X = 20;

int n, m;
pair<int, int> a[X], b[X];

int gett(pair<int, int> x, pair<int, int> y)
{
    int ans = 0;
    ans += (x.first == y.first);
    ans += (x.second == y.first);
    ans += (x.first == y.second);
    ans += (x.second == y.second);
    return ans;
}

int fnd(pair<int, int> x, pair<int, int> y)
{
    if (x.first == y.first) return x.first;
    if (x.second == y.first) return x.second;
    if (x.first == y.second) return x.first;
    if (x.second == y.second) return x.second;
}

int main()
{
    #ifdef ONPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    fastIO;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int s, f;
        cin >> s >> f;
        if (s > f) swap(s, f);
        a[i] = make_pair(s, f);
    }
    for (int i = 0; i < m; i++)
    {
        int s, f;
        cin >> s >> f;
        if (s > f) swap(s, f);
        b[i] = make_pair(s, f);
    }
    set<int> q;
    for (int x = 0; x < n; x++)
        for (int y = 0; y < m; y++)
        {
            if (gett(a[x], b[y]) != 1) continue;
            q.insert(fnd(a[x], b[y]));
        }
    if (q.size() == 1)
    {
        cout << (*q.begin());
        return 0;
    }
    vector<pair<int, int> > pos;
    for (int x = 0; x < n; x++)
        for (int y = 0; y < m; y++)
        {
            if (gett(a[x], b[y]) != 1) continue;
            pos.push_back(a[x]);
        }
    for (pair<int, int> t : pos)
    {
        set<int> q;
        for (int j = 0; j < m; j++)
        {
            if (gett(t, b[j]) != 1) continue;
            q.insert(fnd(t, b[j]));
        }
        if (q.size() > 1)
        {
            cout << "-1";
            return 0;
        }
    }
    pos.clear();
    for (int x = 0; x < n; x++)
        for (int y = 0; y < m; y++)
        {
            if (gett(a[x], b[y]) != 1) continue;
            pos.push_back(b[y]);
        }
    for (pair<int, int> t : pos)
    {
        set<int> q;
        for (int j = 0; j < n; j++)
        {
            if (gett(t, a[j]) != 1) continue;
            q.insert(fnd(t, a[j]));
        }
        if (q.size() > 1)
        {
            cout << "-1";
            return 0;
        }
    }
    cout << "0";
    return 0;
}