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

int main()
{
	int T=read();
	while(T--)
	{
		int n=read(),ans=0,tmp=0;
		for(int i=1;i<=n;i++)
		{
			int x=read();
			if(x==0) ans++,x++; tmp+=x;
		}
		if(tmp==0) ans++;
		cout<<ans<<endl;
	}
	return 0;
}