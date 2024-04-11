#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
//#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

int main()
{
    int n;
    cin >> n;
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = i;
        int cnt = 0;
        for (int j = 2; j * j <= x; j++)
        {
            if (x % j) continue;
            cnt++;
            while (x % j == 0) x /= j;
        }
        if (x != 1)
            cnt++;
        if (cnt == 2)
            res++;
    }
    printf("%d\n", res);
    return 0;
}