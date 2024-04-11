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
const int INF = 1000 * 1000 * 10 + 10;
const int N = 1000 * 10000 + 10;

bool f(int x) {
	vector<int> a(10, 0);
	while(x) {
		int xx = x % 10;
		if (a[xx])
			return false;
		else
			++a[xx];
		x /= 10;
	}
	return true;
}

int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int y;
	cin >> y;
	for (int x = y + 1; ; ++x) {
		if (f(x)) {
			cout << x << endl;
			return 0;
		}
	}
	return 0;
}