#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
clock_t __my_start_clock = clock();
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", (clock() - __my_start_clock)*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, (clock() - __my_start_clock)*1.0/CLOCKS_PER_SEC)

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << " = "; for (auto xxxx: a) cerr << xxxx << " "; cerr << endl


using namespace std;

#ifdef LOCAL
static struct __timestamper {
  string what;
  __timestamper(const char* what) : what(what){};
  __timestamper(const string& what) : what(what){};
  ~__timestamper(){
    TIMESTAMPf("%s", what.data());
	}
} __TIMESTAMPER("end");
#else 
struct __timestamper {};
#endif

typedef long long ll;
typedef long double ld;



namespace n_mint {
    template<typename T>
    T inverse(T a, T m) {
        T u = 0, v = 1;
        while (a != 0) {
            T t = m / a;
            m -= t * a;
            swap(a, m);
            u -= t * v;
            swap(u, v);
        }
        assert(m == 1);
        return u;
    }
    template<typename T>
    class Mint {
    public:
        using Arg = T;
        using Type = typename decay<decltype(T::value)>::type;
        constexpr Mint() : value() {}
        template<typename U>
        Mint(const U &x) {
            value = normalize(x);
        }
        template<typename U>
        static Type normalize(const U &x) {
            Type v;
            if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
            else v = static_cast<Type>(x % mod());
            if (v < 0) v += mod();
            return v;
        }
        const Type &operator()() const { return value; }
        template<typename U>
        explicit operator U() const { return static_cast<U>(value); }
        constexpr static Type mod() { return T::value; }
        Mint &operator+=(const Mint &other) {
            if ((value += other.value) >= mod()) value -= mod();
            return *this;
        }
        Mint &operator-=(const Mint &other) {
            if ((value -= other.value) < 0) value += mod();
            return *this;
        }
        template<typename U>
        Mint &operator+=(const U &other) { return *this += Mint(other); }
        template<typename U>
        Mint &operator-=(const U &other) { return *this -= Mint(other); }
        Mint &operator++() { return *this += 1; }
        Mint &operator--() { return *this -= 1; }
        const Mint operator++(int) {
            Mint result(*this);
            *this += 1;
            return result;
        }
        const Mint operator--(int) {
            Mint result(*this);
            *this -= 1;
            return result;
        }
        Mint operator-() const { return Mint(-value); }
        template<typename U = T>
        typename enable_if<is_same<typename Mint<U>::Type, int>::value, Mint>::type &operator*=(const Mint &rhs) {
            value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
            return *this;
        }
        template<typename U = T>
        typename enable_if<is_same<typename Mint<U>::Type, int64_t>::value, Mint>::type &operator*=(const Mint &rhs) {
            auto q = static_cast<int64_t>(static_cast<long double>(value) * rhs.value / mod());
            value = normalize(value * rhs.value - q * mod());
            return *this;
        }
        template<typename U = T>
        typename enable_if<!is_integral<typename Mint<U>::Type>::value, Mint>::type &operator*=(const Mint &rhs) {
            value = normalize(value * rhs.value);
            return *this;
        }
        Mint &operator/=(const Mint &other) { return *this *= Mint(inverse(other.value, mod())); }
        Mint inv() const { return Mint(inverse(value, mod())); }
        template<typename U>
        friend bool operator==(const Mint<U> &lhs, const Mint<U> &rhs);
        template<typename U>
        friend bool operator<(const Mint<U> &lhs, const Mint<U> &rhs);
        template<typename U>
        friend bool operator>(const Mint<U> &lhs, const Mint<U> &rhs);
        template<typename U>
        friend std::istream &operator>>(std::istream &stream, Mint<U> &number);
    private:
        Type value;
    };
    template<typename T>
    Mint<T> abs(const Mint<T> &val) { return val; }
    template<typename T>
    bool operator==(const Mint<T> &lhs, const Mint<T> &rhs) { return lhs.value == rhs.value; }
    template<typename T, typename U>
    bool operator==(const Mint<T> &lhs, U rhs) { return lhs == Mint<T>(rhs); }
    template<typename T, typename U>
    bool operator==(U lhs, const Mint<T> &rhs) { return Mint<T>(lhs) == rhs; }
    template<typename T>
    bool operator!=(const Mint<T> &lhs, const Mint<T> &rhs) { return !(lhs == rhs); }
    template<typename T, typename U>
    bool operator!=(const Mint<T> &lhs, U rhs) { return !(lhs == rhs); }
    template<typename T, typename U>
    bool operator!=(U lhs, const Mint<T> &rhs) { return !(lhs == rhs); }
    template<typename T>
    bool operator<(const Mint<T> &lhs, const Mint<T> &rhs) { return lhs.value < rhs.value; }
    template<typename T>
    bool operator>(const Mint<T> &lhs, const Mint<T> &rhs) { return lhs.value > rhs.value; }
    template<typename T>
    Mint<T> operator+(const Mint<T> &lhs, const Mint<T> &rhs) { return Mint<T>(lhs) += rhs; }
    template<typename T, typename U>
    Mint<T> operator+(const Mint<T> &lhs, U rhs) { return Mint<T>(lhs) += rhs; }
    template<typename T, typename U>
    Mint<T> operator+(U lhs, const Mint<T> &rhs) { return Mint<T>(lhs) += rhs; }
    template<typename T>
    Mint<T> operator-(const Mint<T> &lhs, const Mint<T> &rhs) { return Mint<T>(lhs) -= rhs; }
    template<typename T, typename U>
    Mint<T> operator-(const Mint<T> &lhs, U rhs) { return Mint<T>(lhs) -= rhs; }
    template<typename T, typename U>
    Mint<T> operator-(U lhs, const Mint<T> &rhs) { return Mint<T>(lhs) -= rhs; }
    template<typename T>
    Mint<T> operator*(const Mint<T> &lhs, const Mint<T> &rhs) { return Mint<T>(lhs) *= rhs; }
    template<typename T, typename U>
    Mint<T> operator*(const Mint<T> &lhs, U rhs) { return Mint<T>(lhs) *= rhs; }
    template<typename T, typename U>
    Mint<T> operator*(U lhs, const Mint<T> &rhs) { return Mint<T>(lhs) *= rhs; }
    template<typename T>
    Mint<T> operator/(const Mint<T> &lhs, const Mint<T> &rhs) { return Mint<T>(lhs) /= rhs; }
    template<typename T, typename U>
    Mint<T> operator/(const Mint<T> &lhs, U rhs) { return Mint<T>(lhs) /= rhs; }
    template<typename T, typename U>
    Mint<T> operator/(U lhs, const Mint<T> &rhs) { return Mint<T>(lhs) /= rhs; }
    template<typename T, typename U>
    Mint<T> bin(const Mint<T> &a, const U &b) {
        assert(b >= 0);
        Mint<T> x = a, res = 1;
        U p = b;
        while (p > 0) {
            if (p & 1) res *= x;
            x *= x;
            p >>= 1;
        }
        return res;
    }
    template <typename T>
    Mint<T> inv(const Mint<T> &a) {
        return inverse(a(), Mint<T>::mod());
    }
    template<typename T>
    string to_string(const Mint<T> &number) {
        return std::to_string(number());
    }
    template<typename T>
    std::ostream &operator<<(std::ostream &stream, const Mint<T> &number) {
        return stream << number();
    }
    template<typename T>
    std::istream &operator>>(std::istream &stream, Mint<T> &number) {
        typename common_type<typename Mint<T>::Type, int64_t>::type x;
        stream >> x;
        number.value = Mint<T>::normalize(x);
        return stream;
    }
    template<typename T, typename Enabled = void>
    struct is_modular : std::false_type {};
    template<typename T>
    struct is_modular<T, typename enable_if<
            is_same<T, Mint<typename T::Arg>>::value &&
            is_integral<typename T::Type>::value
    >::type> : true_type {};
    struct DynamicMod {
        static int value;
    };
    constexpr int MOD = 998244353;
    using mint = Mint<std::integral_constant<decay<decltype(MOD)>::type, MOD>>;
}
using namespace n_mint;

int solve(int n, int m, vector<pair<pair<int, int>, pair<int, int>>> a) {
    vector<char> u1(n), u2(m);
    for (auto o : a) {
        if (o.first.first == o.second.first) {
            u1[o.first.first] = 1;
            u2[o.first.second] = 1;
            u2[o.second.second] = 1;
        } else {
            u1[o.first.first] = 1;
            u1[o.second.first] = 1;
            u2[o.first.second] = 1;
        }
    }

    auto solve = [&](vector<char> used) {
        int n = used.size();
        vector<vector<mint>> dp(n + 1, vector<mint>(n + 1));
        dp[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < (int)dp[i].size(); j++) {
                dp[i + 1][j] += dp[i][j];
                if (i + 1 < n && j + 1 < (int)dp[i].size() && !used[i] && !used[i + 1]) {
                    dp[i + 2][j + 1] += dp[i][j];
                }
            }
        }
        return dp[n];
    };
    auto left = solve(u1);
    auto right = solve(u2);
//    dbv(left);
//    dbv(right);

    int K = max(n, m) + 5;
    vector<vector<mint>> C(K, vector<mint>(K));
    C[0][0] = 1;
    for (int i = 0; i < K - 1; i++) {
        for (int j = 0; j <= i; j++) {
            C[i + 1][j] += C[i][j];
            C[i + 1][j + 1] += C[i][j];
        }
    }

    auto getC = [&](int n, int k) {
        if (n < 0 || k > n || k < 0) return mint(0);
        return C[n][k];
    };

    vector<mint> fct(K);
    fct[0] = 1;
    for (int i = 1; i < K; i++) fct[i] = fct[i - 1] * i;

    int freel = n, freer = m;
    for (auto x : u1) freel -= x;
    for (auto x : u2) freer -= x;

    assert(left.size() > n);
    assert(right.size() > m);
    mint ans = 0;
    for (int cnt1 = 0; cnt1 <= n; cnt1++) {
        for (int cnt2 = 0; cnt2 <= m; cnt2++) {
            ans += left[cnt1] * right[cnt2] * getC(freer - 2 * cnt2, cnt1) * getC(freel - 2 * cnt1, cnt2) * fct[cnt1] * fct[cnt2];
        }
    }
    return ans();
}

int main() {
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif
//  printf("%d\n", solve(3600, 3600, vector<pair<pair<int, int>, pair<int, int>>>()));
//  return 0;

  int n, m, k;
  while (scanf("%d%d%d", &n, &m, &k) == 3) {
      vector<pair<pair<int, int>, pair<int, int>>> a(k);
      for (int i = 0; i < k; i++) {
          scanf("%d%d%d%d", &a[i].first.first, &a[i].first.second, &a[i].second.first, &a[i].second.second);
          a[i].first.first--;
          a[i].first.second--;
          a[i].second.first--;
          a[i].second.second--;
      }
      printf("%d\n", solve(n, m, a));
  }

  return 0;
}