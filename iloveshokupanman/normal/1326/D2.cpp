#include <iostream>
#include <string>
#include <cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
#include <functional>
#include<complex>
using namespace std;

#define rep(i,x) for(ll i=0;i<x;i++)
#define repn(i,x) for(ll i=1;i<=x;i++)

typedef long long ll;
const ll INF = 1e17;
const ll MOD = 998244353;
const ll MAX = 4000001;
const long double eps = 1E-14;

ll max(ll a, ll b) {
	if (a > b) { return a; }
	return b;
}

ll min(ll a, ll b) {
	if (a > b) { return b; }
	return a;
}

ll gcd(ll a, ll b) {
	if (b == 0) { return a; }
	if (a < b) { return gcd(b, a); }
	return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

struct edge {
	ll ind;
	ll fr;
	ll to;
	ll d;
};

class mint {
	long long x;
public:
	mint(long long x = 0) : x((x% MOD + MOD) % MOD) {}
	mint operator-() const {
		return mint(-x);
	}
	mint& operator+=(const mint& a) {
		if ((x += a.x) >= MOD) x -= MOD;
		return *this;
	}
	mint& operator-=(const mint& a) {
		if ((x += MOD - a.x) >= MOD) x -= MOD;
		return *this;
	}
	mint& operator*=(const  mint& a) {
		(x *= a.x) %= MOD;
		return *this;
	}
	mint operator+(const mint& a) const {
		mint res(*this);
		return res += a;
	}
	mint operator-(const mint& a) const {
		mint res(*this);
		return res -= a;
	}
	mint operator*(const mint& a) const {
		mint res(*this);
		return res *= a;
	}

	mint pow(ll t) const {
		if (!t) return 1;
		mint a = pow(t >> 1);
		a *= a;
		if (t & 1) a *= *this;
		return a;
	}

	// for prime MOD
	mint inv() const {
		return pow(MOD - 2);
	}
	mint& operator/=(const mint& a) {
		return (*this) *= a.inv();
	}
	mint operator/(const mint& a) const {
		mint res(*this);
		return res /= a;
	}

	friend ostream& operator<<(ostream& os, const mint& m) {
		os << m.x;
		return os;
	}
};

mint pw(mint a, ll b) {
	if (b == 0) { return 1; }
	mint ret = pw(a, b >> 1);
	ret *= ret;
	if (b & 1) { ret *= a; }
	return ret;
}

typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<vector<vector<ll>>> vvvll;

typedef vector<mint> vmint;
typedef vector<vector<mint>> vvmint;
typedef vector<vector<vector<mint>>> vvvmint;

//////////////////////////////////////
vector< ll > manacher(const string& s) {
	vector< ll > radius(s.size());
	int i = 0, j = 0;
	while (i < s.size()) {
		while (i - j >= 0 && i + j < s.size() && s[i - j] == s[i + j]) {
			++j;
		}
		radius[i] = j;
		int k = 1;
		while (i - k >= 0 && i + k < s.size() && k + radius[i - k] < j) {
			radius[i + k] = radius[i - k];
			++k;
		}
		i += k;
		j -= k;
	}
	return radius;
}

int main() {
	ll T;
	cin >> T;

	repn(t, T) {
		string S;
		cin >> S;
		ll N = S.size();

		ll c = 0;
		while (S[c]==S[N-1-c]) {
			c++;
			if (c >= N - 1 - c) { cout << S << endl; break; }
		}

		if (c >= N - 1 - c) { continue; }
		

		string T = S.substr(c, N - 2 * c);
		string U;
		U += "$";
		rep(i, T.size()) {
			U += T[i];
			U += "$";
		}

		vll man = manacher(U);
		ll pre = 0;
		rep(i, U.size()) {
			if (man[i] > i) { pre = i; }
		}

		reverse(U.begin(), U.end());
		man = manacher(U);
		ll suf = 0;
		rep(i, U.size()) {
			if (man[i] > i) { suf = i; }
		}

		cout << S.substr(0, c);
		if (pre > suf) {
			cout << S.substr(c, pre);
		}
		else {
			cout << S.substr(N - c - suf, suf);
		}

		cout << S.substr(N - c, c);
		cout << endl;
	}
	
}