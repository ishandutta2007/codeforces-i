#include <bits/stdc++.h>

using namespace std;
#define DIM 100007
#define DIM2 107
#define INF 10E10
#define MAXN 2750137
#define LG 18
#define MODULO 998244353
#define fi first
#define sc second
#define pb push_back
#define pu push
#define sz size()
#define po(power) ( 1<<power)
#define schnell ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"

typedef long long ll;
typedef long double ld;

const ld eps = 0.00000001;
const ll MASK(1 << 10);

typedef pair<ll, ll> pll;
typedef ll arr[DIM];
typedef ll msk[MASK + 7];
typedef vector<ll> vec;
typedef vector<ll> graph[DIM];
typedef pll parr[DIM];
typedef ll table[DIM][DIM2];
typedef ll arr2[DIM2];
typedef pair<string, string> ps;
#define forn(i,n) for (ll i = 1;i<=n;i++)
#define fore(y,i,n) for (ll i = y;i<=n;i++)

ll n,pref[DIM],q;
int main()
{
	schnell;
	cin >> n;
	forn(i, n) {
		ll x;
		cin >> x;
		pref[i] = pref[i - 1] + x;
	}
	cin >> q;
	forn(h, q) {
		ll L, R; cin >> L >> R;
		cout << (pref[R] - pref[L - 1]) / 10 << endl;
	}
	return 0;
}