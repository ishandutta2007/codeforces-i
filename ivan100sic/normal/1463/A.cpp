// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    ll a, b, c;
    cin >> a >> b >> c;

    ll d = a + b + c;
    bool ok = d % 9 == 0;
    ok &= min({a, b, c}) * 9 >= d;

    cout << (ok ? "YES\n" : "NO\n");
  }
}