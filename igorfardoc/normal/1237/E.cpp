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
    int n;
    cin >> n;
    int now = 1;
    while(now <= n) {
    	if(n == now || n == now + 1) {
    		cout << 1;
    		return 0;
    	}
    	if(now % 2 == 1) {
    		now = 1 + now + now + 1;
    	} else {
    		now = 1 + now + now;
    	}
    }
    cout << 0;
}