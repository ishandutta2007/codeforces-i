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
    	int n, m, k;
    	cin >> n >> m >> k;
    	if(n - 1 + n * (m - 1) == k) {
    		cout << "YES\n";
    	} else {
    		cout << "NO\n";
    	}
    }
}