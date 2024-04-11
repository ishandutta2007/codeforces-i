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
#define rand_int (abs((rand() << 15) | rand()))
#define do_zero(massiv) memset(massiv, 0, sizeof(massiv))
#define forn(i, l, r) for (int i = l; i < r; i++)
#define str_to_int(stroka) atoi(stroka.c_str())
#define str_to_ll(stroka) atoll(stroka.c_str())
#define str_to_double(stroka) atof(stroka.c_str())
#define read_int(number) scanf("%d", &number)
#define what_is(x) cerr << #x << " is " << x << endl
#define solve_system int number; cin >> number; forn(i, 0, number) solve()
#define solve_system_scanf int number; scanf("%d", &number); forn(i, 0, number) solve()
#define unique(v) v.resize(unique(all(v)) - v.begin())
#define bits(number) __builtin_popcount(number)

//easy functions
template< typename T >
T gcd(T a, T b) { return a ? gcd(b % a, a) : b; }
template< typename T >
T lcm(T a, T b) { return (a / gcd(a, b)) * b; }
string int_to_str_easy(ll n) { return n ? "" : int_to_str_easy(n / 10) + (char)('0' + n % 10); }
//template< typename T >
//T sum(vector<T> v) {T ans = 0; for (T i : v) ans += i; return ans; }
template< typename T >
bool is_prime_sqrt(T n)
{
    if (n == 1)
        return false;
    T k = trunc(sqrt(n));
    for (T i = 2; i <= k; i++)
        if (n % i == 0)
            return false;
    return true;
}
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
const int two = 2;
const ll sr = 31;
const ll MOD = 1000000007;
const int BIG = 1e9;
const int alf = 26;
const int MAX_N = 601;
const int MAX_T = (1 << 20);
const int BLOCK = trunc(sqrt(MAX_N)) + 1;
const int MAX_LOG = 21;
const int km = (1 << 18);
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int bit_max = 32;
const int dig = 10;
const string str_alf = "abcdefghijklmnopqrstuvwxyz";
const string str_alf_big = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int vr, e, n, k, dist[MAX_N][MAX_N], pos[MAX_N];

int pa[MAX_N], pb[MAX_N];
vector<vector<int> > v(MAX_N);
bool used[MAX_N];

bool dfs(int p)
{
    used[p] = true;
    for (int i : v[p])
    {
        if (pb[i] == -1 || (!used[pb[i]] && dfs(pb[i])))
        {
            pa[p] = i;
            pb[i] = p;
            return true;
        }
    }
    return false;
}

void kuhn()
{
    memset(pa, -1, sizeof(pa));
    memset(pb, -1, sizeof(pb));
    for (int i = 0; i < n; i++)
    {
        memset(used, 0, sizeof(used));
        if (dfs(i))
            continue;
    }
}

bool check(int h)
{
    v.clear();
    v.resize(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < vr; j++)
            if (dist[pos[i]][j] <= h)
                v[i].push_back(j);
    kuhn();
    int kol = 0;
    for (int i = 0; i < n; i++)
        kol += (pa[i] != -1);
    return (kol >= k);
}

int main()
{   //*
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif /**/
    fast_read;
    cin >> vr >> e >> n >> k;
    for (int i = 0; i < vr; i++)
        for (int j = 0; j < vr; j++)
            dist[i][j] = BIG;
    for (int i = 0; i < vr; i++)
        dist[i][i] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> pos[i];
        pos[i]--;
    }
    for (int i = 0; i < e; i++)
    {
        int a, b, t;
        cin >> a >> b >> t;
        a--, b--;
        dist[a][b] = min(dist[a][b], t);
        dist[b][a] = min(dist[b][a], t);
    }
    for (int h = 0; h < vr; h++)
        for (int i = 0; i < vr; i++)
            for (int j = 0; j < vr; j++)
                dist[i][j] = min(dist[i][h] + dist[h][j], dist[i][j]);
    if (check(0))
    {
        cout << 0;
        return 0;
    }
    int l = 0;
    int r = 1731315;
    if (!check(r))
    {
        cout << -1;
        return 0;
    }
    while (r - l > 1)
    {
        int h = (l + r) / 2;
        if (check(h))
            r = h;
        else
            l = h;
    }
    cout << r;
    return 0;
}