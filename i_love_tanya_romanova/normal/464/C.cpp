/*
The venom inside turned me into the enemy
Turned into what I hate
My apathy got the best of me
Blood boiled, I lost my way

I never thought I'd be the one to blame
Have to live with constant shame
Everything that I put inside
Just to feel numb

I tried to escape, push it away
Tried to hide the venom inside
Tried to escape, push it away
Tried to hide the venom inside

This was nothing but moral abuse
Guess, I just needed something new
What could I gain from solitude
Or acting like a fool?

I tried to escape, push it away
Tried to hide the venom inside
Tried to escape, push it away
Tried to hide the venom inside

Disconnected, apathetic
It's so pathetic to be this frantic
I needed help, I needed help
Like methadone for an addict

I tried to escape, push it away
Tried to hide the venom inside
Tried to escape, push it away
Tried to hide the venom inside
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
#define bsize 512

using namespace std;

string st;
pair<long long, long long> rule[1000];
long rules;
string st1;
vector<pair<long,string> > v;
long long bas,res,val;

pair<long, string> parse(string st)
{
 pair<long, string> r;
 r.first=st[0]-'0';
 for (int i=3;i<st.size();i++)
  r.second+=st[i];
 return r;
}

void update(pair<long, string> p)
{
 long long res,bas;
 res=bas=0;
 bas=1;
 string st=p.second;
 if (st.size())
 { 
  for (int i=st.size()-1;i+1;--i)
  {
  res+=1ll*rule[st[i]-'0'].first*bas;
  bas*=rule[st[i]-'0'].second;
  res%=bs;
  bas%=bs;
  }
 }
 rule[p.first]=make_pair(res,bas);
 return;
}

int main(){
//freopen("highway.in","r",stdin);
//freopen("highway.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st;
for (int i=0;i<10;i++)
 rule[i]=make_pair(i,10);

cin>>rules;
for (;rules;--rules)
{
 cin>>st1;
 v.push_back(parse(st1));
}

reverse(v.begin(),v.end());
for (int i=0;i<v.size();i++)
 update(v[i]);

// --- degb t
/*
for (int i=0;i<v.size();i++)
 cout<<v[i].first<<"  "<<v[i].second<<endl;
 

for (int i=0;i<10;i++)
 cout<<rule[i].first<<"  % "<<rule[i].second<<endl;
*/
 //---
res=0;
bas=1;
for (int i=st.size()-1;i+1;--i)
{
 res+=1ll*rule[st[i]-'0'].first*bas;
 bas*=rule[st[i]-'0'].second;
 res%=bs;
 bas%=bs;
}

cout<<res<<endl;

cin.get();cin.get();
return 0;}