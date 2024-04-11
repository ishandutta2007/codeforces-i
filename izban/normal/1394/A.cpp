#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
#include <random>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
clock_t __my_start_clock = clock();
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", (clock() - __my_start_clock)*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, (clock() - __my_start_clock)*1.0/CLOCKS_PER_SEC)

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << " = "; for (auto xxxx: a) cerr << xxxx << " "; cerr << endl


using namespace std;

#ifdef LOCAL
static struct __timestamper {
    string what;
    __timestamper(const char* what) : what(what){};
    __timestamper(const string& what) : what(what){};
    ~__timestamper(){
        TIMESTAMPf("%s", what.data());
    }
} __TIMESTAMPER("end");
#else
struct __timestamper {};
#endif

typedef long long ll;
typedef long double dbl;

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int n, d, m;
    while (scanf("%d%d%d", &n, &d, &m) == 3) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);

        sort(a.begin(), a.end());

        int t = upper_bound(a.begin(), a.end(), m) - a.begin();

        vector<ll> sum(n + 1);
        for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i - 1];

        ll ans = 0;

        ll cur = 0;
        for (int cnt = 0; cnt <= n - t; cnt++) {
            ll blocked = cnt;
            blocked += 1LL * (cnt - 1) * d;
            ll small = n - blocked;

            if (blocked <= n) {
                ll cans = 0;
                cans += cur;
                cans += sum[t] - (small <= t ? sum[t - small] : 0);
                ans = max(ans, cans);
            }

            if (cnt < n) {
                cur += a[n - 1 - cnt];
            }
        }

        printf("%lld\n", ans);
    }

    return 0;
}