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
const int M = 1e5 + 239;
const int N = 2e3 + 239;
const int L = 19;
const int T = (1 << 19);
const int B = trunc(sqrt(M)) + 1;
const int X = 110;

int n, m, a[N];
bool used[N];
vector<pair<int, int> > v;

void make_move()
{
    if (!v.empty())
    {
        pair<int, int> nw = v.back();
        v.pop_back();
        if (a[nw.first] < a[nw.second])
            swap(nw.first, nw.second);
        cout << nw.first + 1 << endl;
        used[nw.first] = true;
        return;
    }
    int it = -1;
    for (int i = 0; i < n; i++)
        if (!used[i])
            if (it == -1 || a[it] < a[i])
                it = i;
    cout << (it + 1) << endl;
    used[it] = true;
}

int main()
{
    #ifdef ONPC
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    n += n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
    {
        int s, f;
        cin >> s >> f;
        s--, f--;
        v.push_back(make_pair(s, f));
    }
    int t;
    cin >> t;
    if (t == 1)
    {
        for (int i = 0; i < n; i += 2)
        {
            make_move();
            int ans;
            cin >> ans;
            ans--;
            used[ans] = true;
        }
        return 0;
    }
    for (int i = 0; i < n; i += 2)
    {
        int ans;
        cin >> ans;
        ans--;
        used[ans] = true;
        int ch = -1;
        for (int x = 0; x < (int)v.size(); x++)
            if (v[x].first == ans || v[x].second == ans)
            {
                if (v[x].first == ans)
                    cout << v[x].second + 1 << endl;
                else
                    cout << v[x].first + 1 << endl;
                used[v[x].first] = true;
                used[v[x].second] = true;
                ch = x;
                break;
            }
        if (ch != -1)
        {
            swap(v[ch], v.back());
            v.pop_back();
            continue;
        }
        make_move();
    }
    return 0;
}