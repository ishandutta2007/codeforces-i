#pragma comment(linker, "/stack:64000000")
#define _SECURE_SCL 0
#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include <algorithm>
#include <iostream>
#include <cassert>
#include <iomanip>
#include <utility>
#include <cstring>
#include <complex>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <ctime>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
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

string op[3];

li oper (int pos, li a, li b)
{
    if (op[pos] == "*")
        return a * b;
        
    return a + b;
}

int main()
{
    
    vector <li> v;
    
    forn(i, 4)
    {
        int tmp;
        cin >> tmp;
        v.pb(tmp);
    }
    
    forn(i, 3)
        cin >> op[i];
    
    vector <int> perm;
    forn(i, 4)
        perm.pb(i);
        
    li ans = li(1e17);
        
    do
    {
        vector <li> nw;
        
        nw.pb(oper(0, v[perm[0]], v[perm[1]]));
        
        nw.pb(v[perm[2]]);
        nw.pb(v[perm[3]]);
        
        vector <int> perm2;
        forn(i, 3)
            perm2.pb(i);
        
        do
        {
            vector <li> res;
            
            res.pb(oper(1, nw[perm2[0]], nw[perm2[1]]));
            res.pb(nw[perm2[2]]);
            
            ans = min(ans, oper(2, res[0], res[1]));
        
        } while (next_permutation(all(perm2)));
    
    } while (next_permutation(all(perm)));
    
    cout << ans << endl;

    return 0;
}