#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
#include <stack>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
#define DIM 100007
#define DIM2 10007
#define MODULO 998244353 
#define MAXN 1000000
const ll INF = 10E16;
const ll mask = po(9) - 1;
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
ll n, m,V[DIM];
vector<ll> A[DIM];
priority_queue<ll, vector<ll>, greater<ll> > Q;
void bfs(ll x) {
	Q.push(x);
	V[x] = 1;
	while (!Q.empty()) {
		x = Q.top(); Q.pop();
		cout << x << ' ';
		for (ll to : A[x]) {
			if (V[to] == 0) {
				V[to] = 1;
				Q.push(to);
			}
		}
	}
}
int main() {
	schnell;
	cin >> n>>m;
	forn(i, m) {
		ll x, y; cin >> x >> y;
		A[x].pb(y);
		A[y].pb(x);
	}
	bfs(1);
	
	cout << endl;
	return 0;
}