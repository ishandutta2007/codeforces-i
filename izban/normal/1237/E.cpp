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

vector<vector<vector<vector<mint>>>> mdp;

int slow(int n) {
    mint a;

    int lg = 1;
    while ((1 << lg) <= n) lg++;

    vector<vector<vector<vector<mint>>>> dp;
    if (!mdp.empty()) {
        return (mdp[lg-1][n][0][0] + mdp[lg-1][n][0][1])();
    } else {
        dp.assign(lg, vector<vector<vector<mint>>>(n+1, vector<vector<mint>>(2, vector<mint>(2))));
        for (int i = 0; i <= 1; i++) {
            for (int f = 0; f < 2; f++) {
                for (int r = 0; r < 2; r++) {
                    if (i == 0) dp[0][i][f][r] = 1;
                    else {
                        dp[0][i][f][r] = r == f;
                    }
                }
            }
        }
        for (int h = 1; h < lg; h++) {
            for (int n = 1; n < (int) dp[h].size(); n++) {
                for (int f = 0; f < 2; f++) {
                    for (int r = 0; r < 2; r++) {
                        for (int i = 0; i < n; i++) {
                            if ((i + f) % 2 == r) {
                                dp[h][n][f][r] += dp[h - 1][i][f][r ^ 1] * dp[h - 1][n - 1 - i][r ^ 1][r];
                            }
                        }
                    }
                }
            }
        }
        mdp = dp;
    }
    return (dp[lg-1][n][0][0] + dp[lg-1][n][0][1])();
}

int fast(int n) {
    vector<ll> a;
    a.push_back(0);
    a.push_back(1);
    while (a.back() < n) {
        int sz =a.size();
        a.push_back(a[sz-1] + 2*a[sz-2]+3);
    }
    for (ll x : a) if (x == n) return 1;
    for (ll x : a) if (x+1 == n) return 1;
    return 0;
}


void work() {
    vector<mint> a;
    /*for (int n = 1; n <= 1000; n++) {
        int x = slow(n);
        if (x) db(n);
    }*/
    const int N = 5e3;
    slow(N);

    for (int n = 1; n <= N; n++) {
        auto ans1 = fast(n);
        auto ans2 = slow(n);
        db3(n, ans1, ans2);
        assert(ans1 == ans2);
    }
}

int main() {
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif
//  work();

  int n;
  while (scanf("%d", &n) == 1) {
      printf("%d\n", fast(n));
  }

  return 0;
}