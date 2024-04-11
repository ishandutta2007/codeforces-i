/****************************************************************
Author           : Ishan Dutta
Email            : ishandutta2007@gmail.com
Facebook account : https://www.facebook.com/ishan.dutta
Blog             : tessellationsoftechnology.wordpress.com
Topcoder Handle  : Ishandutta2007
Codeforces Handle: ishandutta2007
Codechef Username: ishandutta2007
Spoj Username    : ishandutta2007
UVA Username     : ishandutta2007
Team Name        : Entropy           
/*******************************************************************/
// \_/\_/\_/\_/\_/\_/\_/\_/---Headers---\_/\_/\_/\_/\_/\_/\_/\_/
/*******************************************************************/
//C headers
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<cctype>
#include<cassert>
#include<climits>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<clocale>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cwchar>
#include<cwctype>

//containers
#include<vector>
#include<list>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<complex>
#include<string>
#include<stack>
#include<bitset>
#include<istream>
#include<valarray>

//IOs
#include<iostream>
#include<sstream>
#include<iomanip>
#include<fstream>
#include<exception>
#include<ios>
#include<iosfwd>
#include<ostream>
#include<iterator>
#include<stdexcept>
#include<streambuf>

//algorithm & miscellaneous
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<limits>
#include<locale>
#include<memory>
#include<new>

/********************************************************************/
// \_/\_/\_/\_/\_/\_/\_/---Frequently used macros---\_/\_/\_/\_/\_/\_/\_/
/********************************************************************/

#define MOD 1000000007
#define INF 1000000000

/********************************************************************/
// \_/\_/\_/\_/\_/\_/\_/\_/\_/---Shorthands---\_/\_/\_/\_/\_/\_/\_/\_/\_/
/********************************************************************/

#define ll long long
#define ld long double
#define F first
#define S second
#define PB push_back
#define PPB pop_back
#define MP make_pair

#define SZ(c)       (int)(c).size()
#define set(x,v)    memset((x),(int)(v),sizeof(x));

#define ALL(x)      (x).begin(),(x).end()
#define SORT(x)     sort(ALL(x))
#define REV(c)      reverse(ALL(c))

#define FOR(i,a,b)  for(int i=(int)(a);i<=(int)(b);i++)
#define REP(i,n)    FOR(i,0,(n-1))

#define FORD(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define REPD(i,n)   FOR(i,(n-1),0)

#define IT(it,x)    for(typeof((x).begin()) it = (x).begin();it!=(x).end();++it)  

#define tst         int T;scanf("%d",&T);for(int testno=1;testno<=T;testno++)
#define s(x)        scanf("%d",&x)
#define sl(x)       scanf("%lld",&x)
#define ss(x)       scanf("%s",x)

#define p(x)        printf("%d",x)
#define pl(x)       printf("%lld",x)
#define ps(x)       printf("%s",x)

#define pn(x)       printf("%d\n",x)
#define pln(x)      printf("%lld\n",x)
#define psn(x)      printf("%s\n",x)

#define PII pair< int,int >
#define PIL pair< int,long long >
#define PLI pair< long long,int >
#define VI vector< int >
#define VLL vector< long long >
#define MII map< int,int >
#define PQ priority_queue

#define sp system("PAUSE")

template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}

/* ****************************************************************** */
// \_/\_/\_/\_/\_/---Fast IO using getchar_unlocked---\_/\_/\_/\_/\_/
/* ****************************************************************** */
/*
int gi(){
   int c = 'a';
   while (!(c >= '0' && c <= '9') && c != '-') c = getchar_unlocked();//();//
   int c2;
   if (c != '-')
     c2 = c;
   else
     c2 = '0';
   int res = 0;
   while((c2 >= '0' && c2 <= '9')){
     res = (res << 3) + (res << 1) + (c2 - '0');
     c2 = getchar_unlocked();//();//
   }
   return res * (c == '-' ? -1 : 1);
}
*/
using namespace std;
/* ****************************************************************** */
// \_/\_/\_/\_/\_/\_/---Actual Code Starts Here---\_/\_/\_/\_/\_/\_/
/* ****************************************************************** */
int s,n;
int a,b;

bool isP[1123456];
vector <int> primes;
int ctr=0;
void sieve()
{
   memset(isP,1,sizeof(isP));
   isP[0]=isP[1]=false;
   for(int i=2;i<1123454;i++){
         if(isP[i])
         {
             primes.PB(i);
             if(i<10002)
             for(int j=i*i;j<1123455;j+=i){
                     isP[j]=false;
             }
         }
   }  
//   for(int i=1;i<11;i++)cout<<isP[i]<<" ";cout<<endl;
//   for(int i=0;i<10;i++)cout<<primes[i]<<" ";cout<<endl;
}

void solve(){
  sieve();
  int a,b,k;
  cin>>a>>b>>k;
  int low=(int)(lower_bound(ALL(primes),a)-primes.begin());
  int up=-1+(int)(upper_bound(ALL(primes),b)-primes.begin());
  int minl=-1;
//  cout<<low<<" "<<up<<endl;
  if(up-low+1>=k)
  {
      for(int i=low;i+k<=up;i++){
         minl=max(minl,primes[i+k]-primes[i]);
      }
      minl=max(minl,1+primes[up]-primes[up-k+1]+b-primes[up]);
      minl=max(minl,1+primes[low+k-1]-primes[low]+primes[low]-a);
      pn(minl);
  }
  else 
  psn("-1");
//  sp;
  return ;
}
int main(){
    solve();
}