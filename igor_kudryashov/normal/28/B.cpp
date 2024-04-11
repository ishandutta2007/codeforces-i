#pragma comment (linker, "/stack:16000000")
#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <sstream>
#include <utility>
#include <stack>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <complex>
#include <algorithm>
#include <set>
#include <list>
#include <map>
#include <string>
#include <queue>
#include <cmath>
#include <cassert>
#include <ctime>

using namespace std;

#define forn(i, n) for (int i = 0; i < int (n); i++)
#define for1(i, n) for (int i = 1; i <= int (n); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define mp make_pair
#define pb push_back
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define X first
#define Y second
#define ft first
#define sc second

template <typename X> inline X abs (const X& a) { return a < 0 ? -a : a; }
template <typename X> inline X sqr (const X& a) { return a * a; }

typedef long long li;
typedef pair <int, int> pt;
typedef long double ld;
typedef pair <ld, ld> ptd;
const int INF = int (1e9);
const int NMAX = int (1e4);
const ld EPS = 1e-9;
const ld PI = 3.1415926535897932384626433832795;

const int N = 100 + 13;

int n;
int a[N], d[N];
vector <int> g[N];
bool used[N];

void dfs (int v)
{
    used[v] = true;

    forn(i, sz(g[v]))
    {
        int to = g[v][i];

        if (!used[to])
            dfs(to);
    }
}

int main()
{ 

    cin >> n;

    forn(i, n)
        scanf("%d", &a[i]), a[i]--;

    forn(i, n)
        scanf("%d", &d[i]);

    forn(i, n)
    {
        int next = i + d[i];
        if (next < n)
        {
            g[i].push_back(next);
            g[next].push_back(i);
        }

        int prev = i - d[i];
        if (prev >= 0)
        {
            g[i].push_back(prev);
            g[prev].push_back(i);
        }
    }

    forn(i, n)
    {
        memset(used, 0, sizeof(used));
        dfs(i);

        if (!used[a[i]])
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}