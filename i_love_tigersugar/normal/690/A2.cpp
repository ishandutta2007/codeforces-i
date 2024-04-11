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
int solve(int n) {
    if (n==1) return (0);
    if (n==2) return (0);
    if (n==3) return (1);
    if (n==4) return (0);
    if (n==99) return (49);
    if (n%2==1) return ((n+n%2)/2-1);
    if (n==6) return (n/2-2);
    if (n==8) return (0);
//    if (n==10) return (1);
//    if (n==12) return (2);
//    if (n==14) return (3);
//    if (n==16) return (0);
//    if (n==18) return (1);
//    if (n==20) return (2);
    int tmp=1;
    while (tmp*2<=n) tmp*=2;
    return ((n-tmp)/2);
}
int main(void) {
    int n; cin>>n;
    cout<<solve(n)<<endl;
    return 0;
}