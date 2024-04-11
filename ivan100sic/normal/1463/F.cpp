// Retired?
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,tune=native")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

vector<int> solve(int n, int x, int y) {
  int w = max(x, y);
  vector<int> val(n+1, -1);
  val[0] = 0;
  vector<int> ol(1 << w, -1), nu = ol;
  ol[0] = 0;
  const int m1 = 1 << (x-1);
  const int m2 = 1 << (y-1);
  const int m12 = m1 | m2;
  const int mw = (1 << w) - 1;
  for (int i=1; i<=n; i++) {
    memset(nu.data(), 255, sizeof(int) << w);
    for (int j=0; j<(1<<w); j++) {
      // stavi?
      if (j & m12) {
        // ne moze
      } else {
        int j2 = ((j << 1) | 1) & mw;
        nu[j2] = max(nu[j2], ol[j] + 1);
      }

      // nemoj
      {
        int j2 = (j << 1) & mw;
        nu[j2] = max(nu[j2], ol[j]);
      }
    }

    val[i] = *max_element(begin(nu), end(nu));
    swap(ol, nu);
  }
  return val;
}

int find_period(int x, int y) {
  int n = 4*x*y+5;
  auto a = solve(n, x, y);

  for (int p=1; 4*p<=n; p++) {
    int ok = 1;
    // check
    for (int i=p; i+2*p<=n; i++) {
      if (a[i+2*p] - a[i+p] != a[i+p] - a[i]) {
        ok = 0;
        break;
      }
    }

    if (ok) {
      return p;
    }
  }

  return -1;
}

array<int, 3> find_period_2(int x, int y) {
  int n = 4*x*y+5;
  auto a = solve(n, x, y);

  for (int e=1; e<=n/2; e++) {
    for (int p=1; p<=e; p++) {
      int ok = 1;
      // check
      for (int i=e; i+p<=n; i++) {
        if (a[i] - a[i-p] != a[i+p] - a[i]) {
          ok = 0;
          break;
        }
      }

      if (ok) {
        return {e, p, a[e] - a[e-p]};
      }
    }
  }

  return {-1, -1, -1};
}

void find_all_periods(int h) {

  mutex mtx;
  vector<thread> vt;

  for (int x=1; x<=h; x++) {
    for (int y=x; y<=h; y++) {
      auto t = thread([x, y, &mtx]() {
        auto t = find_period_2(x, y);
        unique_lock lck(mtx);
        cerr << '{' << x << ',' << y << ',' << t[0] << ',' << t[1] << ',' << t[2] << "},\n";
      });

      vt.emplace_back(move(t));
    }
  }

  for (auto& t : vt) {
    t.join();
  }
}

const int periods[22][22] = {
  {2, 3, 2, 5, 2, 7, 2, 9, 2, 11, 2, 13, 2, 15, 2, 17, 2, 19, 2, 21, 2, 23},
  {3, 4, 5, 6, 7, 4, 9, 10, 11, 4, 13, 14, 15, 4, 17, 18, 19, 4, 21, 22, 23, 4},
  {2, 5, 6, 7, 6, 9, 6, 11, 6, 13, 12, 15, 12, 17, 6, 19, 18, 21, 18, 23, 6, 25},
  {5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 8, 17, 18, 19, 20, 21, 22, 23, 8, 25, 26},
  {2, 7, 6, 9, 10, 11, 20, 13, 10, 15, 10, 17, 26, 19, 10, 21, 40, 23, 20, 25, 20, 27},
  {7, 4, 9, 10, 11, 12, 13, 14, 15, 12, 17, 18, 19, 12, 21, 22, 23, 12, 25, 26, 27, 24},
  {2, 9, 6, 11, 20, 13, 14, 15, 42, 34, 28, 19, 14, 21, 14, 23, 34, 50, 62, 27, 14, 29},
  {9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 38, 20, 21, 22, 23, 24, 25, 26, 27, 28, 58, 30},
  {2, 11, 6, 13, 10, 15, 42, 17, 18, 19, 72, 21, 36, 46, 18, 25, 18, 27, 18, 29, 18, 62},
  {11, 4, 13, 14, 15, 12, 34, 18, 19, 20, 21, 22, 69, 40, 25, 26, 27, 20, 29, 30, 31, 20},
  {2, 13, 12, 15, 10, 17, 28, 38, 72, 21, 22, 23, 110, 75, 66, 54, 44, 29, 50, 31, 22, 33},
  {13, 14, 15, 8, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 58, 30, 62, 24, 33, 34},
  {2, 15, 12, 17, 26, 19, 14, 21, 36, 69, 110, 25, 26, 27, 156, 116, 78, 62, 52, 66, 84, 35},
  {15, 4, 17, 18, 19, 12, 21, 22, 46, 40, 75, 26, 27, 28, 29, 30, 124, 84, 99, 68, 35, 56},
  {2, 17, 6, 19, 10, 21, 14, 23, 18, 25, 66, 27, 156, 29, 30, 31, 210, 33, 120, 35, 60, 74},
  {17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 54, 28, 116, 30, 31, 32, 33, 34, 175, 36, 111, 76},
  {2, 19, 18, 21, 40, 23, 34, 25, 18, 27, 44, 58, 78, 124, 210, 33, 34, 35, 272, 185, 136, 117},
  {19, 4, 21, 22, 23, 12, 50, 26, 27, 20, 29, 30, 62, 84, 33, 34, 35, 36, 37, 38, 39, 144},
  {2, 21, 18, 23, 20, 25, 62, 27, 18, 29, 50, 62, 52, 99, 120, 175, 272, 37, 38, 39, 342, 246},
  {21, 22, 23, 8, 25, 26, 27, 28, 29, 30, 31, 24, 66, 68, 35, 36, 185, 38, 39, 40, 41, 42},
  {2, 23, 6, 25, 20, 27, 14, 58, 18, 31, 22, 33, 84, 35, 60, 111, 136, 39, 342, 41, 42, 43},
  {23, 4, 25, 26, 27, 24, 29, 30, 62, 20, 33, 34, 35, 56, 74, 76, 117, 144, 246, 42, 43, 44}
};

vector<vector<int>> periods2 = {
  {1,1,2,2,1},
  {1,2,3,3,1},
  {1,3,2,2,1},
  {1,4,5,5,2},
  {1,5,2,2,1},
  {1,6,7,7,3},
  {1,7,2,2,1},
  {1,8,9,9,4},
  {1,9,2,2,1},
  {1,10,11,11,5},
  {1,11,2,2,1},
  {2,2,4,4,2},
  {1,13,2,2,1},
  {1,12,13,13,6},
  {2,3,5,5,2},
  {2,4,6,6,2},
  {2,5,7,7,3},
  {2,6,4,4,2},
  {1,14,15,15,7},
  {2,7,9,9,4},
  {2,9,11,11,5},
  {2,8,10,10,4},
  {2,10,4,4,2},
  {2,11,13,13,6},
  {2,12,14,14,6},
  {3,4,7,7,3},
  {3,3,6,6,3},
  {3,5,7,2,1},
  {3,6,9,9,3},
  {3,8,11,11,5},
  {3,7,7,2,1},
  {2,13,15,15,7},
  {1,15,2,2,1},
  {3,9,6,6,3},
  {3,10,13,13,6},
  {2,14,4,4,2},
  {3,11,13,2,1},
  {3,12,15,15,6},
  {4,4,8,8,4},
  {4,5,9,9,4},
  {3,13,13,2,1},
  {4,6,10,10,4},
  {4,7,17,11,5},
  {4,9,19,13,6},
  {4,10,14,14,6},
  {4,8,12,12,4},
  {4,11,15,15,7},
  {1,16,17,17,8},
  {4,12,8,8,4},
  {3,14,17,17,8},
  {5,5,10,10,5},
  {4,13,17,17,8},
  {2,15,17,17,8},
  {5,6,11,11,5},
  {5,7,21,2,1},
  {5,8,21,13,6},
  {5,9,11,2,1},
  {5,10,15,15,5},
  {5,11,11,2,1},
  {5,12,25,17,8},
  {6,6,12,12,6},
  {6,7,13,13,6},
  {6,8,14,14,6},
  {6,9,15,15,6},
  {4,14,18,18,8},
  {5,13,27,2,1},
  {6,11,27,17,8},
  {6,10,14,4,2},
  {6,12,18,18,6},
  {3,15,6,6,3},
  {7,7,14,14,7},
  {7,8,15,15,7},
  {7,9,43,2,1},
  {7,10,43,17,8},
  {6,13,29,19,9},
  {2,16,18,18,8},
  {5,14,19,19,9},
  {7,11,29,2,1},
  {4,15,33,19,9},
  {7,12,30,19,9},
  {8,8,16,16,8},
  {8,9,17,17,8},
  {8,10,18,18,8},
  {8,11,49,19,9},
  {6,14,14,4,2},
  {9,9,18,18,9},
  {8,12,20,20,8},
  {7,13,15,2,1},
  {1,17,2,2,1},
  {9,10,19,19,9},
  {9,11,73,2,1},
  {5,15,10,10,5},
  {7,14,21,21,7},
  {3,16,19,19,9},
  {8,13,34,21,10},
  {9,12,21,21,9},
  {10,10,20,20,10},
  {10,11,21,21,10},
  {10,12,22,22,10},
  {9,13,37,2,1},
  {10,13,81,23,11},
  {11,11,22,22,11},
  {11,12,23,23,11},
  {9,14,57,23,11},
  {8,14,34,22,10},
  {4,16,20,20,8},
  {6,15,21,21,9},
  {11,13,111,2,1},
  {12,12,24,24,12},
  {7,15,15,2,1},
  {12,13,25,25,12},
  {11,14,89,25,12},
  {13,13,26,26,13},
  {8,15,37,23,11},
  {10,14,42,4,2},
  {2,17,19,19,9},
  {5,16,21,21,10},
  {13,14,27,27,13},
  {10,15,25,25,10},
  {12,14,26,26,12},
  {3,17,19,2,1},
  {6,16,22,22,10},
  {12,15,27,27,12},
  {13,15,157,2,1},
  {9,15,21,6,3},
  {14,14,28,28,14},
  {11,15,67,2,1},
  {7,16,34,23,11},
  {1,18,19,19,9},
  {4,17,35,21,10},
  {8,16,24,24,8},
  {9,16,41,25,12},
  {15,15,30,30,15},
  {10,16,42,26,12},
  {14,15,29,29,14},
  {5,17,41,2,1},
  {11,16,69,27,13},
  {12,16,28,28,12},
  {2,18,4,4,2},
  {5,18,41,23,11},
  {14,16,30,30,14},
  {7,17,35,2,1},
  {8,17,39,25,12},
  {15,16,31,31,15},
  {9,17,19,2,1},
  {16,16,32,32,16},
  {6,17,23,23,11},
  {10,17,43,27,13},
  {12,17,74,29,14},
  {13,17,79,2,1},
  {4,18,22,22,10},
  {3,18,21,21,9},
  {11,17,45,2,1},
  {10,19,47,29,14},
  {15,19,121,2,1},
  {14,17,141,31,15},
  {16,17,33,33,16},
  {17,17,34,34,17},
  {8,18,38,26,12},
  {6,18,12,12,6},
  {7,18,59,25,12},
  {15,17,211,2,1},
  {12,19,77,31,15},
  {9,18,27,27,9},
  {13,18,80,31,15},
  {15,18,33,33,15},
  {6,19,25,25,12},
  {12,18,30,30,12},
  {3,19,19,2,1},
  {11,18,47,29,14},
  {16,18,34,34,16},
  {17,18,35,35,17},
  {18,18,36,36,18},
  {14,18,86,4,2},
  {4,19,23,23,11},
  {5,20,25,25,10},
  {8,19,40,27,13},
  {2,20,22,22,10},
  {5,19,21,2,1},
  {13,16,131,29,14},
  {9,19,19,2,1},
  {1,19,2,2,1},
  {1,20,21,21,10},
  {7,20,27,27,13},
  {18,19,37,37,18},
  {2,21,23,23,11},
  {7,19,63,2,1},
  {3,20,23,23,11},
  {10,20,30,30,10},
  {10,18,22,4,2},
  {1,21,2,2,1},
  {11,20,50,31,15},
  {13,19,53,2,1},
  {14,20,86,34,16},
  {16,19,193,35,17},
  {8,20,28,28,12},
  {14,19,115,33,16},
  {6,20,26,26,12},
  {17,19,273,2,1},
  {19,20,39,39,19},
  {4,20,8,8,4},
  {7,21,14,14,7},
  {2,19,21,21,10},
  {3,21,6,6,3},
  {11,19,51,2,1},
  {9,21,21,6,3},
  {10,21,49,31,15},
  {6,21,27,27,12},
  {19,19,38,38,19},
  {11,21,23,2,1},
  {13,20,83,33,16},
  {15,20,35,35,15},
  {2,22,4,4,2},
  {12,21,51,33,15},
  {14,21,35,35,14},
  {1,22,23,23,11},
  {16,20,36,36,16},
  {18,20,38,38,18},
  {9,20,45,29,14},
  {17,20,205,37,18},
  {20,20,40,40,20},
  {4,21,25,25,12},
  {5,21,21,2,1},
  {12,20,28,8,4},
  {19,21,343,2,1},
  {21,21,42,42,21},
  {3,22,25,25,12},
  {9,22,73,31,15},
  {8,21,69,29,14},
  {7,22,29,29,14},
  {4,22,26,26,12},
  {15,21,63,6,3},
  {5,22,45,27,13},
  {18,21,39,39,18},
  {12,22,54,34,16},
  {13,21,85,2,1},
  {6,22,26,4,2},
  {10,22,22,4,2},
  {8,22,30,30,14},
  {11,22,33,33,11},
  {17,21,137,2,1},
  {16,21,131,37,18},
  {20,21,41,41,20},
  {14,22,58,4,2},
  {13,22,56,35,17},
  {15,22,95,37,18},
  {21,22,43,43,21},
  {16,22,98,38,18},
  {19,22,267,41,20},
  {17,22,138,39,19},
  {18,22,146,4,2},
  {22,22,44,44,22},
  {20,22,42,42,20},
};

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  // find_all_periods(22);
  // return 0;

  int n, x, y;
  cin >> n >> x >> y;

  if (x > y) swap(x, y);

  for (auto v : periods2) {
    if (v[0] == x && v[1] == y) {
      int e = v[2];
      int p = v[3];
      int d = v[4];

      auto a = solve(e, x, y);

      if (n <= e) {
        cout << a[n] << '\n';
      } else {
        int t = (n - (n-e)/p*p - p);
        int q = (n-t) / p;
        cout << a[t] + q*d << '\n';
      }
    }
  }
}