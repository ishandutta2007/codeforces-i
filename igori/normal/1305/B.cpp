#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <bitset>
#include <queue>
#include <stack>
#include <deque>
#include <complex>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <random>
#include <functional>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

using std::map;
using std::set;
using std::bitset;
using std::vector;
using std::string;
using std::multimap;
using std::multiset;
using std::deque;
using std::queue;
using std::stack;
using std::pair;
using std::iterator;

using std::sort;
using std::stable_sort;
using std::reverse;
using std::max_element;
using std::min_element;
using std::unique;
using std::ios_base;
using std::swap;
using std::fill;

using std::setprecision;
using std::fixed;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef string S;

ll min(ll a, ll b) {return a < b ? a : b;}
ll min(int a, ll b) {return a < b ? a : b;}
ll min(ll a, int b) {return a < b ? a : b;}
ll min(int a, int b) {return a < b ? a : b;}

ll max(ll a, ll b) {return a > b ? a : b;}
ll max(int a, ll b) {return a > b ? a : b;}
ll max(ll a, int b) {return a > b ? a : b;}
ll max(int a, int b) {return a > b ? a : b;}

namespace MySpace{

};

#define F(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define fi first
#define se second
#define re return
#define all(x) (x).begin(), (x).end()
#define int long long

const int N = 510200;

int n, m, k;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i + 1 < s.size(); i++)
    {
        if (s[i] == '(' && s[i + 1] == ')') cnt++;
    }
    if (cnt == 0)
    {
        cout << 0;
        return 0;
    }
    for (int i = 0; i + 1 < s.size(); i++)
    {
        int c1 = 0;
        for (int j = 0; j <= i; j++)
        {
            if (s[j] == '(') c1++;
        }
        int c2 = 0;
        for (int j = i + 1; j < s.size(); j++)
        {
            if (s[j] == ')') c2++;
        }
        if (c1 == c2)
        {
            cout << 1 << "\n";
            cout << c1 + c2 << "\n";
            for (int j = 0; j <= i; j++)
                if (s[j] == '(') cout << j + 1 << " ";
            for (int j = i + 1; j < s.size(); j++)
                if (s[j] == ')') cout << j + 1 << " ";
            return 0;
        }
    }
}