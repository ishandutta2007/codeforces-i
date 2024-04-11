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
const int INF = 1000 * 1000;

map<int, int> m;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, x;
	cin >> n;
	int res = 0;
	bool pos = true;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		if (x == 0)
			continue;
		if (m.find(x) == m.end())
			m[x] = 0;
		++m[x];
		if (m[x] > 2)
			pos = false;
		if (m[x] == 2)
			++res;
	}
	if (pos)
		cout << res << endl;
	else
		cout << -1 << endl;
	return 0;
}