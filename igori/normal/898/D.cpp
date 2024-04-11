#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <cstdio>
using namespace std;
#define ch_NO(x) cout << "NO\n"; x = 1 - x;
#define b_NO cout << "NO\n"; break;
#define r_NO cout << "NO\n"; return 0;
#define c_NO cout << "NO\n"; continue;
#define ch_YES(x) cout << "YES\n"; x = 1 - x;
#define b_YES cout << "YES\n"; break;
#define r_YES cout << "YES\n"; return 0;
#define c_YES cout << "YES\n"; continue;
#define f(i, n) for (int i = 0; i < n; i++)
#define sz size()
#define pb push_back
#define int_ "%d",
#define fi first
#define se second
#define th third
#define re return
#define MOD 1000000007
#define mm(k) memset((k), -1, sizeof(k));
#define in insert
#define co count
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
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
const ll INF = 1e18 + 2;
const int LIT = 505;
const int BIG = 200001;
string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
ll fact[13] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362280, 3622800, 39916800, 479001600};
int cx[6] = {1, -1, 0, 0, 0, 0};
int cy[6] = {0, 0, 1, -1, 0, 0};
int cz[6] = {0, 0, 0, 0, 1, -1};
ll st_10[10] = {1, 10, 100, 1000, 10000, 1000000, 10000000, 100000000, 1000000000};
ll st_2[30]  = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912};
//___________BAZE_________________
ll m, l, r, x, y, t, k, n, b, ans;
ll a[203404];
ll kk[2037000];
//___________VARIABLES____________

/*int din(int x)
{
    if (table[x] != -1)
    {
        return table[x];
    }
    if (x < 0)
        return 0;
    int ans = 0;
    if (k[n] == 0)
        ans = din(x - 1);
    else
    {
        ans = min(din(x - 1) + 1, din
    }
    return ans;
}*/

int main()
{
    //mm(table);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        kk[a[i]] = 1;
    }
    int now = 0;
    for (int i = 0; i <= 1000000; i++)
    {
        if (kk[i] == 1)
            now++;
        if (i - m >= 0 && kk[i - m] == 1)
            now--;
        if (now >= k)
        {
            now--;
            kk[i] = 0;
            ans++;
        }
    }
    cout << ans;
}