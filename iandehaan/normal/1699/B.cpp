#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        rep(i, 0, n) {
            rep(j, 0, m) {
                int iv = (i+1) / 2;
                int jv = (j + 1) / 2;
                cout << (iv+jv) % 2 << ' ';
            }
            cout << '\n';
        }
    }
}