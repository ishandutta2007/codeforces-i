#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;

int main(){
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  if (n % 2 == 1){cout << n/2 << endl; return 0;}
  n /= 2;
  int p = 1;
  while (p <= n) p *= 2; p /= 2;
  cout << n-p << endl;

  return 0;
}