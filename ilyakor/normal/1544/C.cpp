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

class TaskC {
public:
    void solve(std::istream& in, std::ostream& out) {
	    int n;
	    in >> n;
	    vi a(n), b(n);
	    for (int i = 0; i < n; ++i)
	        in >> a[i];
	    for (int i = 0; i < n; ++i)
	        in >> b[i];
	    int down = -1, up = (n + 1) * 3;
	    while (up - down > 1) {
	        int t = (up + down) / 2;
	        if (check(a, b, t)) {
	            up = t;
	        } else {
	            down = t;
	        }
	    }
	    out << up << "\n";
	}

    bool check(vi a, vi b, int cnt) {
        for (int i = 0; i < cnt; ++i) {
            a.pb(100);
            b.pb(0);
        }
        sort(all(a));
        sort(all(b));
        int k = sz(a) / 4;
        int ra = 0, rb = 0;
        for (int i = k; i < sz(a); ++i) {
            ra += a[i];
            rb += b[i];
        }
        return ra >= rb;
    }
};


int main() {
	TaskC solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	int n;
in >> n;
for(int i = 0; i < n; ++i) {
	solver.solve(in, out);
}

	return 0;
}