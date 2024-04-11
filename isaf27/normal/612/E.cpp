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
#define random srand(time(NULL))
#define rand_int abs((rand() << 15) | rand())
#define str_to_int(stroka) atoi(stroka.c_str())
#define str_to_ll(stroka) atoll(stroka.c_str())
#define str_to_double(stroka) atof(stroka.c_str())
#define what_is(x) cerr << #x << " is " << x << endl
#define solve_system int number; cin >> number; forn(i, 0, number) solve()
#define solve_system_scanf int number; scanf("%d", &number); forn(i, 0, number) solve()

//easy functions
template< typename T >
T gcd(T a, T b) { return a ? gcd(b % a, a) : b; }
template< typename T >
T lcm(T a, T b) { return (a / gcd(a, b)) * b; }
bool is_down(char x) { return ('a' <= x && x <= 'z'); }
bool is_upper(char x) { return ('A' <= x && x <= 'Z'); }
bool is_digit(char x) { return ('0' <= x && x <= '9'); }

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
const int MOD = 1e9 + 7;
const int BIG = 2 * 1e9 + 1;
const int alf = 26;
const int MAX_N = 1e6 + 10;
const int MAX_M = 2001;
const int MAX_T = (1 << 20);
const int BLOCK = trunc(sqrt(MAX_N)) + 1;
const int MAX_LOG = 18;
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
const int bt = 31;

// Code starts here

bool used[MAX_N];
int n, a[MAX_N], r, ans[MAX_N];
vector<vector<int> > c;
vector<int> cyc;

void dfs(int p)
{
    used[p] = true;
    cyc.push_back(p);
    if (!used[a[p]])
        dfs(a[p]);
}

int main()
{   //*
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif /**/
    fast_read;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
    }
    memset(used, 0, sizeof(used));
    r = 0;
    for (int i = 0; i < n; i++)
        if (!used[i])
        {
            cyc.clear();
            dfs(i);
            c.push_back(cyc);
            r++;
        }
    vector<pair<int, int> > sz;
    for (int i = 0; i < r; i++)
    {
        if (c[i].size() & 1)
        {
            for (int x = 0; x < c[i].size(); x++)
                ans[c[i][x]] = c[i][(x + 1 + (c[i].size() / 2)) % c[i].size()];
        }
        else
            sz.push_back(make_pair(c[i].size(), i));
    }
    sort(sz.begin(), sz.end());
    if (sz.size() & 1)
    {
        cout << "-1";
        return 0;
    }
    for (int i = 0; i < sz.size(); i += 2)
    {
        if (sz[i].first != sz[i + 1].first)
        {
            cout << "-1";
            return 0;
        }
        int a = sz[i].first;
        int s = sz[i].second;
        int f = sz[i + 1].second;
        for (int i = 0; i < a; i++)
            ans[c[s][i]] = c[f][i];
        for (int i = 0; i < a; i++)
            ans[c[f][i]] = c[s][(i + 1) % a];
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] + 1 << " ";
    return 0;
}