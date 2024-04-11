#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n;
		cin >> n;
		vector<string> a(n);
		for(auto &s: a){
			cin >> s;
		}
		array<int, 3> cnt{};
		for(auto i = 0; i < n; ++ i){
			for(auto j = 0; j < n; ++ j){
				if(a[i][j] == 'X'){
					++ cnt[(i + j) % 3];
				}
			}
		}
		int c = min_element(cnt.begin(), cnt.end()) - cnt.begin();
		for(auto i = 0; i < n; ++ i){
			for(auto j = 0; j < n; ++ j){
				if(a[i][j] == 'X' && (i + j) % 3 == c){
					a[i][j] = 'O';
				}
			}
		}
		for(auto s: a){
			cout << s << "\n";
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