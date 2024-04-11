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
typedef long double ld;

vector<int> solve(int l, int n, vector<int> a) {
    vector<ll> sum(n + 1);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i - 1];
    }

    if (sum[n] < l) {
        return vector<int>();
    }
    for (int i = 0; i < n; i++) {
        if (i + a[i] > l) {
            return vector<int>();
        }
    }


    vector<int> ans(n);
    int last = l + 1;

    for (int i = n - 1; i >= 0; i--) {
        ll cur = last - 1;
        cur = min(cur, (ll)l - a[i] + 1);
        cur = min(cur, sum[i] + 1);
        ans[i] = cur;
        last = cur;
    }

    for (int i = 1; i < n; i++) {
        assert(ans[i - 1] < ans[i]);
    }
    assert(ans[0] == 1);
    assert(ans[n - 1] + a[n - 1] - 1 == l);
    for (int i = 1; i < n; i++) {
        assert(ans[i - 1] + a[i - 1] >= ans[i]);
    }

    return ans;
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int l, n;
    while (scanf("%d%d", &l, &n) == 2) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);

        auto ans = solve(l, n, a);
        if (ans.empty()) {
            printf("-1\n");
        } else {
            for (int i = 0; i < n; i++) printf("%d%c", ans[i], " \n"[i + 1 == n]);
        }
    }

    return 0;
}