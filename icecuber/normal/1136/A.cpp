#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int,int>> v(n);
  for (auto&p : v)
    cin >> p.first >> p.second;
  int k;
  cin >> k;
  int ans = 0;
  for (auto&p : v) {
    if (k <= p.second) ans++;
  }
  cout << ans << endl;
}