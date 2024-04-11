#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cmath>
using namespace std;
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
#define file_(filename) freopen(""filename".in", "r", stdin); freopen(""filename".out", "w", stdout);
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
ll n, m, k, l, r, x, y, x1, y1_, x2, y2, x3, y3, x4, y4, ans, cw, ccw;
string s;
int times1[26];
int times2[26];

int used_after[26][26];
int used[26];

char a1, a2;
//___________VARIABLES____________

int main()
{
    cin >> n >> m;
    cin >> s;
    for (int i = 1; i <= n; i++)
    {
        if (times1[s[i - 1] - 'A'] == 0)
            times1[s[i - 1] - 'A'] = i;
        times2[s[i - 1] - 'A'] = i;
    }
    for (int i = 0; i < 26; i++)
    {
        if (times1[i] == 0)
            used[i] = 1;
    }
    int u = 0;
    for (int i = 0; i < 26; i++)
    {
         for (int j = 0; j < 26; j++)
         {
             if (used[j] == 0)
             {
                 int can_ = 1;
                 for (int k = 0; k < 26; k++)
                 {
                     if (used_after[i][k] == 1)
                     {
                          if (times1[j] > times2[k] || times2[j] < times1[k])
                          {

                          }
                          else
                          {
                            can_ = 0;
                          }
                     }
                 }
                 if (can_ == 1)
                 {
                     used[j] = 1;
                     used_after[i][j] = 1;
                 }
             }
         }
    }
    for (int i = 0; i < 26; i++)
    {
        for (int k = 0; k < 26; k++)
        {
            if (used_after[i][k] == 1)
            {
                m--;
                break;
            }
        }
    }
    if (m >= 0)
    {
        r_NO;
    }
    r_YES;
}