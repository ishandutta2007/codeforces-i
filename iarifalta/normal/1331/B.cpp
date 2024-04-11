#include <bits/stdc++.h>
using namespace std;
 
#define F first
#define S second 
#define mp make_pair
#define pb push_back
#define pf push_front
#define speed_up ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define debug cerr << "OK\n";
#define ub upper_bound
#define lb lower_bound
#define treap_pair pair<treap*, treap*>
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef set <int> si;
typedef set <ll> sll;
typedef multiset <int> msi;
typedef multiset <ll> msll;
typedef map <int, int> mi;
typedef map <ll, int> mll;
 
const int N = 2e5 + 2;
const int M = 1e5 + 2;
const int mod = 998244353;
const int inf = 1e9;
const ll INF = 1e16;

void data() {
	#ifdef PC
		freopen("b.in", "r", stdin);
		freopen("b.out", "w", stdout);
	#endif
}

int x;

int main() {
	data();
	scanf("%d", &x);
	for (int i = 1; i * i <= x; ++i) {
		if (x % i == 0) {
			bool f1 = 1, f2 = 1;
			for (int j = 2; j * j <= i; ++j) {
				if (i % j == 0)
					f1 = 0;
			}
			for (int j = 2; j * j <= x / i; ++j) {
				if ((x / i) % j == 0)
					f2 = 0;
			}
			if (f1 && f2) {
				printf("%d%d", i, x / i);
			}
		}
	}
}

/*
	Timus: 288481RF
	CodeForces: fractal
*/