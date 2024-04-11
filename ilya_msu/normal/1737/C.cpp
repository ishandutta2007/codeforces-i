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
#include<unordered_set>
#include<chrono>
#include<random>



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
const int INF = 1000 * 1000 * 1000 + 1;
const ll LINF = (ll)1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const ll mod = 998244353;

vector<int> nums;

pii getc(vector<pii> p) {
    int odd = 0;
    for (int i = 0; i < 3; ++i) {
        if ((p[i].first + p[i].second) & 1)
            odd ^= 1;
    }
    for (int i = 0; i < 3; ++i) {
        if (((p[i].first + p[i].second) & 1) == odd)
            return p[i];
    }
}

bool isCorner(pii p, int n) {
    return ((p.first == 1) || (p.first == n)) && ((p.second == 1) || (p.second == n));
}

void solve() {
    int n;
    cin >> n;
    vector<pii> p(3);
    for (int i = 0; i < 3; ++i) {
        cin >> p[i].first >> p[i].second;
    }
    int x, y;
    cin >> x >> y;
    pii c = getc(p);
    if (isCorner(c, n)) {
        if ((x == c.first) || (y == c.second))
            cout << "YES\n";
        else
            cout << "NO\n";
        return;
    }
    if ((x + y + c.first + c.second) & 1) {
        cout << "YES\n";
        return;
    }
    if ((x + c.first) & 1)
        cout << "NO\n";
    else
        cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    solve();



#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}