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
        vector<int> a(n);
        for (int& x : a) cin >> x;
        int h = 0, c = 0;
        for (int x : R::reverse_view(a)) {
            if (x > h) {
                h = x;
                c++;
            }
        }

        cout << c-1 << '\n';
    }
    
}