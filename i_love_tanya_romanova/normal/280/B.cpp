//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
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
#include <memory.h>
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
 
#define  INF 100000000
#define eps 1e-11
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60
using namespace std; 

long n,ar[200000];
stack<long> s;
long ans;

int main(){
//freopen("knight.in","r",stdin);
//freopen("knight.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=0;i<n;i++)
{
 cin>>ar[i];
 while (s.size()>0&&s.top()<ar[i])
 s.pop();
 
 if (s.size()>0)
 ans=max(ans,ar[i]^s.top());
 
 s.push(ar[i]);   
}

reverse(ar,ar+n);
while(s.size())s.pop();


for (int i=0;i<n;i++)
{
// cin>>ar[i];
 while (s.size()>0&&s.top()<ar[i])
 s.pop();
 
 if (s.size()>0)
 ans=max(ans,ar[i]^s.top());
 
 s.push(ar[i]);   
}


cout<<ans<<endl;

cin.get();cin.get();
return 0;}