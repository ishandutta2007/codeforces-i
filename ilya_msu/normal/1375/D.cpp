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
#include<unordered_map>
#include<deque>
#include<cmath>





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
const ll INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const ll mod = 998244353;

void solveCase() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<int> res;
    vector<int> used(n);
    while (true) {
        used.assign(n + 1, 0);
        int ok = 1;
        int id = -1;
        for (int i = 0; i < n; ++i) {
            ++used[a[i]];
            if (a[i] != i) {
                ok = 0;
                id = i;
            }
        }
        if (ok)
            break;
        int m = 0;
        while(used[m])
            ++m;
        if (m < n) {
            res.push_back(m);
            a[m] = m;
            continue;
        }
        res.push_back(id);
        a[id] = m;
    }
    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] + 1 << " ";
    }
    cout << "\n";
}


void solve() {
    int t;
    cin >> t;
    for (int tt = 0; tt < t; ++tt) {
        solveCase();
    }
}


//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
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