#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
template<class T>
    T Abs(const T &x) {
        return (x<0?-x:x);
    }

/* Author: Van Hanh Pham */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

const int MOD = (int)1e9 + 7;

long long f(long long x) {
    long long res = 1;

    for (int i = 2; 1LL * i * i <= x; i++) if (x % i == 0) {
        res *= i - 1; x /= i;
        while (x % i == 0) {
            res *= i;
            x /= i;
        }
    }

    if (x > 1) res *= x - 1;
    return res;
}

long long g(long long x) {
    return x;
}

long long res(long long n, long long k) {
    if (k % 2 == 0) k--;

    while (k > 0 && n > 1) {
        n = f(n);
        k -= 2;
    }
    return n;
}

int main(void) {
    long long n, k; cin >> n >> k;
    cout << res(n, k) % MOD << endl;
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/