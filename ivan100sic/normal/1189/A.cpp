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
	if (count(s.begin(), s.end(), '0')*2 == n) {
		cout << "2\n" << s[0] << ' ' << s.substr(1) << '\n';
	} else {
		cout << "1\n" << s << '\n';
	}
}