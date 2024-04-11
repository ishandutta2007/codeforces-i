#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	int l = 1, r = m;
	while(l <= r){
		if(l == r){
			int u = 1, d = n;
			while(u <= d){
				if(u == d){
					cout << u << " " << l << "\n";
				}
				else{
					cout << u << " " << l << "\n" << d << " " << l << "\n";
				}
				++ u, -- d;
			}
		}
		else{
			int u = 1, d = n;
			while(u <= n){
				cout << u << " " << l << "\n" << d << " " << r << "\n";
				++ u, -- d;
			}
		}
		++ l, -- r;
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