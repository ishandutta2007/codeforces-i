#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int fact[1000001], rfact[1000001];
const int mod = 1000000007;

int bin_pow(int a, int b) {
    if(b == 0) {
        return 1;
    }
    int res = bin_pow(a, b >> 1);
    res = ((ll)res * res) % mod;
    if(b & 1) {
        res = ((ll)res * a) % mod;
    }
    return res;
}

int obr(int a) {
    return bin_pow(a, mod - 2);
}

int c(int n, int k) {
    if(n < 0 || k < 0 || n < k) {
        return 0;
    }
    int res = ((ll)fact[n] * rfact[k]) % mod;
    res = ((ll)res * rfact[n - k]) % mod;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    fact[0] = 1;
    for(int i = 1; i <= 1000000; i++) {
        fact[i] = ((ll)fact[i - 1] * i) % mod;
        rfact[i] = obr(fact[i]);
    }
    rfact[0] = rfact[1];
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = (ans + c(n - 1, i)) % mod;
    }
    ans = ((ll)fact[n] - ans + mod) % mod;
    cout << ans;
}