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

typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  



int main() {
	//freopen("input.txt", "r", stdin);
	int n, t1, t2, k;
	cin >> n >> t1 >> t2 >> k;
	vector<pii> data(n);
	for (int i = 0; i < n; ++i) {
		data[i].second = i + 1;
		int a, b;
		cin >> a >> b;
		data[i].first = -max(a * t1 * (100 - k) + 100 * b * t2, b * t1 * (100 - k) + 100 * a * t2);
	}
	sort(data.begin(), data.end());
	for (int i = 0; i < n; ++i)
		printf("%d %0.2f\n", data[i].second, (double)(-data[i].first) / 100.0);
	return 0;
}