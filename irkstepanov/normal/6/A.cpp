#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long ll;
typedef vector <vector <ll> > matrix;
ll mod = 1000000007;

matrix operator * (const matrix &a, const matrix &b)
{
    int n = a.size();
    matrix ans (n, vector <ll> (n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            for (int g = 0; g < n; g++)
        {
            ans[i][j] = ans[i][j] + a[i][g] * b[g][j];
            if (ans[i][j] >= mod) ans[i][j] %= mod;
        }
    }
    return ans;
}

matrix pw (const matrix & a, ll n)
{
    if (n == 0)
    {
        int s = a.size();
        matrix m(s, vector <ll> (s));
        for (int i = 0; i < s; i++)
            m[i][i] = 1;
        return m;
    }
    if (n == 1) return a;
    if (n % 2) return (a * pw(a, n - 1));
    matrix t = pw(a, n / 2);
    return t * t;
}

struct pt
{
    double x, y;
};

double dist (pt a, pt b)
{
    return sqrt ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

const double pi = 4 * atan(1.0);

bool istr (int a, int b, int c)
{
    return (a + b > c && a + c > b && b + c > a);
}

bool isse (int a, int b, int c)
{
    return (a + b == c || a + c == b || b + c == a);
}

int main()
{

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (istr(a, b, c) || istr(a, b, d) || istr(a, c, d) || istr(b, c, d)) {cout << "TRIANGLE"; return 0;}
    if (isse(a, b, c) || isse(a, b, d) || isse(a, c, d) || isse(b, c, d)) {cout << "SEGMENT"; return 0;}
    cout << "IMPOSSIBLE";

}