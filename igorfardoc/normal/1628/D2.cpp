#include<bits/stdc++.h>
#define maxn 1000000
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

const int mod = 1000000007;
int fact[maxn + 1], rfact[maxn + 1];
int p[maxn + 1], rp[maxn + 1];

int bin_pow(int a, int b) {
    if(b == 0) return 1;
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
    if(n < 0 || k < 0 || k > n) return 0;
    int res = ((ll)fact[n] * rfact[k]) % mod;
    res = ((ll)res * rfact[n - k]) % mod;
    return res;
}

void precalc() {
    fact[0] = 1;
    for(int i = 1; i <= maxn; i++) {
        fact[i] = ((ll)fact[i - 1] * i) % mod;
        rfact[i] = obr(fact[i]);
    }
    rfact[0] = rfact[1];
    p[0] = 1;
    rp[0] = 1;
    int other = obr(2);
    for(int i = 1; i <= maxn; i++) {
        p[i] = p[i - 1] * 2 % mod;
        rp[i] = (ll)rp[i - 1] * other % mod;
    }
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
    precalc();
    int t;
    cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        int ans = 0;
        if(n == m) {
            cout << (ll)n * k % mod << '\n';
            continue;
        }
        for(int i = n; i >= 1; i--) {
            ans = (ans + (ll)c(n - i - 1, m - i) * i % mod * k % mod * rp[n - i] % mod) % mod;
        }
        cout << ans << '\n';
    }
}