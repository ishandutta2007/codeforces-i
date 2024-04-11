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

int main()
{
	int T=read();
	while(T--)
	{
		int r=read(),b=read(),k=read();
		int tmp=__gcd(r,b);
		r/=tmp,b/=tmp;
		if(r>b) swap(r,b);
		int tmp2=b-1,ans=0;
		if(tmp2%r==0) ans=tmp2/r;
		else ans=tmp2/r+1;
		//cout<<ans<<" "<<k<<endl;
		if(ans<k) puts("OBEY");
		else puts("REBEL");
	}
	return 0;
}