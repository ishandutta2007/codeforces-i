#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace chrono;
#define all(a) a.begin(), a.end()
#define sz(x) (int(x.size()))
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef vector<string> vs;
template<class T1, class T2>
istream &operator>>(istream &in, pair<T1, T2> &P){
	in >> P.first >> P.second;
	return in;
}
template<class T1, class T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &P){
	out << "(" << P.first << ", " << P.second << ")";
	return out;
}
template<class T>
istream &operator>>(istream &in, vector<T> &arr){
	for(auto &x: arr) in >> x;
	return in;
}
template<class T>
ostream &operator<<(ostream &out, const vector<T> &arr){
	for(auto &x: arr) out << x << ' '; cout << "\n";
	return out;
}
template<class T>
istream &operator>>(istream &in, deque<T> &arr){
	for(auto &x: arr) in >> x;
	return in;
}
template<class T>
ostream &operator<<(ostream &out, const deque<T> &arr){
	for(auto &x: arr) out << x << ' '; cout << "\n";
	return out;
}



int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<vi> cnt(200001);
	for(int i = 0; i < n; i ++){
		int x;
		cin >> x;
		for(int i = 0; x; i ++, x >>= 1){
			cnt[x].push_back(i);
		}
	}
	ll res = 9e18;
	for(auto &x: cnt){
		if(x.size() >= k){
			sort(all(x));
			res = min(res, accumulate(x.begin(), x.begin() + k, 0LL));
		}
	}
	cout << res;
	return 0;
}
/*
5 3
1 2 2 4 5

5 3
1 2 2 4 200000
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
//                                                                                                  //
//                                              _____________                                       //
//             ++++++++++                ___------------------\\\\                                  //
//           +++`+``+`+`++++        ///`````````````````````````````\\\                             //
//           ++`+`+``+++`++++  /////```````````````````````````````````\\                           //
//           +++`++`+`+``+++/////`````````````````````````````````````````\\                        //
//             +++`++`+``+///```````````|```````````````````````````````````\\                      //
//          ____++++/++++/`````````````/````````|````````|```````````````````\\                     //
//        /  /  / |    //``````````````|````````|```````|````````|````````````\\                    //
//       /  /  /  | ///````````/```````|```````||```````|````````|``````\```````\\                  //
//       | /  /   |///`````````|``````/````````|````````|````````|```````|```````\\                 //
//       |/   |   |//``|```````|``````|````````|`````````|```````|```````|````````\\                //
//       /\___|__//`|``|```````|`    |      ``:|````````|:```````|```````|```|`````|                //
//      /     /  /``|``|``````|/     |        :|     ```:|```````|```````|``++````++                //
//     /     / //```|``|``````|      |        |:        :|    ```|```````|```++``++`\               //
//     |    /  /````|``|``````/    _.::::.    |          |      |    ````|```|`++`\`|               //
//     |   /   |````|``|`````|            `                    |       ``|```++``++`|               //
//     |  /    |````|``|`````|                                 :         |``++````++|               //
//     | /     /````|``|`````|                              _.-:::.      |..`|``.`|.|               //
//     |/     /`````|``|`````|                                     `     |```|````|`|               //
//    /|      |`````|``|`````|                    :'                    .|```|````|.|               //
//   / |      |`````|``|`````|                                         /|-|``|````|`|               //
//  /  |      |`````|```\````|                                        / ||```|````|``\              //
// /   |      |`````|````|```|::                                    /_| ||```|````|``|              //
//            |`````|````|```|:|:.        `.._                    .\___/:|```|````|``|              //
//            |`````\````|```|:|::-          ``:::....           -:|:|:::|```|````|``|              //
//            |``````|```|```|:|::`|.                          .:::|:|:::|```|````|``|              //
//             \`````|```|```|:|::/|--.                     .`:|:::|:|:::/```|````|``|              //
//              |````|```|```\:|:|:|-----             _..-:|:|:|:::|:|::|````|````|`/               //
//              |````|```|````\|:|:|-------.____.....------|/::|:::|:|::|````|````|`|               //
//              |````|```|\````\:|/\___________    ________/\--\:::|:|::|````/````|`|               //
//              |````\```| \```|:/-------------\  /----------\``\::|:|::|```/`````|`|               //
//              |`````|``|  \``|/---------------\/------------\_________|```|`````|`|               //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
//                                        Created by Aeren                                          //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////