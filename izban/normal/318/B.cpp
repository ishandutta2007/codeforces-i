#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 20;
const int inf = 1000000007;
const int mod = 1000000007;

string s;

ll solve() {
    int cnt = 0;
    ll res = 0;
    for (int i = 0; i + 5 <= s.length(); i++) {
        cnt += s.substr(i, 5) == "heavy";
        if (s.substr(i, 5) == "metal") res += cnt;
    }
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    while (cin >> s) cout << solve() << endl;
    
	return 0;
}