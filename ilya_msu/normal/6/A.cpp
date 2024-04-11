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



int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<int> data(4);
	for (int i = 0; i < 4; ++i)
		cin >> data[i];
	sort(data.begin(), data.end());
	if ((data[0] + data[1] > data[2]) || (data[2] + data[1] > data[3])) {
		cout << "TRIANGLE" << endl;
		return 0;
	}
	if ((data[0] + data[1] == data[2]) || (data[2] + data[1] == data[3])) {
		cout << "SEGMENT" << endl;
		return 0;
	}
	cout << "IMPOSSIBLE" << endl;
	return 0;
}