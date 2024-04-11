#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<utility>
#include<map>
#include<ctime>
#include<cstdio>
#include<cassert>
#include<functional>




using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;
typedef pair<double, double> pdd;

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)

const long double PI = 3.14159265358979323846;
const long double eps = 1e-5;
const int INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const ll mod = 1000 * 1000 * 1000 + 7;

vector<vector<int> > g;
vector<int> used;

int dfs(int pos, int p) {
    if (used[pos])
        return pos;
    int res = -1;
    for (int i = 0; i < g[pos].size(); ++i) {
        int to = g[pos][i];
        if (to == p)
            continue;
        res = dfs(to, pos);
        if (res != -1)
            return res;

    }
    return -1;
}

void solveTest() {
    int n;
    cin >> n;
    g.clear();
    g.resize(n);
    used.assign(n, 0);
    for (int i = 0; i + 1 < n; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int k1, k2;
    cin >> k1;
    vector<int> x(k1);
    for (int i = 0; i < k1; ++i) {
        cin >> x[i];
        --x[i];
        used[x[i]] = 1;
    }
    cin >> k2;
    vector<int> y(k2);
    for (int i = 0; i < k2; ++i) {
        cin >> y[i];
        --y[i];
    }
    cout << "B " << y[0] + 1 << endl;
    int yy;
    cin >> yy;
    --yy;
    int xx = dfs(yy, -1);
    cout << "A " << xx + 1 << endl;
    int z;
    cin >> z;
    --z;
    for (int i = 0; i < k2; ++i) {
        if (z == y[i]) {
            cout << "C " << xx + 1 << endl;
            return;
        }
    }
    cout << "C " << -1 << endl;
    return;


}


void solve() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solveTest();
    }
    
    
}

//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    solve();


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}