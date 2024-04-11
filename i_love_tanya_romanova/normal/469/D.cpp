/*
Once I traveled seven seas to find my love
And once I sang seven hundred songs
Well, maybe I still have to walk seven thousand miles
Until I find the one that I belong

I will rest my head side by side
To the one that stays in the night
I will lose my breath in my last words of sorrow

And whatever comes will come soon
Dying, I will pray to the moon
That there once will be a better tomorrow

Once I crossed seven rivers to find my love
And once for seven years I forgot my name
Well, if I have to, I will die seven deaths just to lie
In the arms of my eversleeping aim

I will rest my head side by side
To the one that stays in the night
I will lose my breath in my last words of sorrow

And whatever comes will come soon
Dying I will pray to the moon
That there once will be a better tomorrow

I will rest my head side by side
To the one that stays in the night
I will lose my breath in my last words of sorrow

And whatever comes will come soon
Dying I will pray to the moon
That there once will be a better tomorrow

I dreamt last night that he came to me
He said, "My love, why do you cry?
For now it won't be long any more
Until in my cold grave we will lie
Until in my cold grave we will lie"
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg

using namespace std;

long n,a,b,ar[1<<20];
set<long> has;
map<long, long> mapp;
vector<long> g[1<<20];
vector<long> gr[1<<20];
long temp,id;
long ans[1<<20],comp[1<<20];
vector<long> order;
long used[1<<20];
long ttl;

void add_edge(long a,long b)
{
   //  cout<<a<<"^"<<b<<endl;
     g[a].push_back(b);
     gr[b].push_back(a);
}

void dfs1(long v)
{
 used[v]=1;
 for (int i=0;i<g[v].size();i++)
 {
     long q=g[v][i];
     if (used[q])continue;
     dfs1(q);
 }
 order.push_back(v);
}

void dfs2(long v)
{
 comp[v]=ttl;
 for (int i=0;i<gr[v].size();i++)
 {
     long to=gr[v][i];
     if (comp[to]==-1)dfs2(to);
 }
}

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>a>>b;
for (int i=1;i<=n;i++)
{
    cin>>ar[i];
    mapp[ar[i]]=i;
    has.insert(ar[i]);
}

for (int i=1;i<=n;i++)
{
 add_edge(i,3*n+i);
 add_edge(3*n+i,i);
 add_edge(n+i,2*n+i);
 add_edge(2*n+i,n+i);
}

for (int i=1;i<=n;i++)
{
    temp=a-ar[i];
    if (temp==ar[i])continue;
    if (has.find(temp)==has.end()){add_edge(i,i+n);continue;}
    id=mapp[temp];
    add_edge(i,id);
    add_edge(i+n,id+n);
}

for (int i=1;i<=n;i++)
{
    temp=b-ar[i];
    if (temp==ar[i])continue;
    if (has.find(temp)==has.end()){add_edge(i+2*n,i+3*n);continue;}
    id=mapp[temp];
    add_edge(i+2*n,id+2*n);
    add_edge(i+3*n,id+3*n);
}

for (int i=1;i<=4*n;i++)
{
    if (used[i])continue;
    dfs1(i);
}
for (int i=0;i<=n*4;i++)
 comp[i]=-1;

for (int i=0;i<n*4;i++)
{
    long id=order[4*n-i-1];
    if (comp[id]==-1)
    {
     ++ttl;
     dfs2(id);
    }
}

long er=0;

for (int i=1;i<=n;i++)
{
 if (comp[i]==comp[i+n])
 {
  er=1;
 }
}

if (er)cout<<"NO"<<endl;
else
{
     cout<<"YES"<<endl;
     for (int i=1;i<=n;i++)
      if (comp[i]>comp[i+n])
       ans[i]=0;
       else ans[i]=1;
      for (int i=1;i<=n;i++)
      {
          if (i>1)cout<<" ";
          cout<<ans[i];
      }
      cout<<endl;
}

cin.get();cin.get();
return 0;}