#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, m, k, l;
  cin >> n >> m >> k >> l;
  ll x = (k+l+m-1)/m;
  if (x*m > n) cout << -1 << endl;
  else cout << x << endl;
}