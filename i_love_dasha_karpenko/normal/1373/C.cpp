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

const ll DIM = 2E6+7;
const ll INF = 2E15;
const ld eps = 0.0000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        ll sum = 0;
        ll res = 0;
        ll bound = 0;
        for(char to:s){
            if (to=='+')++sum;
            else --sum;
            bound = max(bound,-sum);
        }
        sum = 0;
        ll mx = 0;
        res+=bound+1;
        for(ll i = 0;i<s.length()-1;++i){
            char to = s[i];
            ll f;
            if (to=='+'){
                ++sum;
                f = 1;
            }
            else{
                --sum;
                f = -1;
            }
            mx = max(mx,-sum);

            res+=(bound-mx+1);
        }

        cout<<res<<endl;
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