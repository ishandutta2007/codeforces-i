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
	int a[n];
	int mini = 1000000000;
	int maxi = 0;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		mini = min(mini, a[i]);
		maxi = max(maxi, a[i]);
	}
	bool prav = 1;
	if ((maxi + mini) % 2 == 0){
		int mid = (mini + maxi) / 2; 
		for (int i = 0; i < n; i++){
			if (a[i] != mid && a[i] != maxi && a[i] != mini){
				prav = 0;
			}
		}
	}
	else{
		for (int i = 0; i < n; i++){
			if (a[i] != maxi && a[i] != mini){
				prav = 0;
			}
		}
	}
	if (prav){
		cout << "YES";
	}
	else{
		cout << "NO";
	}
}