#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n;
		cin >> n;
		vector<int> a(n);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
		}
		int tot = accumulate(a.begin(), a.end(), 0);
		if(!tot){
			cout << "NO\n";
		}
		else if(tot > 0){
			sort(a.rbegin(), a.rend());
			cout << "YES\n";
			for(auto x: a){
				cout << x << " ";
			}
			cout << "\n";
		}
		else{
			sort(a.begin(), a.end());
			cout << "YES\n";
			for(auto x: a){
				cout << x << " ";
			}
			cout << "\n";
		}
		return 0;
	};
	int __tc_cnt;
	cin >> __tc_cnt;
	for(auto __tc_num = 0; __tc_num < __tc_cnt; ++ __tc_num){
		__solve_tc(__tc_num);
	}
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////