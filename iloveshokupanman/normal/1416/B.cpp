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
#include<cassert>
using namespace std;

#define rep(i,x) for(ll i=0;i<x;i++)
#define repn(i,x) for(ll i=1;i<=x;i++)

typedef long long ll;
const ll INF = 1e17;
const ll MOD = 1000000007;
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

/////////////////////////////////////

int main() {
	ll T;
	cin >> T;

	repn(t, T) {
		ll N;
		cin >> N;

		vll a(N + 1);
		repn(i, N)cin >> a[i];

		ll S = 0;
		repn(i, N)S += a[i];
		if (S % N != 0) { cout << -1 << endl; }
		
		else {

			S = S / N;

			vector<pair<ll, ll>> rem;
			for (ll i = 2; i <= N; i++) {
				ll x = 0;
				if (a[i] % i != 0) { x = i - a[i] % i; }
				rem.push_back({ x,i });
			}
			sort(rem.begin(), rem.end());

			vector<pair<pair<ll, ll>, ll>> ans;

			rep(k, N - 1) {
				auto p = rem[k];
				if (p.first > a[1]) { break; }
				ans.push_back({ { 1,p.second },p.first });
				a[1] -= p.first;
				a[p.second] += p.first;

				ans.push_back({ { p.second,1 }, a[p.second] / p.second });
				a[1] += a[p.second];
				a[p.second] = 0;
			}

			for (ll i = 2; i <= N; i++) {
				if (a[i] == 0) { continue; }
				ans.push_back({ {i,1},a[i] / i });
				a[1] += a[i] / i * i;
				a[i] %= i;
			}

			bool b = 1;
			for (ll i = 2; i <= N; i++) {
				if (a[i] > S) { cout << -1 << endl; b = 0; break; }
				ans.push_back({ {1,i},S - a[i] });
			}

			if (b) {
				cout << ans.size() << endl;

				for (auto p : ans) {
					cout << p.first.first << " " << p.first.second << " " << p.second << endl;
				}
			}
		}

	}
}