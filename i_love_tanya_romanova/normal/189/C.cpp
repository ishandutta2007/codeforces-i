//#pragma comment(linker, "/STACK:16777216")
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define  INF 1000000000
#define eps 1e-6
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;

long n,q,ps[300000],ar1[300000],ar2[300000],ans;
int main(){
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;

for (int i=1;i<=n;i++)
{
    cin>>ar1[i];
}

for (int i=1;i<=n;i++)
{
    cin>>ar2[i];
    ps[ar2[i]]=i;
}

q=0;
ans=n;
for (int i=1;i<=n;i++)
{
    if (ps[ar1[i]]>q){q=ps[ar1[i]];--ans;}
    else break;
}
cout<<ans<<endl;
cin.get();cin.get();
return 0;}