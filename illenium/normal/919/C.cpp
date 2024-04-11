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

int n,m,k,ans;
char ch[2005][2005];

int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) scanf("%s",ch[i]+1);
	for(int i=1;i<=n;i++)
	{
		int cnt=0;
		for(int j=1;j<=m;j++)
		{
			if(ch[i][j]=='.') cnt++;
			else cnt=0;
			if(cnt>=k) ans++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		int cnt=0;
		for(int j=1;j<=n;j++)
		{
			if(ch[j][i]=='.') cnt++;
			else cnt=0;
			if(cnt>=k) ans++;
		}
	}
	if(k==1) cout<<ans/2;
	else cout<<ans<<endl;
	return 0;
}