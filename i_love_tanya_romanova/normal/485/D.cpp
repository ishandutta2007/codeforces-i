/*
Trust is nothin' to spit on
It's something that you don't deserve
You are a scheming player
A traitor, a slayer, failure to observe!

Life's a bitch end in the ditch - letdown and hate
Twist of fate

Hang yourself with a figure eight - now it's too... late
Twist of fate
Twist of fate!
Twist of fate!

You try to rule my fuckin' life
You give me hell on earth
You've frightened away my social dealings
Aversion's is all that is left - for what it's worth

Life's a bitch end in the ditch - letdown and hate
Twist of fate

Hang yourself with a figure eight - now it's too... late
Twist of fate
Twist of fate!
Twist of fate!

No money could buy you the freedom
The peace of mind that you won't get
The inner strife of your soul will kill
Worthless fuck best of luck this ain't a murder threat
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
#define free adsgasdg

using namespace std;

long n,ar[1<<20],has[1<<21];
vector<long> s;
vector<long>::iterator it;
long v,ans;

int main(){
//freopen("logins.in","r",stdin);
//freopen("logins.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>ar[i];
 has[ar[i]]=1;
 s.push_back(ar[i]);
}
sort(s.begin(),s.end());

for (int i=1;i<=1000000;i++)
if (has[i])
{
 for (int j=i*2;j<=1000000+i;j+=i)
 {
     it=lower_bound(s.begin(),s.end(),j);
     if (it!=s.begin())
     {
      --it;
      v=(*it);
      ans=max(ans,v%i);
     }
 }
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}