//isaf27

//#pragma GCC optimize("O3")
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
#include <ctime>
#include <bits/stdc++.h>
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
#define solve_system int number; cin >> number; for (int i = 0; i < number; i++) solve()
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
const ld eps = 1e-6;
const ld zero = 0;
const ll INF = 1e18;
const int COUT = 30;
const int prost = 239;
const ll prost64 = 239;
const int two = 2;
const int thr = 3;
const ll sr = 31;
const ll MOD = 1e9 + 7;
const ll MOD2 = MOD * MOD;
const int BIG = 1e9 + 239;
const int alf = 26;
const int M = 3 * 1e5 + 239;
const int N = 2 * 1e3 + 239;
const int L = 20;
const int T = (1 << 20);
const int B = trunc(sqrt(M)) + 1;
const int MAX_LOG = 19;
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
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int bt = 31;

// Code starts here

int n;
ll x[M];
char c[M];
vector<ll> pos;
vector<ll> a, b;

int main()
{   //*
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif /**/
    fast_read;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> c[i];
    pos.push_back(-10LL * (ll)BIG);
    for (int i = 0; i < n; i++)
        if (c[i] == 'G')
            pos.push_back(x[i]);
    pos.push_back(10LL * (ll)BIG);
    for (int i = 0; i < n; i++)
        if (c[i] == 'R')
            a.push_back(x[i]);
    for (int i = 0; i < n; i++)
        if (c[i] == 'B')
            b.push_back(x[i]);
    if (pos.size() == 2)
    {
        cout << (a.empty() ? 0 : (a.back() - a[0])) + (b.empty() ? 0 : (b.back() - b[0]));
        return 0;
    }
    ll ans = 0;
    for (int i = 0; i < (int)pos.size() - 1; i++)
    {
        ll l = pos[i];
        ll r = pos[i + 1];
        int al = lower_bound(a.begin(), a.end(), l) - a.begin();
        int ar = lower_bound(a.begin(), a.end(), r) - a.begin();
        int bl = lower_bound(b.begin(), b.end(), l) - b.begin();
        int br = lower_bound(b.begin(), b.end(), r) - b.begin();
        ll now = 2LL * (r - l);
        ll be = 3LL * (r - l);
        vector<ll> y;
        y.push_back(l);
        for (int x = al; x < ar; x++)
            y.push_back(a[x]);
        y.push_back(r);
        ll mx = 0;
        for (int x = 0; x < (int)y.size() - 1; x++)
            mx = max(mx, y[x + 1] - y[x]);
        be -= mx;
        y.clear();
        y.push_back(l);
        for (int x = bl; x < br; x++)
            y.push_back(b[x]);
        y.push_back(r);
        mx = 0;
        for (int x = 0; x < (int)y.size() - 1; x++)
            mx = max(mx, y[x + 1] - y[x]);
        be -= mx;
        ans += min(be, now);
    }
    ll en = (pos[1] - pos[0]) + (pos.back() - pos[(int)pos.size() - 2]);
    cout << (ans - en);
    return 0;
}