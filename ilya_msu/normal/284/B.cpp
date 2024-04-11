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
	int n;
	cin >> n;
	string s;
	cin >> s;
	int a, f, in;
	a = f = in = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'F')
			++f;
		if (s[i] == 'A')
			++a;
		if (s[i] == 'I')
			++in;
	}
	if (in > 1) 
		cout << 0 << endl;
	else
		if (in == 1)
			cout << 1 << endl;
		else
			cout << a << endl;
	return 0;
}