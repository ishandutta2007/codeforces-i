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
        int n, m;
        cin >> n >> m;
        if ((n == 1 && m >= 3) || (m == 1 && n >= 3)) {
            cout << "-1\n";
            continue;
        }

        n--;
        m--;

        cout << n + m + abs(n-m)/2*2 << '\n';
    }
}