#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            while(!(x%2)) {
                nums[i]++;
                x /= 2;
            }
        }
        sort(nums.begin(), nums.end());
        int ans = nums[0];
        for(int i = 1; i < n; i++) {
            if(nums[i]) ans++;
        }
        cout << ans << '\n';
    }
}