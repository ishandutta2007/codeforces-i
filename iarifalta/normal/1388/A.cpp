
/*
    Im not gonna run away, I never go back on my word! Thats my nindo: my ninja way. Naruto
























































*/

#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second 
#define mp make_pair
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define speed_up ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define sz(x) (int)x.size()
#define szc(x) (int)strlen(x)
#define all(x) x.begin(), x.end()
#define debug cerr << "OK\n";
#define ub upper_bound
#define lb lower_bound 
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef set <int> si;
typedef set <ll> sll;
typedef multiset <int> msi;
typedef multiset <ll> msll;
typedef map <int, int> mi;
typedef map <ll, int> mll;
 
const int N = 1e5 + 2;
const int M = 2e6 + 2;
const int mod = 998244353;
const int inf = 2e9 + 3;
const ll INF = 1e16;

/*
	BIN POISK EBANA V ROT
	DP EBANA V ROT
	DO EBANA V ROT
*/

int T, n;

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		if (n > 30) {
			if (n == 36)
				printf("YES\n5 6 10 15\n");
			else if (n == 40)
				printf("YES\n6 3 10 21\n");
			else if (n == 44) 
				printf("YES\n6 7 10 21\n");
			else	
				printf("YES\n%d %d %d %d\n", 6, 10, 14, n - 6 - 10 - 14);
		}
		else {
			printf("NO\n");
		}
	}
}

/*
	Timus: 288481RF
	CodeForces: fractal
*/