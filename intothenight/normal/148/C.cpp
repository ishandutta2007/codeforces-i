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
#define lambdify(x) [&](auto &&...args){ return x(forward<decltype(args)>(args)...); }
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, a, b;
	cin >> n >> a >> b;
	if(n == a + 1){
		!a ? cout << "1" : cout << "-1\n";
		return 0;
	}
	if(!b){
		cout << "1 1 ";
		for(auto i = 0; i < a; ++ i){
			cout << i + 2 << " ";
		}
		for(auto i = 0; i < n - a - 2; ++ i){
			cout << "1 ";
		}
	}
	else{
		cout << "1 ";
		int mx = 1, s = 1;
		for(auto i = 0; i < b; ++ i){
			cout << s + 1 << " ";
			mx = s + 1, s += s + 1;
		}
		for(auto i = 0; i < a; ++ i){
			cout << mx + 1 << " ";
			++ mx;
		}
		for(auto i = 0; i < n - a - b - 1; ++ i){
			cout << "1 ";
		}
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