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

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int& x : a)
			cin >> x;
		int z = 0, y = 2e9;
		for (int i=n-1; i>=0; i--) {
			if (a[i] > y)
				z++;
			y = min(y, a[i]);
		}
		cout << z << '\n';
	}
}