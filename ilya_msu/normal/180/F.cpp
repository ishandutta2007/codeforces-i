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
	int n;
	cin >> n;
	vector<pii> data(n);
	for (int i = 0; i < n; ++i) 
		cin >> data[i].first;
	for (int i = 0; i < n; ++i) 
		cin >> data[i].second;
	sort(data.begin(), data.end());
	for (int i = 0; i < n; ++i)
		cout << data[i].second << " ";
	cout << endl;
	return 0;
}