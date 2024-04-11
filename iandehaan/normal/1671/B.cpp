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
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        a[0]++;
        string out = "YES";
        for (int i = 1; i < n; i++) {
            if (a[i] == a[i-1]) a[i]++;
            if (a[i] > a[i-1]+1) a[i]--;
            if (a[i] > a[i-1]+1) out = "NO";
        }
        cout << out << endl;
    }
}