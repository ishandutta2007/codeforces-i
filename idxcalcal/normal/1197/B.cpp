#include<bits/stdc++.h>
#define ri register int
#define fi first
#define se second
using namespace std;
inline int read(){
	#define gc getchar
	int ans=0;
	bool f=1;
	char ch=gc();
	while(!isdigit(ch))f^=ch=='-',ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return f?ans:-ans;
}
typedef pair<int,int> pii;
typedef long long ll;
const int mod=998244353;
inline int add(const int&a,const int&b){return a+b>=mod?a+b-mod:a+b;}
inline int dec(const int&a,const int&b){return a>=b?a-b:a-b+mod;}
inline int mul(const int&a,const int&b){return (ll)a*b%mod;}
inline void Add(int&a,const int&b){a=a+b>=mod?a+b-mod:a+b;}
inline void Dec(int&a,const int&b){a=a>=b?a-b:a-b+mod;}
inline void Mul(int&a,const int&b){a=(ll)a*b%mod;}
inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,a=mul(a,a))if(p&1)Mul(ret,a);return ret;}
const int N=2e5+5;
int n,a[N],pos[N],pre[N],suf[N];
int main(){
	n=read();
	for(ri i=1;i<=n;++i)a[i]=read(),pos[a[i]]=i;
	for(ri i=1;i<=n;++i)pre[a[i]]=a[i-1],suf[a[i]]=a[i+1];
	pre[0]=a[1],suf[n+1]=a[n];
	int t;
	for(t=n;t;--t){
		if(pre[t]!=t-1&&suf[t]!=t-1)break;
		suf[pre[t]]=suf[t];
		pre[suf[t]]=pre[t];
	}
	if(t>1)puts("No");
	else puts("Yes");
	return 0;
}