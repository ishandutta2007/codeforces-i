#include<bits/stdc++.h>
#define ri register int
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rsz resize
#define pb push_back
using namespace std;
#define gc getchar
inline int read(){
	int ans=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
}
const int mod=998244353;
typedef long long ll;
inline int add(int a,int b){return (a+=b)<mod?a:a-mod;}
inline int dec(int a,int b){return (a-=b)<0?a+mod:a;}
inline int mul(int a,int b){return (ll)a*b%mod;}
inline void Add(int&a,int b){(a+=b)<mod?a:(a-=mod);}
inline void Dec(int&a,int b){(a-=b)<0?(a+=mod):a;}
inline void Mul(int&a,int b){a=(ll)a*b%mod;}
inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,Mul(a,a))if(p&1)Mul(ret,a);return ret;}
const int N=2e5+5;
int n,k,fa[N],siz[N],sz[N];
struct pot{int x,y;}a[N];
inline int find(int x){return x^fa[x]?fa[x]=find(fa[x]):x;}
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read(),k=read();
	for(ri i=1;i<=n;++i)fa[i]=i,sz[i]=1;
	for(ri fx,fy,i=1;i<=k;++i){
		a[i].x=read(),a[i].y=read();
		fx=find(a[i].x),fy=find(a[i].y);
		if(fx==fy)++siz[fx];
		else fa[fx]=fy,siz[fy]+=siz[fx]+1,sz[fy]+=sz[fx];
	}
	int res=0;
	for(ri i=1;i<=n;++i)if(i==find(i))res+=siz[i]-sz[i]+1;
	cout<<res;
}