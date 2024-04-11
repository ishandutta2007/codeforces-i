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
#include<ctime>
 
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
using std::clock;
 
 
typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-13;
const int INF = 100 * 1000;


int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int s = 0;
	vector<vector<int> > data(n);
	for (int i = 0; i < n; ++i) {
		int c;
		cin >> c;
		s += c;
		data[i].resize(c);
	}
	vector<pii> ind(s + 1);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < data[i].size(); ++j) {
			cin >> data[i][j];
			ind[data[i][j]] = make_pair(i, j);
		}
	}
	vector<pair<pii, pii> > moves;
	int x = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < data[i].size(); ++j, ++x) {
			int k = data[i][j];
			if (x != k) {
				int i1 = ind[x].first;
				int j1 = ind[x].second;
				swap(data[i][j], data[i1][j1]);
				moves.push_back(make_pair(make_pair(i + 1, j + 1), make_pair(i1 + 1, j1 + 1)));
				swap(ind[x], ind[k]);
			}
		}
	}
	cout << moves.size() << endl;
	for (int i = 0; i < moves.size(); ++i) {
		cout << moves[i].first.first << " " << moves[i].first.second << " " << moves[i].second.first << " " << moves[i].second.second << endl;
	}

	return 0;
}