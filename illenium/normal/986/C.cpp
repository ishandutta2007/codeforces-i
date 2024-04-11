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
#define maxn 1<<22
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

int a[maxn],total,n,m;
bool v[maxn],p[maxn];

inline void dfs(int x)
{
	v[x]=1;
	for(int i=0;i<n;i++) if((x&(1<<i))==0&&!v[x^(1<<i)]) dfs(x^(1<<i));
	if(p[total^x]&&!v[total^x]) dfs(total^x);
}

int main()
{
	cin>>n>>m; total=(1<<n)-1;
	for(int i=1;i<=m;i++) a[i]=read(),p[a[i]]=1;
	int ans=0;
	for(int i=1;i<=m;i++)
		if(!v[total^a[i]])
		{
			ans++;
			if(!v[a[i]]) dfs(a[i]);
		}
	cout<<ans<<endl;
	return 0;
}