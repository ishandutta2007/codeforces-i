#include <bits/stdc++.h>

#define int long long
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define len(v) ((int)v.size())
#define vc vector
#define pr pair
#define endl "\n"

using namespace std;

main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;

	for (int i = 2; i <= n + 1; i++){
		if (i == 2){
			
			cout << 2 << endl;
		}
		else
			cout << (i * i) * (i - 1) - (i - 2) << endl;
	}
}