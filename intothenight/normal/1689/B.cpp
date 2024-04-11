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
		vector<int> a(n);
		copy_n(istream_iterator<int>(cin), n, a.begin());
		if(n == 1){
			cout << "-1\n";
			return 0;
		}
		set<int> rem;
		for(auto x = 1; x <= n; ++ x){
			rem.insert(x);
		}
		vector<int> res(n);
		for(auto i = 0; i < n - 1; ++ i){
			if(a[i] != *rem.begin()){
				res[i] = *rem.begin();
				rem.erase(rem.begin());
			}
			else{
				res[i] = *next(rem.begin());
				rem.erase(next(rem.begin()));
			}
		}
		if(a[n - 1] != *rem.begin()){
			res[n - 1] = *rem.begin();
			rem.erase(rem.begin());
		}
		else{
			res[n - 1] = res[n - 2];
			res[n - 2] = *rem.begin();
			rem.erase(rem.begin());
		}
		ranges::copy(res, ostream_iterator<int>(cout, " "));
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