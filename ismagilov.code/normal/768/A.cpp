#include <bits/stdc++.h>

#define int long long
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define len(v) ((int)v.size())
#define vc vector
#define pr pair
#define endl "\n"
#define endd ; exit(0)

using namespace std;

const int MAXN = 1e5;
const int INF = 1e9;
const int MOD = 1e9 + 7;

main() {
	//freopen("kek.in", "r", stdin);
	//freopen("kek.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int tek = 2;
	int i, j;
	for (i = 0; i < n - 1 && a[i + 1] == a[0]; i++) {
		tek++;
	}
	for (j = n - 1; j > 0 && a[j - 1] == a[n - 1]; j--) {
		tek++;
	}
	if (tek >= n) {
		cout << 0;
	}
	else {
		cout << n - tek;
	}
}