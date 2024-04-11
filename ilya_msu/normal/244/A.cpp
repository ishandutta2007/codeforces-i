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
const int INF = 1000 * 1000 * 1000 + 10;
const int N = 1000 * 1000 * 1000 + 10;


int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
 	vector<int> a(n * k, -1);
	vector<vector<int> > c(k);
	for (int i = 0; i < k; ++i) {
		int x;
		cin >> x;
		a[x - 1] = i;
		c[i].push_back(x);
	}
	int l = 0;
	for (int i = 0; i < n * k; ++i) {
		if (a[i] != -1)
			continue;
		if (c[l].size() >= n)
			++l;
		c[l].push_back(i + 1);
	}
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < n; ++j)
			cout << c[i][j] << " ";
		cout << endl;
	}
	return 0;
}