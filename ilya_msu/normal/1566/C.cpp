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
#include<iterator>
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
const ll INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const ll mod = 998244353;


void solve() {
    string s1, s2;
    int n;
    cin >> n;
    cin >> s1 >> s2;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = (s1[i] - '0') * 2 + s2[i] - '0';
    }
    int res = 0;
    int sc[4] = {1, 2, 2, 0};
    for (int i = 0; i < n; ++i)
        res += sc[a[i]];
    vector<int> used(n, 0);
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            if ((i) && (a[i - 1] == 3) && (used[i - 1] == 0)) {
                ++res;
                used[i - 1] = 1;
            }
            else {
                if ((i + 1 < n) && (a[i + 1] == 3) && (used[i + 1] == 0)) {
                    ++res;
                    used[i + 1] = 1;
                }
            }
        }
    }
    cout << res << "\n";
}

//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    solve();

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}