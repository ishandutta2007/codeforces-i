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
    int n, x;
    cin >> n >> x;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        sum += a;
    }
    if(sum == 0) {
        cout << 0;
    } else {
        cout << (abs(sum) - 1) / x + 1;
    }
}