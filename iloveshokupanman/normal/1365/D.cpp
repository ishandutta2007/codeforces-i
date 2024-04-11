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
const ll MOD = 1000000007;
const ll MAX = 4000001;
const double eps = 1E-18;

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

int main() {
	ll T;
	cin >> T;
	repn(t, T) {
		ll N, M;
		cin >> N >> M;

		vector<vector<char>> g(N + 2, vector<char>(M + 2,'?'));
		repn(i, N)repn(j, M) cin >> g[i][j];

		vector<vector<bool>> p(N + 2, vector<bool>(M + 2, 0));

		repn(i, N)repn(j, M) {
			p[i][j] = 1;
			if (g[i][j] == '#') { p[i][j] = 0; }
			if (g[i][j] == 'B') { p[i][j] = 0; }
			if (g[i - 1][j] == 'B') { p[i][j] = 0; }
			if (g[i + 1][j] == 'B') { p[i][j] = 0; }
			if (g[i][j - 1] == 'B') { p[i][j] = 0; }
			if (g[i][j + 1] == 'B') { p[i][j] = 0; }
			//cout <<i<<j<<" "<< p[i][j] << endl;
		}

		vector<vector<bool>> reach(N + 2, vector<bool>(M + 2, 0));

		queue<pair<ll, ll>> q;
		if (p[N][M] != 0) { q.push({ N,M }); reach[N][M] = 1; }
		while (!q.empty()) {
			auto i = q.front().first;
			auto j = q.front().second;
			q.pop();

			//cout << i << j << endl;

			if (p[i + 1][j] == 1&&reach[i+1][j]==0) { q.push({ i + 1,j }); reach[i + 1][j] = 1; }
			if (p[i - 1][j] == 1&&reach[i-1][j]==0) { q.push({ i - 1,j }); reach[i - 1][j] = 1; }
			if (p[i][j - 1] == 1&&reach[i][j-1]==0) { q.push({ i,j - 1 }); reach[i][j - 1] = 1; }
			if (p[i][j + 1] == 1&&reach[i][j+1]==0) { q.push({ i,j + 1 }); reach[i][j + 1] = 1; }

		}

		string ans = "Yes";

		repn(i, N)repn(j, M) {
			if (reach[i][j] == 0 && g[i][j] == 'G') { ans = "No"; }
		}

		cout << ans << endl;


	}
}