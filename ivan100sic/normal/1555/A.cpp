// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        ll x;
        cin >> x;
        if (x % 2) x++;
        if (x < 6) {
            cout << "15\n";
        } else {
            cout << x/2*5 << '\n';
        }
    }
}