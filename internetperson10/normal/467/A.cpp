#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, s=0, a, b;
    cin >> n;
    while(n--) {
        cin >> a >> b;
        if(b-a>1)
            s++;
    }
    cout << s;
}