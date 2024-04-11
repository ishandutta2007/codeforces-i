#include<bits/stdc++.h>
#define ri register int
#define fi first
#define se second
using namespace std;
const int mod=1e9+7;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> poly;
inline int add(int a,int b){return (a+=b)<mod?a:a-mod;}
inline int dec(int a,int b){return (a-=b)<0?a+mod:a;}
inline int mul(int a,int b){return (ll)a*b%mod;}
inline void Add(int&a,int b){(a+=b)<mod?a:a-=mod;}
inline void Dec(int&a,int b){(a-=b)<0?a+=mod:a;}
inline void Mul(int&a,int b){a=(ll)a*b%mod;}
inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,Mul(a,a))if(p&1)Mul(ret,a);return ret;}
inline int read(){
	#define gc getchar
	int ans=0;
	bool f=1;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return f?ans:-ans;
}
const int N=1e5+5;
int n;
char s[N];
bool vis[N];
int main(){
	n=read();
	scanf("%s",s+1);
	for(ri i=1;i<=n;++i){
		if(s[i]=='L'){
			for(ri j=0;j<10;++j){
				if(vis[j])continue;
				vis[j]=1;
				break;
			}
		}
		if(s[i]=='R'){
			for(ri j=9;~j;--j){
				if(vis[j])continue;
				vis[j]=1;
				break;
			}
		}
		if(isdigit(s[i]))vis[s[i]-'0']=0;
	}
	for(ri i=0;i<10;++i)cout<<vis[i];
	return 0;
}