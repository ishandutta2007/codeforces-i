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
const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-5;
const int INF = 50000;
const int N = 1000 * 1000 * 1000 + 10;




int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int x;
	int res = 0;
	int m = 100000;
	int mi = 0;
	for (int i = 0; i < 2 * n - 1; ++i) {
		cin >> x;
		if (x < 0) {
			++mi;
			x = -x;
		}
		res += x;
		m = min(m, x);
	}
	if (n & 1)
		cout << res << endl;
	else
		if (mi & 1)
			cout << res - 2 * m << endl;
		else
			cout << res << endl;
	return 0;
}