#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct edge {
	int u, v, w, id, used;

	bool operator< (const edge& b) const {
		return w < b.w;
	}
};

struct dsu {
	vector<int> p;

	dsu(int n) : p(n) {
		iota(p.begin(), p.end(), 0);
	}

	int e(int x) {
		if (x == p[x])
			return x;
		return p[x] = e(p[x]);
	}

	bool spoji(int x, int y) {
		x = e(x);
		y = e(y);
		if (x == y)
			return false;
		p[x] = y;
		return true;
	}
};

int n, m;
edge f[1000005];
edge g[1000005];

void mst() {
	copy(f, f+m, g);
	sort(g, g+m);
	dsu d(n+1);
	for (int i=0; i<m; i++)
		g[i].used = d.spoji(g[i].u, g[i].v);
}

vector<pair<int, int>> e[100005];

int p[20][100005];
int q[20][100005];
int d[100005];

void dfs(int x, int par, int w) {
	p[0][x] = par;
	q[0][x] = w;
	for (int i=1; i<20; i++) {
		int y = p[i-1][x];
		p[i][x] = p[i-1][y];
		q[i][x] = max(q[i-1][x], q[i-1][y]);
	}
	for (auto [y, ww] : e[x]) {
		if (y == par)
			continue;
		d[y] = d[x] + 1;
		dfs(y, x, ww);
	}
}

int dizi(int& x, int y) {
	int z = 0;
	for (int i=0; i<20; i++) {
		if (y & (1 << i)) {
			z = max(z, q[i][x]);
			x = p[i][x];
		}
	}
	return z;
}

int maxpath(int u, int v) {
	if (d[u] < d[v])
		swap(u, v);
	int z = dizi(u, d[u] - d[v]);
	if (u == v)
		return z;
	for (int i=19; i>=0; i--) {
		int uu = p[i][u];
		int vv = p[i][v];
		if (uu != vv) {
			z = max({z, q[i][u], q[i][v]});
			u = uu;
			v = vv;
		}
	}
	return max({z, q[0][u], q[0][v]});
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		cin >> f[i].u >> f[i].v >> f[i].w;
		f[i].id = i;
	}

	mst();

	for (int i=0; i<m; i++) {
		if (g[i].used) {
			int j = g[i].id;
			f[j].used = 1;
			e[f[j].u].emplace_back(f[j].v, f[j].w);
			e[f[j].v].emplace_back(f[j].u, f[j].w);
		}
	}

	dfs(1, 1, 0);

	for (int i=0; i<m; i++) {
		if (!f[i].used) {
			cout << maxpath(f[i].u, f[i].v) << '\n';
		}
	}
}