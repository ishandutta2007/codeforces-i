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

class TaskE {
public:
    int mod;
    //vector<vector<vi>> d;
    //vector<vector<vi>> D;
    vector<vi> d;
    vector<vi> C;
    vi f, rf, p2;

    vector<int64> convolve(vector<int64> a, vector <int64> b) {
        vector<int64> res(sz(a), 0);
        for (int i =0 ; i < sz(a); ++i)
            for (int j = 0; j < sz(b) && i + j < sz(res); ++j) {
                res[i + j] = (res[i + j] + a[i] * b[j]) % mod;
            }
        return res;
    }

    void solve(std::istream& in, std::ostream& out) {
	    int n;
	    in >> n >> mod;
//	    d = vector<vector<vi>>(4, vector<vi>(n + 1, vi(n + 1, -1)));
//        D = vector<vector<vi>>(4, vector<vi>(n + 1, vi(n + 1, -1)));
	    C = vector<vi>(n + 1, vi(n + 1, 0));
	    C[0][0] = 1;
	    for (int i = 1; i <= n; ++i) {
	        C[i][0] = 1;
	        for (int j = 1; j <= n; ++j) {
	            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
	        }
	    }


        f = vi(n + 1, 1);
	    rf = vi(n + 1, 1);
        p2 = vi(n + 1, 1);
	    for (int i = 1; i <= n; ++i) {
	        f[i] = (f[i - 1] * (int64) i) % mod;
	        rf[i] = pw(f[i], mod - 2, mod);
	        p2[i] = (p2[i - 1] * 2LL) % mod;
	    }

	    vector<vi> d(n + 1, vi(n + 1, 0));
	    d[0][0] = 1;
	    d[1][1] = 1;
	    for (int i = 2; i <= n; ++i) {
	        d[i][i] = p2[i - 1];
	        for (int k = 1; k < i; ++k) {
                int64 cur = 0;
                for (int j = 1; j < i - 1; ++j) {
                    int l = i - j - 1;
                    if (l > k) continue;
                    int64 val = p2[l - 1];
                    val *= d[j][k - l];
                    val %= mod;
                    val *= C[k][l];
                    val %= mod;
                    cur = (cur + val) % mod;
                }
                d[i][k] = cur;
            }
	    }
	    int64 res = 0;
	    for (int i = 0; i <= n; ++i)
	        res = (res + d[n][i]) % mod;
	    out << res << "\n";

//	    d = vector<vi>(4, vi(n + 1, -1));
//	    int64 res = 0;
//	    for (int i = 0; 2 * i < n; ++i) {
//	        int64 cur = C[n - i - 1][i];
//	        cur *= calc(0, n - i);
//	        cur %= mod;
//	        res = (res + cur) % mod;
//	    }
//	    out << res << "\n";

//        for (int i = 1; i < min(n, 10); ++i) {
//            cerr << i << "\t" << calc(0, i) << "\n";
//        }
//        cerr.flush();


//
//        for (int mask = 3; mask < 4; ++mask) {
//            for (int i = 0; i <= n; ++i) {
//                if (i < 2) {
//                    for (int j = 0; j <= n; ++j) {
//                        d[mask][i][j] = calc(mask, i, j);
//                        int64 val = d[mask][i][j];
//                        val *= rf[j];
//                        val %= mod;
//                        D[mask][i][j] = val;
//                    }
//                    continue;
//                }
//                vector<int64> cur(n + 1, 0);
//                for (int j = 0; j < i; ++j) {
//                    for (int k = 0; k <= n; ++k)
//                        cur[k] = (cur[k] + D[mask][j][k]) % mod;
//                }
//                cur = convolve(cur, cur);
//                calc(mask, i, 0);
//                int64 val = d[mask][i][0];
//                val *= rf[0];
//                val %= mod;
//                D[mask][i][0] = val;
//                for (int j = 1; j <= n; ++j) {
//                    D[mask][i][j] = cur[j - 1];
//                    d[mask][i][j] = (cur[j - 1] * f[j - 1]) % mod;
//                }
//            }
//        }
//
//
//	    int res = 0;
//	    for (int cnt = 0; cnt <= n; ++cnt) {
//	        res += calc(0, n, cnt);
//	        res %= mod;
//	    }
//	    out << res << "\n";
	}

//	int calc(int mask, int n, int k) {
//	    if (k < 0 || n < 0) return 0;
//	    if (n == 0) return k == 0 ? 1 : 0;
//	    if (n == 1) {
//	        if (mask == 3) {
//	            return k == 0 ? 1 : 0;
//	        }
//	        return k == 1 ? 1 : 0;
//	    }
//	    if (k > n) return 0;
//	    if (k == 0) return 0;
//	    if (k * 2 + 1 < n) return 0;
//	    int& res = d[mask][n][k];
//	    if (res != -1) return res;
//	    res = 0;
//	    int ml = mask % 2, mr = (mask >> 1) % 2;
//	    for (int i = 0; i < n; ++i) {
//	        int numL = i, numR = n - i - 1;
//	        // k - cntL - 1 <= numR
//	        // cntL >= k - numR - 1
//	        for (int cntL = max(0, k - numR - 1); cntL < k && cntL <= numL; ++cntL) {
//	            int64 rl = calc(ml + 2, numL, cntL), rr = calc(mr * 2 + 1, numR, k - cntL - 1);
//                int64 cur = rl * rr;
//                cur %= mod;
//                cur *= (int64) C[k - 1][cntL];
//                cur %= mod;
//                res += cur;
//                res %= mod;
//            }
//	    }
//	    //cerr << mask << " " << n << " " << k << ": " << res << "\n";
//	    return res;
//	}

    int calc(int mask, int n) {
        if (n <= 1) return 1;
        int& res = d[mask][n];
        if (res != -1) return res;
        res = 0;
        int ml = mask % 2, mr = (mask >> 1) % 2;
	    for (int i = 0; i < n; ++i) {
	        if (i == 1 && ml) continue;
	        if (i == n - 2 && mr) continue;
            int numL = i, numR = n - i - 1;
            int64 rl = calc(ml + 2, numL), rr = calc(mr * 2 + 1, numR);
            int64 cur = rl * rr;
            cur %= mod;
            cur *= (int64) C[n - 1][i];
            cur %= mod;
            res += cur;
            res %= mod;
        }
	    return res;
    }

	int64 pw(int64 x, int64 y, int64 mod) {
	    int64 res = 1;
	    while (y > 0) {
	        if (y % 2) {
	            --y;
	            res = (res * x) % mod;
	        } else {
	            y /= 2;
	            x = (x * x) % mod;
	        }
	    }
	    return res;
	}
};


int main() {
	TaskE solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}