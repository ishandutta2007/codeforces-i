// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=1; i<=n; i++) {
            if (i == 1 && n % 2 == 1) {
                cout << "1 ";
            } else if ((n-i) % 2 == 0) {
                cout << i-1 << ' ';
            } else {
                cout << i+1 << ' ';
            }
        }
        cout << '\n';
    }
}