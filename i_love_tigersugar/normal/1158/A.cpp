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

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

#define MAX   100100
int minRow[MAX], maxCol[MAX], numRow, numCol;

long long process(void) {
    scanf("%d%d", &numRow, &numCol);
    FOR(i, 1, numRow) scanf("%d", &minRow[i]);
    FOR(i, 1, numCol) scanf("%d", &maxCol[i]);

    sort(minRow + 1, minRow + numRow + 1);
    sort(maxCol + 1, maxCol + numCol + 1);

    if (minRow[numRow] > maxCol[1]) return -1;

    long long sum = 0;
    FOR(i, 1, numRow) sum += 1LL * numCol * minRow[i];
    FOR(j, 1, numCol) sum += maxCol[j] - minRow[numRow];
    if (maxCol[1] > minRow[numRow]) sum += minRow[numRow] - minRow[numRow - 1];
    return sum;
}

int main(void) {
    cout << process() << endl;
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/