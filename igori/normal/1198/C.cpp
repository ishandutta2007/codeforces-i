#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <bitset>
#include <queue>
#include <stack>
#include <deque>
#include <time.h>
#include <complex>

#define int long long

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

using std::map;
using std::set;
using std::bitset;
using std::vector;
using std::string;
using std::multimap;
using std::multiset;
using std::deque;
using std::queue;
using std::stack;
using std::pair;
using std::iterator;
using std::complex;

using std::sort;
using std::stable_sort;
using std::reverse;
using std::max_element;
using std::min_element;
using std::unique;
using std::ios_base;
using std::swap;
using std::fill;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef string S;
typedef complex<double> cd;

ll min(ll a, ll b)
{
    if (a < b)
        return a;
    return b;
}

ll max(ll a, ll b)
{
    if (a > b)
        return a;
    return b;
}

namespace MySpace{
    struct Small_Segment_Tree{
        vector<int> a;
        int l, r;

        private:
        int __summ(int L, int R, int l, int r, int v)
        {
            if (L <= l && r <= R)
                return a[v];
            if (R <= l || r <= L)
                return 0;
            int m = (l + r) / 2;
            return __summ(L, R, l, m, 2 * v + 1) + __summ(L, R, m, r, 2 * v + 2);
        }

        void __set(int P, int l, int r, int v, int V)
        {
            if (l + 1 == r)
            {
                a[v] = V;
                return;
            }
            int m = (l + r) / 2;
            if (P < m)
            {
                __set(P, l, m, 2 * v + 1, V);
                a[v] = a[2 * v + 1] + a[2 * v + 2];
            }
            else
            {
                __set(P, m, r, 2 * v + 2, V);
                a[v] = a[2 * v + 1] + a[2 * v + 2];
            }
        }

        public:
        int Summ(int L, int R)
        {
            if (R < L)
                return 0;
            return __summ(L, R + 1, l, r, 0);
        }

        void Set(int P, int V)
        {
            __set(P, l, r, 0, V);
        }

        Small_Segment_Tree(int _n)
        {
            a.resize(4 * _n);
            l = 0, r = _n;
        }
    };
    long long inq(long long x, long long q, long long MOD)
    {
        if (q == 0)
            return 1;
        long long l = inq(x, q / 2, MOD);
        if (q % 2)
            return l * l % MOD * x % MOD;
        return l * l % MOD;
    }
};


using namespace MySpace;

#define F(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define fi first
#define se second
#define re return
#define all(x) (x).begin(), (x).end()

void YN(int val)
{
    if (val >= 1)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}

#define y0 y1234
//const ll MOD = 998244353;
const ll MOD = 1e9 + 7;

int t, n, m;

inline void solve()
{
    scanf("%d %d", &n, &m);
    vector<int> A, B, a(m), b(m), mark(3 * n + 1);
    vector<vector<int>> graph(3 * n + 1);
    for (int i = 0; i < m; i++)
    {
        int v, u;
        scanf("%d %d", &v, &u);
        graph[v].push_back(i);
        graph[u].push_back(i);
        a[i] = u;
        b[i] = v;
    }
    for (int i = 1; i <= 3 * n; i++)
    {
        if (mark[i]) continue;
        for (int j = 0; j < graph[i].size(); j++)
        {
            int u = a[graph[i][j]] + b[graph[i][j]] - i;
            if (mark[u] == 0)
            {
                mark[i] = 1, mark[u] = 1;
                A.push_back(graph[i][j]);
                break;
            }
        }
        if (mark[i] == 0)
        {
            mark[i] = 1;
            B.push_back(i);
        }
    }
    if (A.size() >= n)
    {
        printf("Matching\n");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", A[i] + 1);
        }
        printf("\n");
    }
    else
    {
        printf("IndSet\n");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", B[i]);
        }
        printf("\n");
    }
    return;
}

signed main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        solve();
    }
}