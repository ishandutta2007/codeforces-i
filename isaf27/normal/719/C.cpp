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
template< typename T >
T gcd(T a, T b) { return a ? gcd(b % a, a) : b; }
template< typename T >
T lcm(T a, T b) { return (a / gcd(a, b)) * b; }
string int_to_str_easy(ll n) { return n ? "" : int_to_str_easy(n / 10) + (char)('0' + n % 10); }
template< typename T >
T sum(vector<T> v) {T ans = 0; for (T i : v) ans += i; return ans; }
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
const ll MOD = 1000000007;
const int BIG = 1e9;
const int alf = 26;
const int MAX_M = 2001;
const int MAX_N = 2 * 1e5 + 1;
const int km = (1 << 18) - 1;
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int bit_max = 32;

// Code starts here

void solve()
{
    return;
}

int n, q, u[MAX_N];
string s;

int main()
{   //*
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif /**/
    fast_read;
    cin >> n >> q >> s;
    string w;
    int pos = 0;
    while (s[pos] != '.')
        pos++;
    string t = "";
    for (int i = pos + 1; i < s.length(); i++)
        t += s[i];
    for (int i = 0; i < pos; i++)
        w += s[i];
    u[0] = -1;
    for (int i = 1; i < t.length(); i++)
    {
        if (t[i - 1] != '9')
            u[i] = i - 1;
        else
            u[i] = u[i - 1];
    }
    int p = -1;
    for (int i = 0; i < t.length(); i++)
        if (t[i] >= '5')
    {
        p = i;
        break;
    }
    //cerr << t << endl;
    if (p == -1)
    {
        cout << s;
        return 0;
    }
    int d = 0;
    for (int i = 0; i < q; i++)
    {
        if (t[p] < '5')
            break;
        if (u[p] == -1)
        {
            d = 1;
            p = -1;
            break;
        }
        p = u[p];
        t[p]++;
    }
    if (p == -1)
    {
        int m = w.length();
        string bad = "";
        for (int i = 0; i < m; i++)
            bad += '9';
        if (w == bad)
        {
            cout << 1;
            for (int i = 0; i < m; i++)
                cout << 0;
            return 0;
        }
        for (int i = m - 1; i >= 0; i--)
        {
            if (w[i] == '9')
            {
                w[i] = '0';
                continue;
            }
            w[i]++;
            break;
        }
        cout << w;
        return 0;
    }
    cout << w << ".";
    for (int i = 0; i <= p; i++)
        cout << t[i];
    return 0;
}