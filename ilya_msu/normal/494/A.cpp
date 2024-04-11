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
const ll N = 1001;
//const int M = 10000000;



void solve() {
	string s;
	cin >> s;
	int x = 0;
	vector<int> res;

	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '(') {
			++x;
		}
		if (s[i] == ')') {
			--x;
		}
		if (s[i] == '#') {
			res.push_back(1);
			--x;
		}
	}
	bool ok = true;
	if (x < 0) {
		ok = false;
	}
	res[res.size() - 1] += x;
	x = 0;
	int j = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '(')
			++x;
		if (s[i] == ')')
			--x;
		if (s[i] == '#') {
			x -= res[j];
			++j;
		}
		if (x < 0)
			ok = false;
	}
	if (!ok) {
		cout << -1 << endl;
		return;
	}
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << "\n";
	}
}



//#define LOCAL

int main() {
	//ios_base::sync_with_stdio(0);
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