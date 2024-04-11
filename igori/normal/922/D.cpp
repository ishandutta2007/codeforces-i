#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
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
//___________BAZE_________________
ll n, m, ans;
string s[766666];
map<int, int> mm;
ll x, y, a, b;
vector<pair<double, string> > pss;
string ss;
//___________VARIABLES____________

int dp(int x, int y)
{
    do_nothing;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        double alpha = 0, beta = 0;
        for (int j = 0; j < s[i].sz; j++)
        {
            if (s[i][j] == 's')
                alpha++;
            else
                beta++;
        }
        if (beta == 0)
            pss.pb({1000000, s[i]});
        else
            pss.pb({alpha / beta, s[i]});
    }
    sort(pss.begin(), pss.end());
    for (int i = pss.sz - 1; i >= 0; i--)
    {
        ss = ss + pss[i].second;
    }
    ll ans = 0;
    ll ha = 0;
   // cout << ss << endl;
    for (int i = 0; i < ss.sz; i++)
    {
        if (ss[i] == 's')
            ha++;
        else
            ans += ha;
    }
    cout << ans;
}