#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
#define DIM 200007
#define DIM2 DIM*150
#define MODULO 998244353 
#define MAXN 1000000
#define MS 302
#define BigNumSize 250
#define AddLimit 151
const ll INF = 10E16;
const ll mask = po(9) - 1;
const ll base = 100000000000;
const ld eps = 0.0000001;
struct pp {
	ll fi, sc;
	bool const operator < (const pp& b) {
		if (fi == b.fi)return sc < b.sc;
		return fi < b.fi;
	}
	bool const operator > (const pp& b) {
		if (fi == b.fi)return sc > b.sc;
		return fi > b.fi;
	}
	bool const operator == (const pp& b) {
		if (fi == b.fi && sc == b.sc)return 1;
		return 0;
	}
};
bool const operator<(const pp& a, const pp& b) {
	if (a.fi == b.fi)return a.sc < b.sc;
	return a.fi < b.fi;
}
ll R[DIM],A[DIM];
ll n, k,N[DIM];
int main() {
	schnell;
	cin >> n >> k;
	for (ll i = 1; i <= n; i++) {
		cin >> A[i];
	}
	sort(A + 1, A + 1 + n);
	for (ll i = 1; i <= n; i++) {
		ll r = 0;
		while (A[i] >= 0) {
			if (N[A[i]] < k) {
				N[A[i]]++;
				R[A[i]] += r;
			}
			if (A[i] == 0)break;
			A[i] /= 2;
			r++;
		}
	}
	ll res = INF;
	for (ll i = 0; i < DIM; i++) {
		if (N[i]>=k)
		res = min(res, R[i]);
	}
	cout << res << endl;
	return 0;
}