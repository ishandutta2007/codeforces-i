/*#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")*/

#include <bits/stdc++.h>
using namespace std;

#define ll  long long
#define pll pair<ll,ll>
#define ff first
#define ss second
#define pb push_back
#define endl "\n"
#define F(i,a,b) for (ll i=a;i<=b;i++)

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn=1e5+30;
const ll mod=998244353;
const ll base=3e18 ;

/// you will be the best but now you just are trash
/// goal 3/7
ll a[maxn];
ll pos[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen("t.inp", "r"))
    {
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    }
    ll t;
    cin>> t;
    while (t--)
    {
        ll n;
        cin>> n;
        for (int i=1;i<=n;i++)
        {
            cin>> a[i];
            pos[a[i]]=i;
        }
        for (int i=1;i<=n;i++)
        {
            if (a[i]!=i)
            {
             //   cout <<i<<" "<<pos[i]<<endl;
                reverse(a+i,a+pos[i]+1);
                break;
            }
        }
        F(i,1,n) cout <<a[i]<<" ";
        cout <<endl;
    }
}