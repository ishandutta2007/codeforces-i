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
const ll MOD = 1e9 + 7; //998244353;
const ll MOD2 = MOD * MOD;
const int BIG = 1e9 + 239;
const int alf = 26;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxb[4] = {-1, 1, 1, -1};
const int dyb[4] = {-1, 1, -1, 1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int dig = 10;
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const ll bt = 30;

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

//random
//mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rnd(239);

//constants
const int M = 2e5 + 239;
const int N = (2 * M);
const int L = 18;
const int T = (1 << 20);
const int B = trunc(sqrt(M)) + 1;
const int X = 110;

int n, m;
ll a[M], dist[M], mn;
vector<pair<int, ll> > v[M];
set<pair<ll, int> > q, qa;

void add(int p)
{
    q.erase(make_pair(dist[p], p));
    qa.erase(make_pair(a[p], p));
    mn = min(mn, a[p]);
    dist[p] = 0;
    for (pair<int, ll> t : v[p])
    {
        int to = t.first;
        if (dist[to] == 0) continue;
        if (dist[to] > t.second)
        {
            q.erase(make_pair(dist[to], to));
            dist[to] = t.second;
            q.insert(make_pair(dist[to], to));
        }
    }
}

int main()
{
    #ifdef ONPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
    {
        int s, f;
        ll w;
        cin >> s >> f >> w;
        s--, f--;
        v[s].push_back(make_pair(f, w));
        v[f].push_back(make_pair(s, w));
    }
    mn = INF;
    for (int i = 0; i < n; i++)
    {
        q.insert(make_pair(INF, i));
        qa.insert(make_pair(a[i], i));
        dist[i] = INF;
    }
    add(0);
    ll ans = 0;
    for (int i = 1; i < n; i++)
    {
        int t = q.begin()->second;
        ll dl = q.begin()->first;
        if (dl > mn + qa.begin()->first)
            t = qa.begin()->second, dl = mn + qa.begin()->first;
        add(t);
        ans += dl;
    }
    cout << ans;
    return 0;
}