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
    int n = 5;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int a;
            cin >> a;
            if(a) {
                cout << abs(2 - i) + abs(2 - j);
                return 0;
            }
        }
    }
}