#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <bitset>
#include <ctime>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define F first
#define S second
#define qq queue
#define dq deque
#define vc vector
#define INF ((int)(1e8))
#define in cin >>
#define LINF ((int)(1e17))
#define out cout <<
#define ln  << outtimedl
#define pb push_back
#define mp make_pair
#define ll long long
#define _tp template
#define _tyn typename
#define pf push_front
#define itor iterator
#define sint short int
#define ull unsigned ll
#define pq priority_queue
#define pii pair<int,int>
#define uint unsigned int
#define B out "BreakPoint\n";
#define read(_num) scanf("%d",&_num)
#define ms(_data) memset(_data,0,sizeof(_data))
#define fin(_filouttimeame) freopen(_filouttimeame,"r",stdin)
#define fout(_filouttimeame) freopen(_filouttimeame,"w",stdout)
#define read2(_num1,_num2) scanf("%d %d",&_num1,&_num2)
#define msn(_data,_num) memset(_data,_num,sizeof(_data))
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define read3(_num1,_num2,_num3) scanf("%d %d %d",&_num1,&_num2,&_num3)
using namespace std;
_tp<_tyn T>void mymax( T &_a , T _b ){ if( _a < _b ) _a = _b; }
_tp<_tyn T>void mymin( T &_a , T _b ){ if( _a > _b ) _a = _b; }
void print(int _x){printf("%d ",_x);}
void print(ll _x){printf("%I64d ",_x);}
#define MAXN 501020

int n;
int v[10];

int main(){
	ms( v );

    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ){
        int x;
        scanf("%d",&x);
        v[x]++;
    }

    int ans = v[4];
    while(v[3] > 0){
        ans++;
        v[3]--;
        if( v[1] > 0 ) v[1]--;
    }
    while( v[2] > 0 ){
        ans++;
        v[2]--;
        if( v[2] > 0 ) v[2]--;
        else{
            if( v[1] > 0 ) v[1]--;
            if( v[1] > 0 ) v[1]--;
        }
    }
    while( v[1] > 0 ){
        ans++;
        v[1] -= 4;
    }
	
    printf("%d\n",ans);
    return 0;
}