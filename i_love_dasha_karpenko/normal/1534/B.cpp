//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const ll DIM = 4E5+7;
ll A[DIM];
void solve(){
    ll n;
    cin>>n;
    for(ll i = 1;i<=n;++i)
        cin>>A[i];
    ll res = 0;
    for(ll i = 1;i<=n;++i){
        if (A[i]>A[i-1] && A[i]>A[i+1]) {
            res += A[i] - max(A[i - 1], A[i + 1]);
            A[i] = max(A[i - 1], A[i + 1]);
        }
    }
    for(ll i = 1;i<=n;++i){
        res+=abs(A[i]-A[i-1]);
    }
    res+=A[n];
    cout<<res<<endl;
    for(ll i = 1;i<=n;++i)
        A[i] = 0;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}