#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
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
		int x=read(); if(x>45) {puts("-1"); continue;}
		vector <int> ans; ans.clear();
		per(i,9,1)
		{
			if(x==0) break;
			if(x>=i) ans.pb(i),x-=i;
			else {ans.pb(x); break;}
		}
		for(int i=ans.size()-1;i>=0;i--) printf("%d",ans[i]); puts("");
	}
	return 0;
}