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
using std::priority_queue;

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

#define F(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define fi first
#define se second
#define re return
#define all(x) (x).begin(), (x).end()
#define int long long

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

struct kewa1{
    vector<pii> a;
    void insert(int x)
    {
        if (a.size() == 0)
            a.push_back({x, x});
        else
            a.push_back({x, std::min(x, 1LL * a[a.size() - 1].second)});
    }
    int min()
    {
        if (a.size() == 0)
            return 1e9;
        else
            return a[a.size() - 1].second;
    }
    void erase()
    {
        if (a.size()) a.pop_back();
    }
    void pri()
    {
        for (int i = 0; i < a.size(); i++)
        {
            cout << a[i].first << " ";
        }
        cout << endl;
    }
};

struct kewa2{
    kewa1 a, b;
    void insert(int x)
    {
        b.insert(x);
    }
    void erase()
    {
        if (a.a.size() == 0)
        {
            while (b.a.size())
            {
                a.insert(b.a[b.a.size() - 1].first);
                b.erase();
            }
            //reverse(all(a.a));
        }
        a.erase();
    }
    int min()
    {
        return std::min(a.min(), b.min());
    }
    void pri()
    {
        cout << "a : ";
        a.pri();
        cout << "b : ";
        b.pri();
        cout << endl;
    }
};

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

const ll MOD = 998244353;
//const ll MOD = 1e9 + 7;

ll n, m;
ll a[5000];
ll dp[501][501];

ll shift(int l, int r)
{
    if (r == l)
        return 1;
    if (r < l)
        return 1;
    if (dp[l][r] != -1)
        return dp[l][r];
    int minC = 999, pos = 0;
    for (int i = l; i <= r; i++)
    {
        minC = min(minC, a[i]);
        if (a[i] == minC)
            pos = i;
    }
    ll ans1 = 0, ans2 = 0;
    for (int border = l - 1; border < pos; border++)
    {
        //cout << l << " " << border << " and " << border + 1 << " " << pos - 1 << endl;
        ans1 += shift(l, border) * shift(border + 1, pos - 1);
        ans1 %= MOD;
    }

    for (int border = pos + 1; border <= r + 1; border++)
    {
        ans2 += shift(pos + 1, border - 1) * shift(border, r);
        ans2 %= MOD;
    }
    //cout << l << " " << r << " " << ans1 << " " << ans2 << endl;
    return dp[l][r] = (ans1 * ans2) % MOD;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    //#slow
    cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) dp[i][j] = -1;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << shift(0, n - 1);
}