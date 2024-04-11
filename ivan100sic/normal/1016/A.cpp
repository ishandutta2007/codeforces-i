#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, m;
	cin >> n >> m;
	ll z = 0;
	for (int i=1; i<=n; i++) {
		ll x;
		cin >> x;
		cout << (z+x)/m - z/m << ' ';
		z += x;
	}
}