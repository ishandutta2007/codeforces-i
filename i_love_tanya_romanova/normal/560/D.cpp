/*
My heart is unyielding
My dreams are fulfilled
Yet so full of longing
Without him it's stilled
Untouched by all evil
My truelove and I
My hope and my sole will
His sight so divine

My heart is stern faithful
No tempt or a lie
Never bitter nor hateful
O'er waves chanted sigh
Shamelessly yearn for him
For his heart I know
In the winds my lust burning
In the winds my heart woe

I am your fear of weakness
I'm your guilt and the fault
I grant you all eternal
I grant you all desires

My heart is sheer forthright
Nor guilt neither fault
No shadows of hellwraith
No sin to be found

I am your fear of weakness
I'm your guilt and the fault
I grant you all eternal
I grant you all desires

My heart is unyielding
I am his but alone
Yet so full of longing
Awaits whilst he's gone
My love stands eternal
His touch I desire
Wraiths of all infernal
Our love will defy
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
#include <ctime> 

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512
#define nice adsfasdfasdfasdf

using namespace std;

string st1,st2;

long long get_hash(string st)
{
    if (st.size()==1)
        return st[0];
    long long q=1;
    for (int i=0;i<st.size();i++)
        q=q*173+st[i],
        q%=bs;
    if (st.size()%2)
        return q;
    long long l=st.size()/2;
    string st1,st2;
    for (int i=0;i<l;i++)
        st1+=st[i];
    for (int i=l;i<st.size();i++)
        st2+=st[i];
    long long v1,v2;
    v1=get_hash(st1);
    v2=get_hash(st2);
    if (v1>v2)
        swap(v1,v2);
    
//  cout<<v1<<" "<<v2<<" "<<st<<endl;
    
    return ((1ll*v1*v1%bs*1234567891%bs+v2)%bs*10000007+31)%bs;
}

int main(){
//freopen("blind.in","r",stdin);
//freopen("blind.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st1>>st2;

long long p1=get_hash(st1);
long long p2=get_hash(st2);
//cout<<p1<<" "<<p2<<endl;

if (p1==p2)
    cout<<"YES"<<endl;
else
    cout<<"NO"<<endl;
    
//cin.get();cin.get();
return 0;}