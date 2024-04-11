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
 
namespace io {
	const int __SIZE = (1 << 21) + 1;
	char ibuf[__SIZE], *iS, *iT, obuf[__SIZE], *oS = obuf, *oT = oS + __SIZE - 1, __c, qu[55]; int __f, qr, _eof;
	#define Gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, __SIZE, stdin), (iS == iT ? EOF : *iS++)) : *iS++)
	inline void flush () { fwrite (obuf, 1, oS - obuf, stdout), oS = obuf; }
	inline void gc (char &x) { x = Gc(); }
	inline void pc (char x) { *oS ++ = x; if (oS == oT) flush (); }
	inline void pstr (const char *s) {int __len = strlen(s); for (__f = 0; __f < __len; ++__f) pc (s[__f]); }
	inline void gstr (char *s) {  for(__c = Gc(); __c < 32 || __c > 126 || __c == ' ';)  __c = Gc();
		for(; __c > 31 && __c < 127 && __c != ' '; ++s, __c = Gc()) *s = __c; *s = 0;}
	template <class I> inline bool gi (I &x) { _eof = 0;
		for (__f = 1, __c = Gc(); (__c < '0' || __c > '9') && !_eof; __c = Gc()) { if (__c == '-') __f = -1; _eof |= __c == EOF; }
		for (x = 0; __c <= '9' && __c >= '0' && !_eof; __c = Gc()) x = x * 10 + (__c & 15), _eof |= __c == EOF; x *= __f; return !_eof; }
	template <class I> inline void gp (I x) { if (!x) pc ('0'); if (x < 0) pc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10; while (qr) pc (qu[qr --]); }
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
} using io::pc; using io::gc; using io::pstr; using io::gstr; using io::gi; using io::gp;
 
void scan() {
	return;
}
 
template<class T, typename... Args>
void scan(T &a, Args&&... args) {
	gi(a);
	scan(args...);
	return;
}
 
template<typename T>
void scerr(T a, T b) {
	for (auto it = a; it != b; ++it)
		cerr << *it << " ";
	cerr << '\n';
}

void print() {
	pc('\n');
	return;
}
 
template<class T, typename... Args>
void print(T a, Args... args) {
	gp(a);
	pc(' ');
	print(args...);
	return;
}
 
void cer() {
	return;
}
 
template<class T, typename... Args>
void cer(T a, Args... args) {
	cerr << a << " ";
	cer(args...);
	return;
}
 
 
typedef long long ll;
typedef long double ld;
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
 
const int N = 1e5 + 2;
const int M = 4e6 + 2;
const int mod = 998244353;
const int inf = 2e9 + 3;
const ll INF = 1e15;

void data() {
	#ifdef PC
		freopen("e.in", "r", stdin);
		freopen("e.out", "w", stdout);
	#endif
}

string s, t;
ll dp[3001][3001], n, m, ans;

void add(ll &a, ll b) {
	a += b;
	if (a >= mod)
		a -= mod;
}

int main() {
	data();
	cin >> s >> t;
	n = sz(s);
	m = sz(t);
	s = '!' + s;
	t = '@' + t;
	cerr << s << ' ' << t;
	for(int i = m; i <= n; i++) {
        if(i > m || s[i] == t[m])
            dp[i][0] = 1;
        if(s[i] == t[1])
            dp[i][1] = 1;
    }
	for (int i = n; i > 1; --i) {
		for (int j = 0; j <= n - i + 1; ++j) {
			if (j + 1 > m || s[i - 1] == t[j + 1])
				add(dp[i - 1][j + 1], dp[i][j]);
			if (i + j - 1 > m || s[i - 1] == t[i + j - 1])
				add(dp[i - 1][j], dp[i][j]);	
		}
	}
	for (int i = 0; i <= n; ++i) {
		add(ans, dp[1][i]);
	}
	print(ans);
}	

/*
	Timus: 288481RF
	CodeForces: fractal
*/