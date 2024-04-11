#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll n,a[maxn],ans,b[maxn];

int main()
{
	int T=read();
	while(T--)
	{
		n=read(); rep(i,0,n-1) a[i]=read(),b[i]=0; ans=0;
		rep(i,0,n-1)
		{
			ans+=max(a[i]-b[i]-1,0ll);
			for(int j=i+2;j<=min(n-1,i+a[i]);j++) b[j]++;
			b[i+1]+=max(b[i]-a[i]+1,0ll);
		}
		printf("%lld\n",ans);
	}
	return 0;
}