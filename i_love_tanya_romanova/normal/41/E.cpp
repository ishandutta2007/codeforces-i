/*
I'm home again, I won the war, and now I am behind
your door. I tried so hard to obey the law, and see the
meaning of this all. Remember me? Before the war.
I'm the man who lived next door. Long ago...

As you can see, when you look at me, I'm pieces of
what I used to be. It's easier when you don't see me
standing on my own two feet. I'm taller when I sit
here still, you ask are all my dreams fulfilled.
They made me a heart of steal, the kind them bullets
cannot see, yeah.

Nothing's what it seems to be,
I'm a replica, I'm a replica
Empty shell inside of me
I'm not myself, I'm a replica of me...

The light is green, my slate is clean, new life to fill
the hole in me. I had no name, last December, Christmas
Eve I can't remember. I was in a constant pain, I saw
your shadow in the rain. I painted all your pigeons red,
I wish I had stayed home instead, yeah.

Nothing's what it seems to be,
I'm a replica, I'm a replica
Empty shell inside of me
I'm not myself, I'm a replica of me...

Are you gonna leave me now, when it is all over
Are you gonna leave me, is my world now over...

Raising from the place I've been, and trying to keep
my home base clean. Now I'm here and won't go back believe.

I fall asleep and dream a dream, I'm floating in a
silent scream. No-one placing blame on me
But nothing's what it seems to be, yeah.

Nothing's what it seems to be,
I'm a replica, I'm a replica
Empty shell inside of me
I'm not myself, I'm a replica of me...
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
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-6
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 250
#define clone agsdahfaassdg

using namespace std;

long n;
vector<pair<long, long> > edges;

void add_edge(long a,long b)
{
     if (a>b)return;
     edges.push_back(make_pair(a,b));
}

int main(){
//freopen("galaxy.in","r",stdin);
//freopen("galaxy.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
for (int j=1;j<=n;j++)
if (i%2!=j%2)
add_edge(i,j);

cout<<edges.size()<<endl;
for (int i=0;i<edges.size();i++)
{
 cout<<edges[i].first<<" "<<edges[i].second<<endl;
}

cin.get();cin.get();
return 0;}