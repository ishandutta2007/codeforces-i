#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())
#define print(x) cout << x
#define println(x) cout << x << endl

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll MOD998 = 998244353;

typedef unsigned int uint;
typedef unsigned long long ull;


int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int ans = 0;
	int x;
	cin >> x;
	int k = 60 * 4 - x;
	for (int i = 1; i <= n; i++) {
        if (5 * i <= k) {
            ans++;
            k -= 5 * i;
        }
	}
	cout << ans;
	return 0;
}