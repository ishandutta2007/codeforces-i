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
    	int n;
    	cin >> n;
    	if(n % 3 == 0)
    	{
    		cout << n / 3 << ' ' << n / 3 << '\n';
    		continue;
    	}
    	if(n % 3 == 1)
    	{
    		cout << n / 3 + 1 << ' ' << n / 3 << '\n';
    		continue;
    	}
    	cout << n / 3 << ' ' << n / 3 + 1 << '\n';
    }
}