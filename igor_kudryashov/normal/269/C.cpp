#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <utility>
#include <numeric>
#include <functional>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forl(i, n) for (int i = 1; i <= int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i <= int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define ft first
#define sc second
#define x first
#define y second

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

const int N = 200 * 1000 + 13;

int n, m;
pt ed[N];
vector <pt> g[N];
vector <int> idx[N];
int sum[N], income[N];

inline bool read()
{
    if (scanf("%d%d", &n, &m) != 2)
        return false;

    forn(i, m)
    {
        int a, b, w;
        assert(scanf("%d%d%d", &a, &b, &w) == 3);
        --a, --b;

        ed[i] = mp(a, b);
        g[a].pb(mp(b, w));
        g[b].pb(mp(a, w));
        idx[a].pb(i);
        idx[b].pb(i);
        sum[a] += w;
        sum[b] += w;
    }

    return true;
}

int ans[N];
int used[N];

inline void solve()
{
    queue <int> q;
    q.push(0);

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        forn(i, sz(g[v]))
        {
            if (used[idx[v][i]]) continue;

            int to = g[v][i].ft;
            int w = g[v][i].sc;

            used[idx[v][i]] = true;
            if (ed[idx[v][i]].ft != v) ans[idx[v][i]] = 1;

            income[to] += w;
            if (to == n - 1) continue;

            assert(income[to] <= sum[to] / 2);
            if (income[to] == sum[to] / 2)
                q.push(to);
        }
    }

    forn(i, m)
    {
        assert(used[i]);
        printf("%d\n", ans[i]);
    }
}

int main()
{
#ifdef SU2_PROJ
    freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
#endif

    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;

    assert(read());
    solve();

    return 0;
}