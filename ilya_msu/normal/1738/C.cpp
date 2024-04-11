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

const int N = 101;
vector<vector<int> > d0(N, vector<int>(N, 0)), d1(N, vector<int>(N, 0));

void init() {
    
    d0[0][0] = 1;
    d1[0][0] = 0;
    for (int i = 1; i < N; ++i) {
        d0[i][0] = 1;
        d1[i][0] = 0;
        d0[0][i] = 1 - (((i + 1) / 2) & 1);
        d1[0][i] = 1 - d0[0][i];
    }
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < N; ++j) {
            if (j & 1) {
                if ((d0[i - 1][j] == 0) || (d0[i][j - 1] == 0))
                    d0[i][j] = 1;
                if ((d1[i - 1][j] == 0) || (d1[i][j - 1] == 0))
                    d1[i][j] = 1;
            }
            else {
                if ((d1[i - 1][j] == 0) || (d1[i][j - 1] == 0))
                    d0[i][j] = 1;
                if ((d0[i - 1][j] == 0) || (d0[i][j - 1] == 0))
                    d1[i][j] = 1;
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    int a, c0 = 0, c1 = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        if (abs(a) & 1)
            ++c1;
        else ++c0;
    }
    if (d0[c0][c1])
        cout << "Alice\n";
    else
        cout << "Bob\n";
    

}

int main() {
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    init();
    for (int i = 0; i < t; ++i)
        solve();



#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}