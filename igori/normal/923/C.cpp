const int MOD = 1e9 + 7;
const long long INF = 1e9;
const long long INFLL = 1e18;

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef complex<double> cd;

#define forn(i, n) for (int i = 0; (i) != (n); (i)++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define popcount(x) __builtin_popcount(x)
#define popcountll(x) __builtin_popcountll(x)
#define fi first
#define se second
#define re return
#define pb push_back
#define uniq(x) sort(all(x)); (x).resize(unique(all(x)) - (x).begin())

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " " << #x << " " << x << endl
#define ln cerr << __LINE__ << endl
#else
#define dbg(x) void(0)
#define ln void(0)
#endif // LOCAL

int cx[4] = {-1, 0, 1, 0};
int cy[4] = {0, -1, 0, 1};
string Yes[2] = {"No\n", "Yes\n"};
string YES[2] = {"NO\n", "YES\n"};
string Possible[2] = {"Impossible\n", "Possible\n"};
string POSSIBLE[2] = {"IMPOSSIBLE\n", "POSSIBLE\n"};

#define ok(x, n) (0 <= (x) && (x) < (n))
#define withBit(mask, i) ((mask & (1 << i)) > 0)

template<typename T> istream& operator>>(istream& in, vector<T>& a)
{
    for (int i = 0; i < a.size(); i++)
        in >> a[i];
    return in;
}

template<typename T> ostream& operator<<(ostream& out, const vector<T>& a)
{
    for (auto e : a)
    {
        out << e << " ";
        if (typeid(T) != typeid(int) && typeid(T) != typeid(ll))
            out << "\n";
    }
    return out;
}

void solve()
{
    int n;
    cin >> n;
    vi a(n), p(n);
    cin >> a >> p;

    struct Trie{
        vector<vector<int> > go;
        vector<int> sz;
        Trie()
        {
            go.resize(1);
            go[0] = {0, 0};
            sz.resize(1);
        }

        void add(int x, int k)
        {
            int pnt = 0;
            sz[pnt] += k;
            for (int b = 29; b >= 0; b--)
            {
                int bi = withBit(x, b);
                if (go[pnt][bi] == 0)
                {
                    go[pnt][bi] = go.size();
                    go.push_back({0, 0});
                    sz.push_back(0);
                }
                pnt = go[pnt][bi];
                sz[pnt] += k;
            }
        }

        int make(int x)
        {
            int pnt = 0;
            int res = 0;
            for (int b = 29; b >= 0; b--)
            {
                int bi = withBit(x, b);
                if (go[pnt][bi] != 0 && sz[go[pnt][bi]])
                {
                    pnt = go[pnt][bi];
                    res += (bi << b);
                }
                else
                {
                    pnt = go[pnt][1 ^ bi];
                    res += ((1 ^ bi) << b);
                }
            }
            add(res, -1);
            return x ^ res;
        }
    };

    Trie T;
    for (auto e : p) T.add(e, 1);

    forn(i, n)
    {
        cout << T.make(a[i]) << " ";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    #ifdef tests
    cin >> t;
    #endif // tests
    while (t--)
    {
        solve();
    }
}