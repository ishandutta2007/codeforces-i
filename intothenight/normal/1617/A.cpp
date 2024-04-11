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
		string s, t;
		cin >> s >> t;
		if(t == "abc" && ranges::find(s, 'a') != s.end()){
			ranges::sort(s, [&](auto c, auto d){
				if(c == 'b' || c == 'c'){
					c ^= 'b' ^ 'c';
				}
				if(d == 'b' || d == 'c'){
					d ^= 'b' ^ 'c';
				}
				return c < d;
			});
		}
		else{
			ranges::sort(s);
		}
		cout << s << "\n";
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