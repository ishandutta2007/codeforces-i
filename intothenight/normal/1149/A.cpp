#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/rope"
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> cnt(3);
	for(auto i = 0; i < n; ++ i){
		int x;
		cin >> x;
		++ cnt[x];
	}
	if(cnt[2]){
		cout << "2 ";
		-- cnt[2];
	}
	if(!cnt[1]){
		for(auto i = 0; i < cnt[2]; ++ i){
			cout << "2 ";
		}
	}
	else{
		for(auto i = 0; i < (cnt[1] % 2 ? cnt[1] : cnt[1] - 1); ++ i){
			cout << "1 ";
		}
		for(auto i = 0; i < cnt[2]; ++ i){
			cout << "2 ";
		}
		if(cnt[1] % 2 == 0){
			cout << "1 ";
		}
	}
	return 0;
}

/*
1 2 3 4 5 6 7 9 11
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////