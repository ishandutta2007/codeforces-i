#include <bits/stdc++.h>

#define int long long
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define len(v) ((int)v.size())
#define vc vector
#define pr pair
#define endl "\n"
#define endd ; exit(0)

using namespace std;

const int MAXN = 1e3;
const int INF = 1e9;
const int MOD = 1e9 + 7;

main() {
	//freopen("kek.in", "r", stdin);
	//freopen("kek.out", "w", stdout);
	ios_base::sync_with_stdio(0);
    int tek = 0;
    int maxi = 0;
    map<int, int> kk;
    int n;
    cin >> n;
    n *= 2;
    int a[n];
    for (int i = 0; i < n; i++){
        int d;
        cin >> d;
        kk[d]++;
        if (kk[d] < 2){
            tek++;
        }
        else{
            tek--;
        }
        maxi = max(maxi, tek);
    }
    cout << maxi;
}