#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--)
    {
        int l, r;
        cin >> l >> r;
        int b = r / 2 + 1;
        if(b < l)
        {
            b = l;
        }
        cout << r % b << '\n';
    }
}