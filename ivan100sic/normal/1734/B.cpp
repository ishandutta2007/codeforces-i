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
        for (int i : ra(1, n+1)) {
            for (int j : ra(0, i)) {
                cout << (j == 0 || j == i-1) << " \n"[j == i-1];
            }
        }
    }
}