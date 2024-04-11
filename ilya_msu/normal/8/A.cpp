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
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000 + 1;
const ll LINF = (ll)1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const ll mod = 1000 * 1000 * 1000 + 7;
const int N = 1000000;

bool solve(const string& s, const string& s1, const string& s2) {
    size_t st = s.find(s1);
    if (st == string::npos)
        return 0;
    if (st + s1.size() + s2.size() > s.size())
        return 0;
    size_t st2 = (s.substr(st + s1.size(), s.size() - s1.size() - st)).find(s2);
    return (st2 != string::npos);
}

void solve() {
    string s, s1, s2;
    cin >> s >> s1 >> s2;
    bool f = solve(s, s1, s2);
    reverse(s.begin(), s.end());
    bool b = solve(s, s1, s2);
    if (f && b) {
        cout << "both\n";
        return;
    }
    if (f) {
        cout << "forward\n";
        return;
    }
    if (b) {
        cout << "backward\n";
        return;
    }
    cout << "fantasy\n";
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