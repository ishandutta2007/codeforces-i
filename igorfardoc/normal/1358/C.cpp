#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;


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
    while(t--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        --x1;
        --y1;
        --x2;
        --y2;
        int maxd = min(x2 - x1, y2 - y1);
        ll ans = (ll)maxd * (maxd - 1);
        ans += (ll)maxd * (max(x2 - x1, y2 - y1) - min(x2 - x1, y2 - y1) + 1);
        cout << ans + 1 << '\n';
    } 

}