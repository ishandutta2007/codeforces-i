#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 200005
#define inf 1e9
#define eps 1e-10
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
		int n=read();
		for(int i=1;i<=2*n;i++) a[i]=read();
		sort(a+1,a+2*n+1);
		printf("%d\n",a[n+1]-a[n]);
	}
	return 0;
}