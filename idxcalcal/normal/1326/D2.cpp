#include<bits/stdc++.h>
#define ri register int
using namespace std;
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef vector<int> poly;
#define pb push_back
const int rlen=1<<18|1,inf=0x3f3f3f3f;
const ll Inf=1e18;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() (((ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin)),ib==ob)?-1:*ib++)
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
  int tp=0;
  char ch=gc();
  while(!isdigit(ch)&&!isalpha(ch)) ch=gc();
  while(isdigit(ch)||isalpha(ch)) s[++tp]=ch,ch=gc();
  return tp;
}
namespace modular {
  const int mod=998244353;
  inline int add(int a,int b) { return a+b<mod?a+b:a+b-mod; }
  inline int dec(int a,int b) { return a<b?a-b+mod:a-b; }
  inline int mul(int a,int b) { return (ll)a*b%mod; }
  inline void Add(int&a,int b) { a=a+b<mod?a+b:a+b-mod; }
  inline void Dec(int&a,int b) { a=a<b?a-b+mod:a-b; }
  inline void Mul(int&a,int b) { a=(ll)a*b%mod; }
  inline int ksm(int a,int p) { int ret=1;for(;p;p>>=1,Mul(a,a)) (p&1)&&(Mul(ret,a),1);return ret; }
  inline int Inv(int a) { return ksm(a,mod-2); }
  inline int sqr(int a) { return mul(a,a); }
  inline int cub(int a) { return (ll)a*a%mod*a%mod; }
}
using namespace modular;
template<typename T> inline void ckmax(T&a,T b) { a<b?a=b:0; }
template<typename T> inline void ckmin(T&a,T b) { a>b?a=b:0; }
template<typename T> inline T gcd(T a,T b) { T t;while(b)t=a,a=b,b=t-t/a*a;return a; }
template<typename T> inline T Abs(T x) { return x<0?-x:x; }
inline int rd() { return rand()|(rand()<<15); }
const int N=2e6+5,bs1=37,bs2=41;
typedef unsigned long long Ull;
int pr1[N],sf1[N],n,m,l,len[N];
char s[N],t[N];
Ull pr2[N],sf2[N];
inline bool check(int l) { return pr1[l]==sf1[l]&&pr2[l]==sf2[l]; }
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  for(ri tt=read();tt;--tt) {
    n=Read(t);
    pr1[0]=pr2[0]=sf1[0]=sf2[0]=1;
    for(ri i=1;i<=n;++i) {
      pr1[i]=add(mul(pr1[i-1],bs1),t[i]-'a'+1);
      pr2[i]=pr2[i-1]*bs2+(t[i]-'a'+1);
      sf1[i]=add(mul(sf1[i-1],bs1),t[n-i+1]-'a'+1);
      sf2[i]=sf2[i-1]*bs2+(t[n-i+1]-'a'+1);
    }
    s[0]='!',s[l=1]='*';
    for(ri i=1;i<=n;++i) s[++l]=t[i],s[++l]='*';
    s[l+1]='@';
    for(ri i=1,mxps=0,r=0;i<=l;++i) {
      len[i]=0;
      if(i<=r) len[i]=min(r-i+1,len[mxps*2-i]);
      while(s[i+len[i]]==s[i-len[i]]) ++len[i];
      if(i+len[i]-1>r) r=i+len[i]-1,mxps=i;
    }
    int res=0,ps1=0,ps2=0;
    for(ri tmp,lm,ps,i=1;i<=l;++i) {
      lm=len[i]-1,ps=i/2;
      if(i&1) {
        if(ps<=n/2) {
          tmp=ps-lm/2;
          if(check(tmp)&&res<tmp*2+lm) {
            res=tmp*2+lm;
            ps1=ps+lm/2;
            ps2=n-tmp+1;
          }
        }
        else {
          tmp=ps+lm/2+1;
          if(check(n-tmp+1)&&res<2*(n-tmp+1)+lm) {
            res=(n-tmp+1)*2+lm;
            ps1=n-tmp+1;
            ps2=ps-(lm/2)+1;
          }
        }
      }
      else {
        if(ps<=n/2) {
          tmp=ps-lm/2-1;
          if(check(tmp)&&res<tmp*2+lm) {
            res=tmp*2+lm;
            ps1=ps+lm/2;
            ps2=n-tmp+1;
          }
        }
        else {
          tmp=ps+lm/2+1;
          if(check(n-tmp+1)&&res<2*(n-tmp+1)+lm) {
            res=(n-tmp+1)*2+lm;
            ps1=n-tmp+1;
            ps2=ps-lm/2;
          }
        }
      }
    }
    for(ri i=1;i<=ps1;++i) cout<<t[i];
    for(ri i=ps2;i<=n;++i) cout<<t[i];
    puts("");
  }
  return 0;
}