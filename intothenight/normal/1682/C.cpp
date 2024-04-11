#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n;
		cin >> n;
		map<int, int> cnt;
		for(auto i = 0; i < n; ++ i){
			int x;
			cin >> x;
			++ cnt[x];
		}
		auto one = ranges::find_if(cnt, [&](auto x){ return x.second == 1; });
		if(one == cnt.end()){
			one = cnt.begin();
		}
		array<int, 2> len{1, 1};
		for(auto it = cnt.begin(); it != cnt.end(); ++ it){
			if(it == one){
				continue;
			}
			if(it->second >= 2){
				++ len[0];
				++ len[1];
			}
			else{
				++ *ranges::min_element(len);
			}
		}
		cout << ranges::min(len) << "\n";
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