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

const int MOD = 1'000'000'007;
typedef modint<MOD> mint;

struct linfunc {
	mint a, b;

	linfunc() : a(1), b(0) {}

	linfunc operator* (linfunc o) const {
		linfunc tmp;
		tmp.b = b + a * o.b;
		tmp.a = a * o.a;
		return tmp;
	}
};

template<class T>
T pw(T x, ll y) {
	if (y == 0)
		return T();
	if (y == 1)
		return x;

	T z = pw(x, y >> 1);
	z = z * z;
	if (y & 1)
		z = z * x;
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll a, b, n, x;
	cin >> a >> b >> n >> x;
	linfunc f;
	f.a = a;
	f.b = b;
	auto g = pw(f, n);
	cout << (int)(g.a * x + g.b) << '\n';
}