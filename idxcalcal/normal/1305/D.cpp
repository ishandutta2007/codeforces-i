#include<bits/stdc++.h>
#include<tr1/unordered_map>
#define ri register int
using namespace std;
#define y2 cyktxdy
typedef long long ll;
typedef vector<int> poly;
typedef vector<ll> Poly;
typedef pair<int,int> pii;
#define pb push_back
#define fi first
#define se second
const int rlen=1<<18|1,inf=0x3f3f3f3f;
const ll Inf=1e18;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() getchar()//(((ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin)),ib==ob)?-1:*ib++)
inline int read() {
  int ans=0;
  bool f=1;
  char ch=gc();
  while(!isdigit(ch)) f^=ch=='-',ch=gc();
  while(isdigit(ch)) ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
  return f?ans:-ans;
}
inline ll readl() {
  ll ans=0;
  bool f=1;
  char ch=gc();
  while(!isdigit(ch)) f^=ch=='-',ch=gc();
  while(isdigit(ch)) ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
  return f?ans:-ans;
}
inline int Read(char*s) {
  int top=0;
  char ch=gc();
  while(!isalpha(ch)&&!isdigit(ch)) ch=gc();
  while(isalpha(ch)||isdigit(ch)) s[++top]=ch,ch=gc();
  return top;
}
namespace modular {
  int mod;
  inline int add(int a,int b) { return a+b<mod?a+b:a+b-mod; }
  inline int dec(int a,int b) { return a<b?a-b+mod:a-b; }
  inline int mul(int a,int b) { return (ll)a*b%mod; }
  inline void Add(int&a,int b) { a=a+b<mod?a+b:a+b-mod; }
  inline void Dec(int&a,int b) { a=a<b?a-b+mod:a-b; }
  inline void Mul(int&a,int b) { a=(ll)a*b%mod; }
  inline int ksm(int a,ll p) { int ret=1;for(;p;p>>=1,Mul(a,a)) (p&1)&&(Mul(ret,a),1);return ret; }
  inline int Inv(int a) { return ksm(a,mod-2); }
  inline int sqr(int a) { return mul(a,a); }
  inline int cub(int a) { return mul(mul(a,a),a); }
}
using namespace modular;
template<typename T>inline void ckmax(T&a,T b) { a<b?a=b:0; }
template<typename T>inline void ckmin(T&a,T b) { a>b?a=b:0; }
template<typename T>inline T gcd(T a,T b) { T t;while(b) t=a,a=b,b=t-t/a*a;return a; }
template<typename T>inline T Abs(T x) { return x<0?-x:x; }
const int N=1e5+5;
set<int>e[N];
set<pii>q;
int n,du[N];
void dfs(int p) {
  du[p]=1;
  int x;
  for(set<int>::iterator it=e[p].begin();it!=e[p].end();++it) {
    x=*it;
    if(e[x].find(p)!=e[x].end()) e[x].erase(p);
    dfs(x);
  }
}
int main() {
  // #ifdef ldxcaicai
  // freopen("lx.in","r",stdin);
  // #endif
  n=read();
  for(ri i=1,u,v;i<n;++i) {
    u=read(),v=read();
    e[u].insert(v);
    e[v].insert(u);
  }
  for(ri i=1;i<=n;++i) q.insert(pii(e[i].size(),i));
  while(q.size()) {
    pii x=*q.rbegin();
    q.erase(x);
    int a=x.se,b,c,d;
    if(du[a]) continue;
    if(e[a].size()==1) {
      b=*e[a].begin();
      e[a].clear();
      q.erase(pii(e[b].size(),b));
      e[b].erase(a);
      if(e[b].size()) q.insert(pii(e[b].size(),b));
      cout<<"? "<<a<<' '<<b<<'\n'<<endl;
      int c=read();
      dfs(a+b-c);
    }
    else {
      b=*e[a].begin();
      e[a].erase(b);
      q.erase(pii(e[b].size(),b));
      e[b].erase(a);
      if(e[b].size()) q.insert(pii(e[b].size(),b));
      c=*e[a].begin();
      e[a].erase(c);
      q.erase(pii(e[c].size(),c));
      e[c].erase(a);
      if(e[c].size()) q.insert(pii(e[c].size(),c));
      cout<<"? "<<b<<' '<<c<<'\n'<<endl;
      int d=read();
      if(d==b) dfs(a),dfs(c);
      else if(d==a) dfs(c),dfs(b);
      else if(d==c) dfs(a),dfs(b);
      if(e[a].size()) q.insert(pii(e[a].size(),a));
    }
  }
  for(ri i=1;i<=n;++i) if(!du[i]) return cout<<"! "<<i<<endl,0;
  return 0;
}