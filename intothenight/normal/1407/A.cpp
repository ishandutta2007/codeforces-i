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
		auto test = [&](){
			int res = 0;
			for(auto i = 0; i < (int)a.size(); i += 2){
				res += a[i];
			}
			for(auto i = 1; i < (int)a.size(); i += 2){
				res -= a[i];
			}
			return !res;
		};
		auto answer = [&](){
			cout << (int)a.size() << "\n";
			for(auto x: a){
				cout << x << " ";
			}
			cout << "\n";
		};
		if(test()){
			answer();
			return 0;
		}
		for(auto i = 0; i < n; ++ i){
			int x = a[i];
			a.erase(a.begin() + i);
			if(test()){
				answer();
				return 0;
			}
			a.insert(a.begin() + i, x);
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