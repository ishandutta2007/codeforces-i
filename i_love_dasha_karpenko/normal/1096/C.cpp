#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
#define DIM 200007
#define DIM2 10007
#define MODULO 998244353  
#define MAXN 1000000
#define DIM2 31
const long long INF = 10E16;
const ll mask = po(9) - 1;
const ll base = 100000000000;
struct pp {
	ll fi, sc;
	bool operator < (const pp& b)const {
		if (fi == b.fi)return sc < b.sc;
		return fi < b.fi;
	}
	bool operator > (const pp& b)const {
		if (fi == b.fi)return sc > b.sc;
		return fi > b.fi;
	}
	bool operator == (const pp& b)const {
		if (fi == b.fi && sc == b.sc)return 1;
		return 0;
	}
};
ll t, n;
ll __gcd(ll x,ll y) {
	if (x < y)swap(x, y);
	while (y > 0) {
		x %= y;
		swap(x, y);
	}
	return x;
}
int main() {
	schnell;
	cin >> t;
	forn(h, t) {
		cin >> n;
		if (n == 180) {
			cout << -1 << endl;
			continue;
		}
		ll g = __gcd(n, 180);
		if (180 - n == g) {
			cout << 360 / g << endl;
		}
		else {
			cout << 180 / g << endl;
		}
	}
	return 0;
}