#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define IS_INF(x)   (std::isinf(x))
#define IS_NAN(x)   (std::isnan(x))
#define fi   first
#define se   second
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x > y + eps) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x + eps < y) {
            x = y;
            return true;
        } else return false;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

/* Author: Van Hanh Pham */

/** END OF TEMPLATE. DRINK A CUP OF TIGERSUGAR BEFORE READING MY CODE. **/

#define MAX   1111
int value[MAX], n;

bool mark[MAX];
int mex(void) {
    memset(mark, false, sizeof mark);
    FOR(i, 1, n) mark[value[i]] = true;
    REP(i, n + 1) if (!mark[i]) return i;
    assert(false);
}

bool ok(void) {
    FOR(i, 1, n - 1) if (value[i] > value[i + 1]) return false;
    return true;
}

void process(void) {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &value[i]);

    int right = n;
    vector<int> res;
    while (!ok()) {
        int v = mex();
        assert(v <= right);
        if (v == right) {
            res.push_back(right);
            value[right] = v;
            right--;
        } else {
            res.push_back(v + 1);
            value[v + 1] = v;
        }
    }

    printf("%d\n", (int)res.size());
    FORE(it, res) printf("%d ", *it); printf("\n");
}

int main(void) {
    int t; scanf("%d", &t);
    REP(love, t) process();
    return 0;
}

/*** BUBBLE TEA IS GREAT. MY CODE IS AMAZING :D ***/