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

const ll maxn=2e5+100;
const ll mod=1e9+7;
const ll base=3e18;

/// you will be the best but now you just are trash
/// goal 6/7


ll a[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("shortestpath.inp", "r"))
    {
        freopen("shortestpath.inp", "r", stdin);
        freopen("shortestpath.out", "w", stdout);
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
        }
        bool chk=true;
        for (int i=1;i<=n-1;i++)
        {
            if (a[i]>a[i+1]) chk=false;
        }
        if (chk)
        {
            cout <<0<<endl;
            continue;
        }
        else
        {
            if (a[n]<0||a[n-1]>a[n])
            {
                cout <<-1<<endl;
                continue;
            }
            cout <<n-2<<endl;
            for (int i=1;i<=n-2;i++)
            {
                cout <<i<<" "<<n-1<<" "<<n<<endl;
            }
        }

    }
}