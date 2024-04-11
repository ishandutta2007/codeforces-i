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

	int n;
	string s;
	cin >> n >> s;
	for (int i=0; i<n-1; i++) {
		if (s[i] != s[i+1]) {
			cout << "YES\n" << s[i] << s[i+1] << '\n';
			return 0;
		}
	}
	cout << "NO\n";
}