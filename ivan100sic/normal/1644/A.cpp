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
        string s, a = "YES\n";
        cin >> s;
        set<char> k;
        for (char c : s) {
            if (islower(c)) {
                k.insert(c);
            } else {
                if (!k.contains(tolower(c))) {
                    a = "NO\n";
                }
            }
        }
        cout << a;
    }
}