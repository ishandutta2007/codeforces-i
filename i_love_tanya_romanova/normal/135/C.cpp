/*
I can't comprehend society's movement
The regression of human existence
This is the quest of life
Fulfill your destiny
Slow down

Slow down this fast paced world
And you will see past the illusion

Breaking the foundation
Collapse the control
Building a revolution to heal nations
It starts within you

Slow down the fast paced world
And you will see past the illusion

Breaking the foundation
Collapse the control
Building a revolution to heal nations
It starts within you

In this search for I and I
(Reversal of oneself finding the truth)
The truth is always deep inside
(Reversal of oneself finding the truth)

This is the quest of life
(Quest of life)
We must find the strength
(Find the strength)
This is the quest of life
We must find the strength for a new movement

In this search for I and I
(Reversal of oneself finding the truth)
The truth is always deep inside
(Reversal of oneself finding the truth)

Slow down this fast paced world
And you will see the revolution for a new movement
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

#define EPS 1e-11
//#define M_PI 3.141592653589793
#define bs 9999997
#define bsize 256
#define right adsgasgadsg

using namespace std;

string st;
long a,b,c,d;
vector<string> ans;

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st;
for (int i=0;i<st.size();i++)
{
 if (st[i]=='?')++c;
 else if (st[i]=='1')++a;
 else ++b;
}
if (a<b+c)ans.push_back("00");
if (a+c>b+1)ans.push_back("11");

if (st[st.size()-1]!='1')
{
 for (int x=0;x<=c-(st[st.size()-1]=='?');x++)
 {
  if (a+x>=b+(c-x)&&a+x<=b+(c-x)+1)
  {ans.push_back("10");break;}
 }
}
if (st[st.size()-1]!='0')
{
 for (int x=0+(st[st.size()-1]=='?');x<=c;x++)
 {
  if (a+x>=b+(c-x)&&a+x<=b+(c-x)+1)
  {ans.push_back("01");break;}
 }
}
sort(ans.begin(),ans.end());
for (int i=0;i<ans.size();i++)
 cout<<ans[i]<<endl;
 
cin.get();cin.get();
return 0;}