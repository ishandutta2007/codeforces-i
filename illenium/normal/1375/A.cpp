#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 2000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int a[maxn];

int main()
{
	int T=read();
	while(T--)
	{
		int n=read(); rep(i,1,n) a[i]=abs(read());
		rep(i,1,n)
		{
			if(i%2==0) printf("%d ",a[i]);
			else printf("%d ",-a[i]);
		}
		puts("");
	}
	return 0;
}