#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 1000000+7;
const ll INF = 10E16;

ll A[DIM],B[DIM];
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
    ll n,m,p;
    cin>>n>>m>>p;
    forn(i,n){
        ll x;
        cin>>x;
        if (x%p==0)A[i] = 1;
    }
    forn(i,m){
        ll x;
        cin>>x;
        if (x%p!=0){
            forn(j,n){
                if (A[j]==0){

                    ll ans = (i-1)+(j-1);
                    cout<<ans<<endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}