/*
Once we lived in harmony, but it seems so distance now.
Even though it wasnt long ago, were all doomed to
Plague and death. Working hard from dawn til dusk. but
That aint enough for him Product of unholy love, untrue
Brother of a king.

Know that youll fail, now hear us hail
Your brother that you killed.

Hail to the king that brought peace to us all. Rise from
Your grave, hear our call. Well not forget that you once
Saved our land. Killed by your own brothers hand.

Pure evil and cruelty, the true nature of your soul.
Mercy and responsibility, words that you cant understand.
Your quest for total control will only end in your own fall.
We will fight for our freedom, and our right to live.

Do it your way, soon you will pay
Debts with your own blood.

Stars so bright, dance in the night
Day come soon, hide the moon
Stars so bright dance in the night
Day come soon, killing the moon

Morning breaks its time to march, to the castle of betrayal.
Bring your sword, wield your armour, we wont take this anymore.
Kill the tyrant he must die, for his falseness and his crimes.
Strike him down, and slay his guards, and his ministers as well.

Done it your way, now you will pay
Debts with your own blood.

Hail to the king!
*/

#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
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
#include <assert.h>

#define y0 sdkfaslhagaklsldk

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define left asdgashgrketwjklrej
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd
#define prev asdgSHJsfgsdfhdsh
#define hash asdgasdgasdgdfrywewery

#define eps 1e-9
#define M_PI 3.141592653589793
#define bsize 1024

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 200031;

int tests,n,k1,k2;

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
 //   cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n>>k1>>k2;
    	bool win=0;
    	for (int i=1;i<=k1;i++){
    		int val=0;
    		cin>>val;
    		if (val==n)
    			win=1;
    	}

    	for (int i=1;i<=k2;i++){
    		int val;
    		cin>>val;
    	}
    	if (win)
    		cout<<"YES"<<endl;
    	else
    		cout<<"NO"<<endl;
    }

    //    cin.get(); cin.get();
    return 0;
}