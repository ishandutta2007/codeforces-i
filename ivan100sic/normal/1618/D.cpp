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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int& x : a) cin >> x;
        R::sort(a);

        int sol = accumulate(a.begin(), a.end() - 2*k, 0);
        for (int i : ra(0, k)) {
            int b = n-2*k+i;
            sol += a[b] / a[b+k];
        }

        cout << sol << '\n';
    }
    
}