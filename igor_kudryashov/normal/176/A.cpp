#pragma comment(linker, "/stack:64000000")
#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include <algorithm>
#include <iostream>
#include <fstream>
#include <cassert>
#include <iomanip>
#include <utility>
#include <cstring>
#include <complex>
#include <cstdlib>
#include <bitset>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define for1(i, n) for (int i = 1; i <= int(n); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define debug(x) cerr << #x << " = " << x << endl;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair((a), (b))
#define X first
#define Y second
#define ft first
#define sc second

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long double ld;
typedef pair<ld, ld> ptd;
typedef pair <int, int> pt;
typedef long long li;
typedef unsigned char byte;

const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-9;
const int INF = 1000 * 1000 * 1000;

const int N = 100 + 13;

int n, m, K;
int a[N][N], b[N][N], c[N][N];

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n >> m >> K;
    
    forn(i, n)
    {
        char buf[100];
        scanf("%s", buf);
        
        forn(j, m)
            scanf("%d%d%d", &a[i][j], &b[i][j], &c[i][j]);
    }
    
    int ans = 0;
    
    forn(i, n)
        forn(j, n)
            {
                vector <pt> v;
                
                forn(k, m)
                    v.pb(mp(b[j][k] - a[i][k], c[i][k]));
                    
                sort(all(v));
                reverse(all(v));
                
                int cur = 0, curCnt = 0;
                
                forn(k, sz(v))
                    if (v[k].ft < 0)
                        break;
                    else
                    {
                        int mincnt = min(K - curCnt, v[k].sc);
                        curCnt += mincnt;
                        cur += v[k].ft * mincnt;
                    }
                    
                ans = max(ans, cur);
            }
            
    cout << ans << endl;

    return 0;
}