#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long  ll;
typedef long double ld;
#define DIM 200007
#define DIM2 10007
#define MODULO 1000000007  
#define MAXN 1000000
#define MS 302
#define BigNumSize 250
#define AddLimit 151
const long long INF = 10E16;
const ll mask = po(9) - 1;
const ll base = 100000000000;
const ld eps = 0.0000001;
struct pp {
	ld fi, sc;
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
string s, t;
ll pref[DIM], suf[DIM];
int main() {
	schnell;
	cin >> s >> t;
	ll pos = 0;
	for (ll i = 0; i < s.length(); i++) {
		if (pos >= t.length())break;
		if (s[i] == t[pos]){
			pref[pos] = i; pos++;
		}
	}
	pos = t.length() - 1;
	for (ll i = s.length() - 1; i >= 0; i--) {
		if (pos < 0)break;
		if (s[i] == t[pos]) {
			suf[pos] = i;
			pos--;
		}
	}
	ll res = max(s.length()-pref[t.length()-1]-1,suf[0]);
	for (ll i = 0; i < t.length()-1; i++) {
		res = max(res, suf[i + 1] - pref[i]-1);
	}
	cout << res << endl;
	return 0;
}