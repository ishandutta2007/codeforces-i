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

int n,w[maxn],a[maxn],x;

int main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cout<<"? "<<i<<" "<<i+1<<endl;
		fflush(stdout);
		cin>>w[i];
	}
	cout<<"? 1 3"<<endl;
	fflush(stdout);
	cin>>x;
	a[1]=(x+w[1]+w[2])/2-w[2]; cout<<"! "<<a[1]<<" ";
	for(int i=2;i<=n;i++) a[i]=w[i-1]-a[i-1],cout<<a[i]<<" ";
	return 0;
}