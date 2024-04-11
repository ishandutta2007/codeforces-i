#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>
 
#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <stack>
#include <functional>
#include <unordered_set>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

using namespace std;

using ull = unsigned long long;

// const int P = 998244353;

// int norm(int x) { return x >= P ? x - P : x; }
// int reduce(int x) { return x < 0 ? x + P : x; }
// int neg(int x) { return x ? P - x : 0; }
// void add(int& x, int y) { if ((x += y - P) < 0) x += P; }
// void sub(int& x, int y) { if ((x -= y) < 0) x += P; }
// void fam(int& x, int y, int z) { x = (x + y * (ull)z) % P; }
// int mpow(int x, unsigned k) {
// 	if (k == 0) return 1;
// 	int ret = mpow(x * (ull)x % P, k >> 1);
// 	if (k & 1) ret = ret * (ull)x % P;
// 	return ret;
// }
// int quo2(int x) { return ((x & 1) ? x + P : x) >> 1; }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;
	while (T--) {
		int N; string s; cin >> N >> s;
		int k = N - 1;
		for (int i = 1; i != N; ++i)
			if (s[i] > s[i - 1]) { k = i - 1; break; }
		if (N >= 2 && s[0] == s[1]) k = 0;
		for (int i = 0; i <= k; ++i) cout << s[i];
		for (int i = k; i >= 0; --i) cout << s[i];
		cout << '\n';
	}

	return 0;
}