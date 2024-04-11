#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef complex<double> P;
static const double EPS = 1e-8;
static const int INF = (int)1e8;

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) for (int i=0; i<(int)(n); ++i)
#define FOREQ(i,k,n) for (int i=(k); i<=(int)(n); ++i)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define FIND(m,w) ((m).find(w)!=(m).end())

int main(void){
  int n,m,a,b;
  cin>>n>>m>>a>>b;
  int diff = (b-1)/m - (a-1)/m;
  bool fst = (((a-1)%m)==0);
  bool lst = (((b-1)%m)==m-1);
  bool ajst = ((a-1)%m - (b-1)%m) == 1;
  if(b==n)lst = true;
  int ans = 1;
  if(diff==0)ans = 1;
  else if(diff==1){
    if(fst&&lst)ans = 1;
    else ans = 2;
  }else{
    if(fst&&lst)ans = 1;
    else if(fst||lst) ans = 2;
    else if(ajst) ans = 2;
    else ans = 3;
  }
  cout<<ans<<endl;

  return 0;
}