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

const ll DIM = 1E3+7;
const ll INF = 2E15;
const ld eps = 0.0000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> V1,V2;
        forn(i,n*2){
            ll x;
            cin>>x;
            if (x%2)V1.pb(i);
            else V2.pb(i);
        }
        if (V1.size()%2!=0){
            V1.pop_back();
            V2.pop_back();
        }
        else{
            if (V1.size()<V2.size()){
                swap(V1,V2);
            }
            V1.pop_back();
            V1.pop_back();
        }
        for(ll i = 0;i<V1.size();i+=2)cout<<V1[i]<<' '<<V1[i+1]<<endl;
        for(ll i = 0;i<V2.size();i+=2)cout<<V2[i]<<' '<<V2[i+1]<<endl;

        //cout<<endl;
    }
    return 0;
}
// 001011
// 001110
// 011010
// 110010
// 1110
// 11 - 8 11-8+1-3 = 1
// 11 10 8
// 1001100
// 4,3,2,6,