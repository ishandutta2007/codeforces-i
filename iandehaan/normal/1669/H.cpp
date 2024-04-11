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
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int needed[31];
        for (int ind = 0; ind < 31; ind++) {
            needed[ind] = 0;
            for (int i = 0; i < n; i++) {
                if ((a[i] & (1 << ind)) == 0) needed[ind]++;
            }
        }
        int out = 0;
        for (int ind = 30; ind >= 0; ind--) {
            if (needed[ind] <= k) {
                k -= needed[ind];
                out |= (1 << ind);
            }
        }
        cout << out << endl;
    }
}