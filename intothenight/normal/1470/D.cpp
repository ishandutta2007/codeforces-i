#include <bits/stdc++.h>
using namespace std;

template<class T>
struct graph{
	struct edge{
		int from, to;
		T cost;
	};
	int n;
	vector<edge> edges;
	vector<vector<int>> adj;
	function<bool(int)> ignore; // edge ignoration rule
	graph(int n): n(n), adj(n){ }
	int link(int u, int v, T w = 1){ // insert an undirected edge
		int id = (int)edges.size();
		adj[u].push_back(id), adj[v].push_back(id), edges.push_back({u, v, w});
		return id;
	}
	int orient(int u, int v, T w = 1){ // insert a directed edge
		int id = (int)edges.size();
		adj[u].push_back(id), edges.push_back({u, v, w});
		return id;
	}
	graph transposed() const{ // the transpose of the directed graph
		graph res(n);
		for(auto &e: edges) res.orient(e.to, e.from, e.cost);
		res.ignore = ignore;
		return res;
	}
	int degree(int u){ // the degree (outdegree if directed) of u (without the ignoration rule)
		return (int)adj[u].size();
	}
};
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n, m;
		cin >> n >> m;
		graph<int> g(n);
		for(auto i = 0; i < m; ++ i){
			int u, v;
			cin >> u >> v, -- u, -- v;
			g.link(u, v);
		}
		vector<int> vis(n), dist(n, numeric_limits<int>::max()), res;
		function<void(int)> dfs = [&](int u){
			vis[u] = true;
			if(dist[u] >= 2){
				dist[u] = 0;
				res.push_back(u);
			}
			for(auto id: g.adj[u]){
				auto &e = g.edges[id];
				int v = u ^ e.from ^ e.to;
				if(vis[v]) continue;
				ctmin(dist[v], dist[u] + 1);
			}
			for(auto id: g.adj[u]){
				auto &e = g.edges[id];
				int v = u ^ e.from ^ e.to;
				if(vis[v]) continue;
				dfs(v);
			}
		};
		dfs(0);
		if(any_of(vis.begin(), vis.end(), [&](int x){ return !x; })){
			cout << "NO\n";
		}
		else{
			cout << "YES\n" << (int)res.size() << "\n";
			for(auto u: res){
				cout << u + 1 << " ";
			}
			cout << "\n";
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