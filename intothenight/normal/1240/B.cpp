#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n;
		cin >> n;
		vector<int> a(n);
		vector<vector<int>> appear(n);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i], -- a[i];
			appear[a[i]].push_back(i);
		}
		vector<int> seq;
		for(auto x = 0; x < n; ++ x){
			if(!appear[x].empty()){
				seq.push_back(x);
			}
		}
		int res = numeric_limits<int>::max();
		for(auto i = 0, j = 1; i < (int)seq.size(); ++ i){
			while(j < (int)seq.size() && (i == j || appear[seq[j - 1]].back() < appear[seq[j]].front())){
				++ j;
			}
			ctmin(res, (int)seq.size() - j + i);
		}
		cout << res << "\n";
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