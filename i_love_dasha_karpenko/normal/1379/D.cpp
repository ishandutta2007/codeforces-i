#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
#define log sdfdsfdsf

const ll DIM = 1E5+7;

const ll INF = 2E18;
const ld eps = 0.0000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}

pp A[DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


    ll n,h,m,k;
    cin>>n>>h>>m>>k;
    m/=2;
    forn(i,n){
        cin>>A[i].fi>>A[i].sc;
        swap(A[i].fi,A[i].sc);
        A[i].sc = i;
        A[i].fi%=m;
    }
    sort(A+1,A+1+n);
    A[0].fi = -1;
    ll ptr = 0,ptr1 = 0;
    A[n+1].fi = INF;
    pp pos = {INF,0};
    for(ll i = 0;i<=n;++i){
        if (A[i].fi+k>=m){
            while(A[ptr1].fi<(A[i].fi+k)%m)++ptr1;
            if (pos.fi>n-i+ptr1-1){
                pos.fi = n-i+ptr1-1;
                pos.sc = (A[i].fi+k)%m;
            }
        }
        else{
            while(A[ptr].fi<A[i].fi+k)++ptr;
            if (pos.fi>ptr-i-1){
                pos.fi = ptr-i-1;
                pos.sc = A[i].fi+k;
            }
        }
    }
    cout<<pos.fi<<' '<<pos.sc<<endl;

    forn(i,n){
        if (pos.sc-k<0){
            if (A[i].fi<pos.sc || A[i].fi>pos.sc-k+m)cout<<A[i].sc<<' ';
        }
        else{
            if (pos.sc-k<A[i].fi && A[i].fi<pos.sc)cout<<A[i].sc<<' ';
        }
    }
    return 0;
}
// (i-1)%p
// l = A[i],r = A[i+1]
// 001011
// 001110
// 011010
// 110010
// 1110
// 11 - 8 11-8+1-3 = 1
// 11 10 8
// 1001100
// 4,3,2,6,