#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int&v : a) cin >> v;
    vector<int> sorted = a;
    sort(sorted.begin(), sorted.end());
    int mi = sorted[0];
    int ok = 1;
    for (int i = 0; i < n; i++) {
      if (a[i]%mi && a[i] != sorted[i]) ok = 0;
    }
    cout << (ok ? "YES" : "NO") << endl;
  }
}