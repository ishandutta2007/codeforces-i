#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#define ll long long
#define maxn 200005
#define re register
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

int n,a,b;
map <ll,int> S;
map <pair<int,int>,int> T;

int main()
{
	ll ans=0;
	int x,vx,vy;
	n=read(); a=read(); b=read();
	for(int i=1;i<=n;i++)
	{
		x=read(); vx=read(); vy=read();
		ll t=vy-(ll)a*vx;
		ans+=(S[t]-T[make_pair(vx,vy)]);
		S[t]++; T[make_pair(vx,vy)]++;
	}
	cout<<ans*2<<endl;
	return 0;
}