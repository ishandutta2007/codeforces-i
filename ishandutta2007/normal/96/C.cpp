/****************************************************************
Author           : Ishan Dutta
Email            : ishandutta2007@gmail.com
Facebook account : http://www.facebook.com/ishan.dutta
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
/********************************************************************/
// \_/\_/\_/\_/\_/\_/---Actual Code Starts Here---\_/\_/\_/\_/\_/\_/
/********************************************************************/
char *pEnd;
string w,w2,str[105],str2[105];
int arr[1010];
char let;
ll n;
void solve(){
  cin>>n;
  REP(i,n){cin>>str[i];str2[i]=str[i];}
  cin>>w;w2=w;
  cin>>let;
  
  REP(i,n){
    int j;
    for(j=0;j<str[i].length();j++){
      if('A'<=str[i][j]&&str[i][j]<='Z')str2[i][j]=str[i][j]+32;
      else                    str2[i][j]=str[i][j];
    }
  }
  REP(j,w.length())
    if('A'<=w[j]&&w[j]<='Z')w2[j]=w[j]+32;
    else                    w2[j]=w[j];
    
  int wl=w.length();
  for(int k=0;k<n;k++){//for each substr
      for(int i=0;i<wl;i++){
        int j;
        for(j=0;j<str2[k].length() && i+j<wl && w2[i+j]==str2[k][j];j++);
        if(j==str2[k].length()){
          //cout<<j<<" "<<str2[k].length()<<" "<<i<<" "<<k<<endl;
          for(j=0;j<str2[k].length();j++)arr[i+j]=1;
        }
      }
  }
  //REP(i,wl)cout<<arr[i];cout<<endl;
  REP(i,wl){
    if(arr[i]==1){
         if(w2[i]==let){
            if(let!='a'){
                        if('A'<=w[i] && w[i]<='Z')w2[i]='A';
                        else w2[i]='a';
                      }
              else{
                        if('A'<=w[i] && w[i]<='Z')w2[i]='B';
                        else w2[i]='b';
                      }
         }
         else{
                        if('A'<=w[i] && w[i]<='Z')w2[i]=let-32;
                        else w2[i]=let;
         }
    }
    else             if('A'<=w[i] && w[i]<='Z')w2[i]=w2[i]-32;
  }
  cout<<w2;
//sp;
}
int main(){solve();}