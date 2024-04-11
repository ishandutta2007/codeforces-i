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

class DisjointSet {
    private:
    vector<int> label; //label[x] stores the root of x if x is not root, otherwise it stores -(size of x's set).
    public:
    DisjointSet(){}
    DisjointSet(int n) {
        label.assign(n+7,-1); //label should contains at least n+1 elements, as x is 1-indexed.
        //At first, each node is a seperate set of size 1.      
    }
    int find(int x) { //find the root of set which contains x.
        if (label[x]<0) return (x); //x is root iff label[x] is negative.
        label[x]=find(label[x]);
        return (label[x]); //find the root of x by recursion.
    }
    bool join(int a,int b) { // join the sets which contains a and b. Return false iff a and b are already in the same set.
        int x=find(a);
        int y=find(b);
        if (x==y) return (false); //A set contains both a and b.
        if (label[x]>label[y]) swap(x,y); //label[x]>label[y] means size(x)<size(y).
        //We speed up the disjoint set by joinning the smaller set to the bigger set        
        label[x]+=label[y];
        label[y]=x; //Update the label of x and y.      
        return (true);
    }
    int getSize(int x) { //return the size of set which contains x.
        return (-label[find(x)]);
    }
};

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

void process(void) {
  int numNode, numEdge; scanf("%d%d", &numNode, &numEdge);
  DisjointSet dsu(numNode);

  int circleEdge = 0;
  REP(love, numEdge) {
    int u, v; scanf("%d%d", &u, &v);
    if (!dsu.join(u, v)) circleEdge++;
  }

  cout << circleEdge << endl;
}

int main(void) {
  process();
  return 0;
}
/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/