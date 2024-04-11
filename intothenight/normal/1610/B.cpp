#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n;
		cin >> n;
		vector<int> a(n);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
		}
		array<int, 2> bad{1, 2};
		for(auto i = 0; i < n; ++ i){
			if(a[i] != a[n - 1 - i]){
				bad = {a[i], a[n - 1 - i]};
				break;
			}
		}
		for(auto x: bad){
			auto b = a;
			b.erase(remove_if(b.begin(), b.end(), [&](int y){ return x == y; }), b.end());
			auto c = b;
			reverse(c.begin(), c.end());
			if(b == c){
				cout << "YES\n";
				return 0;
			}
		}
		cout << "NO\n";
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