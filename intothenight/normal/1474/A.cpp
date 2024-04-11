#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n;
		string b;
		cin >> n >> b;
		for(auto i = 0, prev = -1; i < n; ++ i){
			if(b[i] & 1){
				if(prev == 2){
					cout << 0;
					prev = 1;
				}
				else{
					cout << 1;
					prev = 2;
				}
			}
			else{
				if(prev == 1){
					cout << 0;
					prev = 0;
				}
				else{
					cout << 1;
					prev = 1;
				}
			}
		}
		cout << "\n";
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