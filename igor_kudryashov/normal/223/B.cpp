#pragma comment(linker, "/stack:64000000")
#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include <algorithm>
#include <iostream>
#include <fstream>
#include <cassert>
#include <iomanip>
#include <utility>
#include <cstring>
#include <complex>
#include <cstdlib>
#include <bitset>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define for1(i, n) for (int i = 1; i <= int(n); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define debug(x) cerr << #x << " = " << x << endl;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair((a), (b))
#define X first
#define Y second
#define ft first
#define sc second

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long double ld;
typedef pair<ld, ld> ptd;
typedef pair <int, int> pt;
typedef long long li;
typedef unsigned char byte;

const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-9;
const int INF = 1000 * 1000 * 1000;

const int N = 200 * 1000 + 13;

int n1, n2;
char s1[N], s2[N];
vector <int> poses[30];
int maxPref[N], maxSuf[N];

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    gets(s1);
    gets(s2);
    
    n1 = strlen(s1);
    n2 = strlen(s2);
    
    forn(i, n2)
        poses[s2[i] - 'a'].pb(i);
        
    int curmax = 0;
        
    forn(i, n1)
    {
        if (s1[i] == s2[curmax])
        {
            curmax++;
            maxPref[i] = curmax;
            
        } else
        {
            int curc = s1[i] - 'a';
            
            int idx = int(lower_bound(all(poses[curc]), curmax) - poses[curc].begin()) - 1;
            
            if (idx >= 0 && idx < sz(poses[curc]))
                maxPref[i] = poses[curc][idx] + 1;
        }
    }
    
    curmax = 0;
    
    ford(i, n1)
    {
        if (curmax < n2 && s1[i] == s2[n2 - 1 - curmax])
        {
            curmax++;
            maxSuf[i] = curmax;
            
        } else
        {
            int curc = s1[i] - 'a';
            
            int idx = int(lower_bound(all(poses[curc]), n2 - curmax) - poses[curc].begin());
            
            if (idx >= 0 && idx < sz(poses[curc]))
                maxSuf[i] = n2 - poses[curc][idx];
        }
    }
    
    /*forn(i, n1)
        cerr << i << ' ' << maxPref[i] << ' ' << maxSuf[i] << endl;*/
    
    forn(i, n1)
        if (maxPref[i] + maxSuf[i] - 1 < n2)
        {
            puts("No");
            return 0;
        }
        
    puts("Yes");
    
    return 0;
}