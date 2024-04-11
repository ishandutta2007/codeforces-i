/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author
 */

#include <iostream>
#include <fstream>

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <functional>
#include <sstream>
#include <cmath>

#include <cstring>
#include <cstdio>

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())

template<class T> T abs(T x) { return x >= 0 ? x : -x; }
template<class T> T sqr(T x) { return x * x; }

constexpr int mod = 998244353;

class TaskC {
public:
    vector<vi> g;
    vi col;
    vi vc1, vc2;

    void solve(std::istream& in, std::ostream& out) {
	    int n;
	    in >> n;
	    vector<vi> a(2 * n, vi(n, -1));
	    for (int i = 0; i < sz(a); ++i)
	        for (int j = 0; j < sz(a[i]); ++j) {
                in >> a[i][j];
                --a[i][j];
            }
        vector<vi> contr(sz(a));
        for (int i = 0; i < sz(a); ++i) {
            for (int j = 0; j < sz(a); ++j)
                if (i != j) {
                    bool ok = true;
                    for (int t = 0; t < sz(a[i]); ++t)
                        if (a[i][t] == a[j][t]) {
                            ok = false;
                            break;
                        }
                    if (!ok) contr[i].pb(j);
                }
        }
        vi state(sz(a), 0);
        int taken = 0;
        for (int i = 0; i < n; ++i) {
            while (true) {
                bool done = true;
                vector<vi> guys(n);
                for (int j = 0; j < sz(a); ++j)
                    if (state[j] != -1) guys[a[j][i]].pb(j);
                for (int j = 0; j < n; ++j) {
                    assert(sz(guys[j]));
                    if (sz(guys[j]) == 1 && state[guys[j][0]] == 0) {
                        int v = guys[j][0];
                        done = false;
                        state[v] = 1;
                        ++taken;
                        for (int x : contr[v]) {
                            state[x] = -1;
                        }
                    }
                }
                if (done) break;
            }
        }
        assert(taken <= n);
        int need = n - taken;
        vi pos(sz(a), -1);
        vi ind;
        for (int i = 0; i < sz(a); ++i) if (state[i] == 0) {
            pos[i] = sz(ind);
            ind.pb(i);
        }
        assert(sz(ind) <= 2 * need);
        g = vector<vi>(sz(ind));
        for (int x : ind) {
            for (int y : contr[x]) if (pos[y] != -1) {
                g[pos[x]].pb(pos[y]);
            }
        }
        col = vi(sz(ind), 0);
        vector<pair<vi, vi>> comps;
        for (int i = 0; i < sz(ind); ++i) if (col[i] == 0) {
                vc1.clear();
                vc2.clear();
                dfs(i, 1);
                comps.emplace_back(vc1, vc2);
            }
        vi d(need + 1, 0);
        vector<vi*> from(need + 1, nullptr);
        d[0] = 1;
        for (auto& e : comps) {
            int c1 = sz(e.first), c2 = sz(e.second);
            for (int i = sz(d) - 1; i >= 0; --i) {
                if (i - c1 >= 0 && d[i - c1] > 0) {
                    d[i] += d[i - c1];
                    d[i] %= mod;
                    if (from[i] == nullptr) from[i] = &e.first;
                }
                if (i - c2 >= 0 && d[i - c2] > 0) {
                    d[i] += d[i - c2];
                    d[i] %= mod;
                    if (from[i] == nullptr) from[i] = &e.second;
                }
            }
        }
        out << d[need] << "\n";
        vi vr;
        for (int i =0  ;i < sz(a); ++i)
            if (state[i] == 1)
                vr.pb(i);
        int cur = need;
        while (cur > 0) {
            auto* f = from[cur];
            for (int x : *f)
                vr.pb(ind[x]);
            cur -= sz(*f);
        }
        sort(all(vr));
        assert(sz(vr) == n);
        vi u(2 * n, 0);
        for (int x : vr) {
            assert(u[x] == 0);
            u[x] = 1;
        }
        for (int x : vr)
            for (int y : contr[x])
                assert(!u[y]);
        bool first = true;
        for (int x : vr) {
            if (!first) out << " ";
            first = false;
            out << (x + 1);
        }
        out << "\n";
	}

    void dfs(int x, int c) {
        col[x] = c;
        if (c == 1) vc1.pb(x);
        else vc2.pb(x);
        for (int y : g[x]) {
            if (col[y] == 0) dfs(y, -c);
            else {
                assert(col[y] == -c);
            }
        }
    }
};


int main() {
	TaskC solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	int n;
in >> n;
for(int i = 0; i < n; ++i) {
	solver.solve(in, out);
}

	return 0;
}