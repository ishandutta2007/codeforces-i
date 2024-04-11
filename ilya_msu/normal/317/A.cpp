#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:128000000")
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

 
using namespace std; 
 
typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;

const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
//const long double eps = 1e-5;
//const int INF = 50000;
//const int N = 1000 * 1000 + 10;
//const ll mod = 1000 * 1000 * 1000 + 7;;


int main() {
    //std::ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll x, y, m;
    cin >> x >> y >> m;
    if (x < y)
        swap(x, y);
    if (x >= m) {
        cout << 0 << endl;
        return 0;
    }
    if (x <= 0) {
        cout << -1 << endl;
        return 0;
    }
    ll res = 0;
    if (y < 0) {
        ll q = -y / x;
        if (y % x != 0)
            ++q;
        res = q;
        y = y + x * q;
    }
    while(true) {
        if (x < y)
            swap(x, y);
        if (x >= m) {
            cout << res << endl;
            return 0;
        }
        y = x + y;
        ++res;
    }  
    return 0;
}