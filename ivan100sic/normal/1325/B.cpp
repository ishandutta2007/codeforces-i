// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
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
		set<int> s;
		copy_n(istream_iterator<int>(cin), *istream_iterator<int>(cin), inserter(s, s.begin()));
		cout << s.size() << '\n';
	}
}

// I will still practice daily...