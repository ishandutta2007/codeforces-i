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
        int n;
        cin >> n;
        vi a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int last = 0;
        for(int i = n - 2; i >= 0; i--) {
            if(a[i] < a[i + 1]) {
                last = i + 1;
                break;
            }
        }
        int last1 = 0;
        for(int i = last - 2; i >= 0; i--) {
            if(a[i] > a[i + 1]) {
                last1 = i + 1;
                break;
            }
        }
        cout << last1 << '\n';
    }
}