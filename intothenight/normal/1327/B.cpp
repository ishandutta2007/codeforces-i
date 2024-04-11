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
	int tt;
	cin >> tt;
	while(tt --){
		int n;
		cin >> n;
		vector<vector<int>> adj(n);
		for(int u = 0; u < n; ++ u){
			int k;
			cin >> k;
			while(k --){
				int v;
				cin >> v, -- v;
				adj[u].push_back(v);
			}
		}
		int cnt = 0, res;
		set<int> rem;
		for(int u = 0; u < n; ++ u){
			rem.insert(u);
		}
		for(int u = 0; u < n; ++ u){
			int i = 0;
			while(i < int(adj[u].size()) && !rem.count(adj[u][i])){
				++ i;
			}
			if(i == int(adj[u].size())){
				res = u;
			}
			else{
				++ cnt;
				rem.erase(adj[u][i]);
			}
		}
		if(cnt == n){
			cout << "OPTIMAL\n";
		}
		else{
			cout << "IMPROVE\n" << res + 1 << " " << *rem.begin() + 1 << "\n";
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