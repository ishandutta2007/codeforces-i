#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:64000000")
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

using std::pair;
using std::stringstream;
using std::next_permutation;
using std::sqrt;
using std::priority_queue;
using std::sort;
using std::stack;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::min;
using std::max;
using std::set;
using std::swap;
using std::random_shuffle;
using std::queue;
using std::sin;
using std::cos;
using std::make_pair;
using std::cos;
using std::cerr;
using std::map;

typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const double eps = 1e-12;

bool f(int a, int b) {
	return ((b + 1 >= a) && (2 * a + 2 >= b));
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int d, s;
	cin >> d >> s;
	vector<int> l(d), r(d);
	int mins = 0, maxs = 0;
	for (int i = 0; i < d; ++i) {
		cin >> l[i] >> r[i];
		mins += l[i];
		maxs += r[i];
	}
	if ((s > maxs) || (s < mins)) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	int dif = s - mins;
	for (int i = 0; i < d; ++i) {
		int x = min(l[i] + dif, r[i]);
		cout << x << " ";
		dif -= x - l[i];
	}
	cout << endl;
	return 0;
}