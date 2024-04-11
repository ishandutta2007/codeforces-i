#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int v[1005];
basic_string<int> e[1005];

void dfs(int x) {
	v[x] = 1;
	for (int y : e[x])
		if (!v[y])
			dfs(y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}
	dfs(1);
	if (count(v+1, v+n+1, 1) == n && m == n-1) {
		cout << "yes\n";
	} else {
		cout << "no\n";
	}
}