#include <bits/stdc++.h>
#define F first
//#define S second
#define dq deque
#define vc vector
#define INF (0x3f3f3f3f)
#define LINF ((long long)(0x3f3f3f3f3f3f3f3f))
#define Pb push_back
#define Mp make_pair
#define ll long long
#define _tp template
#define _tyn typename
#define Pf push_front
#define itor iterator
#define sint short int
#define ull unsigned ll
#define pii pair<int,int>
#define uint unsigned int
#define All(x) x.begin(),x.end()
#define B cout << "BreakPoint" << endl;
#define Fin(a) freopen(a,"r",stdin)
#define Fout(a) freopen(a,"w",stdout)
#define Ms(_data) memset(_data,0,sizeof(_data))
#define Msn(_data,_num) memset(_data,_num,sizeof(_data))
#define Fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define O_(x) cout << #x << " " << x << "  ";
#define O(x) cout << #x << " " << x << endl;
using namespace std;
#define Mymax(a,b) if(a<b) a = b;
#define Mymin(a,b) if(a>b) a = b;
void Print(int _x){printf("%d\n",_x);}
void Print(ll _x){printf("%lld\n",_x);}
_tp<_tyn T>void Print( T _a[] , int _s , int _t ){
	for( int i = _s ; i <= _t ; i++ )
		cout << _a[i] << " ";
   	cout << endl;
}
#define il inline
#define rg register
struct InputReader{
	static const int bs = 100000;
	char buf[bs];
	int p;
	il InputReader():p(bs) {}
	il void Flush(){
		p = 0;
		fread(buf, 1, bs, stdin);
	}
	il char C(){
		if(p >= bs) Flush();
		return buf[p++];
	}
	int Getnum(){
		char ch = C();
		while( ch < '0'  ||  ch > '9' ) ch = C();
		return (int)(ch-'0');
	}
	il int operator() (){
		int ans = 0;
		char ch = C();
		int fu = 1;
		while( ch < '0'  ||  ch > '9' ){
			if( ch == '-' ) fu = -1;
			ch = C();
		}
		while( ch >= '0'  &&  ch <= '9' ){
			ans *= 10;
			ans += ch-'0';
			ch = C();
		}
		return ans * fu;
	}
	ll Readll(){
		ll ans = 0LL;
		ll fu = 1;
		char ch = C();
		while( ch < '0'  ||  ch > '9' ){
			if( ch == '-' ) fu = -1;
			ch = C();
		}
		while( ch >= '0'  &&  ch <= '9' ){
			ans *= 10LL;
			ans += ch-'0';
			ch = C();
		}
		return ans * fu;
	}
	il void Readstring( string &x ){
		x.clear();
		char ch = C();
		while( !isdigit(ch)  &&  !isalpha(ch) ) ch = C();
		while( isdigit(ch)  ||  isalpha(ch) ){
			x += ch;
			ch = C();
		}
	}
	il void Readalpha( char &c ){
		c = C();
		while( !isalpha(c) ) c = C();
	}
	il void Specialread( char &c ){
		c = C();
		while( c != 'o'  &&  c != 'x'  &&  c != '?' ) c = C();
	}
}In;
il void Read( int &x ){ x = In(); }
il void Read( int &x, int &y ){ x = In(); y = In(); }
il void Read( int &x1 , int &x2 , int &x3 ){
	x1 = In(); x2 = In(); x3 = In();
}
il void Read( int &x1 , int &x2 , int &x3 , int &x4 ){
	x1 = In(); x2 = In(); x3 = In(); x4 = In();
}
il void Read( ll &x ){ x = In.Readll(); }
il void Read( ll &x, ll &y ){ x = In.Readll(); y = In.Readll(); }
il void Read( ll &x1 , ll &x2 , ll &x3 ){
	x1 = In.Readll(); x2 = In.Readll(); x3 = In.Readll();
}
il void Read( ll &x1 , ll &x2 , ll &x3 , ll &x4 ){
	x1 = In.Readll(); x2 = In.Readll(); x3 = In.Readll(); x4 = In.Readll();
}
clock_t _starttime , _endtime;
il void FILEIO(){
	#ifdef InterestingLSY
		_starttime = clock();
		Fin("in.in");
	#endif
}
il void END(){
	#ifdef InterestingLSY
		_endtime = clock();
		double _timeuse = (_endtime-_starttime)* 1000.0 / CLOCKS_PER_SEC;
		printf("\n\nTime usage:\n%.0lf ms\n",_timeuse);
	#endif
	exit(0);
}
#define For(i,j) for( rg int (i) = 1 ; (i) <= (j) ; (i)++ )
#define For0(i,j) for( rg int (i) = 0 ; (i) < (j) ; (i)++ )
#define Forx(i,j,k) for( rg int (i) = (j) ; (i) <= (k) ; (i)++ )
#define Forstep(i,j,k,st) for( rg int (i) = (j) ; (i) <= (k) ; (i) += (st) )
#define fOR(i,j) for( rg int (i) = (j) ; (i) >= 1 ; (i)-- )
#define fOR0(i,j) for( rg int (i) = (j)-1 ; (i) >= 0 ; (i)-- )
#define fORx(i,j,k) for( rg int (i) = (j) ; (i) >= (k) ; (i)-- )
int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};
//			D L U  R
#define Mymod(a,b) if( a >= b ) a -= b;
#define Rmod(a,b) a = (a%b+b)%b
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
#define MAXN 1000010
#define MAXA 10100
#define ld double

int T;
int n;
int aa[MAXN];
int cnt[MAXA];
vc<int> a;

ld S( ld a , ld b ){
	return (ld)a / (ld)b + (ld)b / (ld)a;
}

int main(){
	FILEIO();

	Read(T);
	For(Ti,T){
		//Ms(cnt);
		a.clear();

		Read(n);
		For(i,n){
			Read(aa[i]);
			cnt[aa[i]]++;
		}
		sort(aa+1,aa+1+n);
		For(i,n){
			if( cnt[aa[i]] < 2  ||  aa[i] == aa[i-1] ) continue;
			a.Pb(aa[i]);
		}
		sort(All(a));

		int a1 , a2;
		ld mins = INF;
		For0(i,a.size()){
			int u = a[i];
			ld ts = INF;
			int ano;
			if( cnt[u] < 4 ){
				vc<int>::iterator pr = lower_bound(All(a),u);
				if( pr != a.begin() ){
					pr--;
					ts = S((*pr),u);
					ano = (*pr);
				}
				vc<int>::iterator nx = upper_bound(All(a),u);
				if( nx != a.end() ){
					ld tans = S((*nx),u);
					if( tans < ts ){
						ts = tans;
						ano  =(*nx);
					}
				}
			}else{
				Mymin(ts,S(u,u));
				ano = u;
			}
			if( ts < mins ){
				mins = ts;
				a1 = u;
				a2 = ano;
			}
		}

		printf("%d %d %d %d\n",a1,a1,a2,a2);
		For(i,n)
			cnt[aa[i]]--;
	}

	END();
}