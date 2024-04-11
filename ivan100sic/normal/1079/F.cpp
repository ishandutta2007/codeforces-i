#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<int m>
struct modint {

	unsigned x;

	modint() : x(0) {}

	modint(long long arg) {
		arg %= m;
		if (arg < 0) {
			x = arg + m;
		} else {
			x = arg;
		}
	}	

	modint& operator+= (const modint& other) {
		x += other.x;
		if (x >= m) {
			x -= m;
		}
		return *this;
	}

	modint& operator*= (const modint& other) {
		x = (x * 1ll * other.x) % m;
		return *this;
	}

	modint& operator-= (const modint& other) {
		x += m - other.x;
		if (x >= m) {
			x -= m;
		}
		return *this;
	}

	modint operator+ (const modint& other) const {
		modint tmp = *this;
		tmp += other;
		return tmp;
	}

	modint operator- (const modint& other) const {
		modint tmp = *this;
		tmp -= other;
		return tmp;
	}

	modint operator* (const modint& other) const {
		modint tmp = *this;
		tmp *= other;
		return tmp;
	}

	explicit operator int () const {
		return x;
	}

	modint& operator++ () {
		++x;
		if (x == m) {
			x = 0;
		}
		return *this;
	}

	modint& operator-- () {
		if (x == 0) {
			x = m-1;
		} else {
			--x;
		}
		return *this;
	}

	modint operator++ (int) {
		modint tmp = *this;
		++*this;
		return tmp;
	}

	modint operator-- (int) {
		modint tmp = *this;
		--*this;
		return tmp;
	}

	bool operator== (const modint& other) const {
		return x == other.x;
	}

	bool operator!= (const modint& other) const {
		return x != other.x;
	}

	template<class T>
	modint operator^ (T arg) const {
		if (arg == 0) {
			return 1;
		}
		if (arg == 1) {
			return x;
		}
		auto t = *this ^ (arg >> 1);
		t *= t;
		if (arg & 1) {
			t *= *this;
		}
		return t;
	}

	modint inv() const {
		return *this ^ (m-2);
	}
};

const int MOD = 998244353;
typedef modint<MOD> mint;

int n;
basic_string<int> e[300005];
mint un[300005], gore[300005], dole[300005];

void dfs1(int x, int p) {
	un[x] = 1;
	gore[x] = 1;

	basic_string<mint> z, z_pref, z_suff, gore1;

	for (int y : e[x]) {
		if (y == p)
			continue;
		dfs1(y, x);
		un[x] *= dole[y] + un[y];
		gore[x] *= dole[y] * 2 + un[y]; 
		// dole
		z += un[y] + dole[y] * 2;
		gore1 += gore[y];
	}

	z_pref = z;
	z_suff = z;
	int m = z.size();
	if (m > 0) {
		z_pref[0] = 1;
		for (int i=0; i<m-1; i++)
			z_pref[i+1] = z_pref[i] * z[i];
		z_suff[m-1] = 1;
		for (int i=m-1; i>0; i--)
			z_suff[i-1] = z_suff[i] * z[i];
		for (int i=0; i<m; i++)
			dole[x] += gore1[i] * z_pref[i] * z_suff[i];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}

	dfs1(1, 1);
	cout << (int)(dole[1] + un[1]) << '\n';
}