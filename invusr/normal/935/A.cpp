#include <bits/stdc++.h>
using namespace std;

typedef unsigned u32;
typedef long long s64;
typedef unsigned long long u64;

typedef double r32;
typedef long double r64;

template <class T>
inline bool relax(T &a, const T &b)
{
	if (b > a)
	{
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool tense(T &a, const T &b)
{
	if (b < a)
	{
		a = b;
		return true;
	}
	return false;
}

int main()
{
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);

	int n;
	cin >> n;

	int res = 0;
	for (int i = 1; i <= n; ++i)
		if (n % i == 0 && n / i > 1)
			++res;

	cout << res << endl;

	fclose(stdin);
	fclose(stdout);
	return 0;
}