#include <bits/stdc++.h>

using namespace std;
#define DIM  200007
#define DIM2 107
#define INF 10E16
#define MAXN 2750137
#define LG 18
#define MODULO 1000000007

typedef long long ll;
const ll MASK(1 << 10);

typedef long double ld;
const ld eps = 0.00000001;
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
#define fi first
#define sc second
#define pb push_back
#define pu push
#define sz size()
#define po(power) ( 1<<power)
#define schnell ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"
ll n;
ll A[DIM],V[DIM];
int main()
{
	
	schnell;
	cin >> n;
	ll sum = 0;
	forn(i, n) {
		ld x; cin >> x;
		A[i] = floor(x);
		sum += A[i];
		if (abs(A[i] - x) < eps)V[i] = 1;
	}
	ll i = 1;
	while (sum < 0) {
		if (V[i] == 0) {
			A[i]++;
			sum++;
		}
		i++;
	}
	forn(i, n)cout << A[i] << endl;
}