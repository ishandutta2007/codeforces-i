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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        sort(begin(a), end(a));

        ll z = 0;
        for (int i=1; i<n; i++) {
            ll c;            
            if (i == n - 1) {
                c = 2 - n;
            } else {
                c = n - 1 - 2*i;
            }
            z += c * a[i];
        }

        cout << z << '\n';
    }
}