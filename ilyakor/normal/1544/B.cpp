/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author
 */

#include <iostream>
#include <fstream>

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <functional>
#include <sstream>
#include <cmath>

#include <cstring>
#include <cstdio>

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())

template<class T> T abs(T x) { return x >= 0 ? x : -x; }
template<class T> T sqr(T x) { return x * x; }

class TaskB {
public:
	void solve(std::istream& in, std::ostream& out) {
	    int n, m;
	    in >> n >> m;
	    vector<vi> a(n, vi(m, 0));
	    a[0][0] = a[n - 1][0] = a[0][m - 1] = a[n - 1][m - 1] = 1;
	    for (int i = 2; i < n - 2; i += 2) {
	        a[i][0] = a[i][m - 1] = 1;
	    }
	    for (int j = 2; j < m - 2; j += 2) {
	        a[0][j] = a[n - 1][j] = 1;
	    }
	    for (int i = 0; i < n; ++i) {
	        for (int j = 0; j < m; ++j)
	            out << a[i][j];
	        out << "\n";
	    }
	    out << "\n";
	}
};


int main() {
	TaskB solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	int n;
in >> n;
for(int i = 0; i < n; ++i) {
	solver.solve(in, out);
}

	return 0;
}