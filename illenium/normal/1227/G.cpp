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

struct node{int val,id;}a[maxn];
int ans[1005][1005];

inline bool cmp(node a,node b){return a.val>b.val;}

int main()
{
	int n=read();
	for(int i=1;i<=n;i++) a[i].val=read(),a[i].id=i;
	sort(a+1,a+n+1,cmp);
	cout<<n+1<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i].val;j++)
			ans[(i+j-1)%(n+1)+1][a[i].id]=1;
	}
	for(int i=1;i<=n+1;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%d",ans[i][j]);
		puts("");
	}
	return 0;
}