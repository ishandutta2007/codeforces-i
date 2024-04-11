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
//	    vi v;
//	    for (int i = 0; i < 6; ++i)
//	        v.pb(i + 1);
//	    int cnt = 0;
//	    do {
//	        bool ok = true;
//	        for (int i = 0; i + 1 < sz(v); ++i)
//	            if (v[i + 1] < v[i] - 1) ok = false;
//            if (ok) {
//                for (int x : v)
//                    cerr << x << " ";
//                cerr << "\n";
//                cerr.flush();
//                ++cnt;
//            }
//	    } while (next_permutation(all(v)));
//	    cerr << cnt << "\n";
//	    assert(false);

	    int n;
	    int64 k;
	    in >> n >> k;
	    --k;
	    int inc = 0;
	    vi cache;
	    vi res;
	    for (int i = 0; i < n; ++i) {
	        cache.pb(inc + 1);
	        int64 cur = k;
	        for (int j = 0; j < n - i - 2 && cur > 0; ++j)
	            cur /= 2LL;
	        if (cur == 0) {
	            reverse(all(cache));
	            for (int x : cache)
	                res.pb(x);
	            cache.clear();
	            ++inc;
	        } else {
	            int64 val = 1;
                for (int j = 0; j < n - i - 2; ++j)
                    val *= 2LL;
                k -= val;
	            ++inc;
	        }
	    }
	    if (k > 0 || !cache.empty()) {
	        out << "-1\n";
            return;
	    }
	    for (int x : res)
	        out << x << " ";
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