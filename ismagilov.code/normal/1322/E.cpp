/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author Azat Ismagilov
 */

                                         /*..         ....
                                    ..',,'..............''...'''.','..
                                  .';'..                          ..',,'.
                                 .'..                                 .';,.
                                .'.              .:ol;.                 .';.
                                ..              .cO00k:.                  .,.
                               ..          .'...;k00Od'                   .'.
                              ...        .;xOkxdk00Od,                    ...
                             ...        .,x0000000Od;.                     ..
                             .'         .cO00OOOOOOd;'...                 ...
                            .'.          .;lxkOOOO00Okkxo:.               .'.
                           .'.             .cxOOOOO000000Ol.              .'.
                          .'.             .ck00OOd::oxOOOOl.              .,.
                          ''...,;''''''''':kKK0Od,. ..:xOo'               .,.
                         ';,;;;:,..........;lxOx:.    .';'               .''
                        'cc;..               .,;:,..                     ...
                       ,oc.       ..........    .',:;,..                 ...
                      'o:.     .,;;;,,,,;;;;;'.    ..,;;,..              ...
                      ';.      ...         .,::.       .,::'.            .'.
                      ..                     .',.        ..;;'.         ...
                     ..          .',,;;,'.                  ':;'.       .,.
                    .,::;,.        .......                   .';:'.    .,,.
                    .;dOK0x;.                         .        .':;.   .,.
                    ...,cdxdl;.              ..,;;;cloddoc;.     .,:,. .,.
                   .     ...;cl:.          ':ldxxdocccclol;.      ..:;.',.
                   .   .;llc;',c;.       .,:,''';::;'.  ..          .;:;'
                      .:xdoxko,',.      .,:. .;llc:ldl.              .;c.
                      .lxdoxkd:''.     .;:.  .cxl'';od;.          .. .,,
                      .:clool;.',.     .:'   .:dxolccl;.         .::;,:'
                       .;::,.. .,.     .;.   .,:;:;,,;'         .,;,:ol.
                         ..    ',.     .;.    .',,,,,.          .,:llc;.
                              .,'      .,.                      .;lxxc'
                             .,;.      .;.                      .;lxxc.
            ..              .;;.       .:'                      .;cc,.
           ...';'          .;;.        .;:.                      ,:'
          .;c:;.       .. .,;.       ....,;.                     .'.
         .,lc,.      .':,..,:,''....;c:;'':'..              ..   .'.
         .;:;.      .,:'   .::,,;;;;;..',;,..,,.            .,.  .'.
        .'',,.     .,;.                      .;,            .'.  ...
        .'',,.    .,;.                        ';.           .,.  .'.
        .'...     .;.                         .,,.          .,'   ..
        .'.      .;,.                          .::.         .,'   .
        .'.     .,;.                            ,c'         .,'  .'.
        .'.     .:'                             .,'          .. .,'
         ''.    ,;.    .....................    .;'            .:,
         .,.   .,;.   ..'''''''''''''''''','.  .,;.           .::.
          .,.   ,;.                           .,;.           .;,.
          .,,.  .:,.                         .;;.          .''.
           .,'   .'.                         ...          .,.
            .''                                          .,.
             .,'.                                       .'.
              .'.                                      .*/

#include <fstream>

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <numeric>
#include <set>
#include <map>

#define ld long double
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define eb emplace_back
#define mp make_pair
#define len(v) ((int)v.size())
#define vc vector
#define pr pair
#define all(v) v.begin(), v.end()
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops,inline")

using namespace std;

template<typename T, typename U>
inline ostream &operator<<(ostream &_out, const pair<T, U> &_p) {
    _out << _p.first << ' ' << _p.second;
    return _out;
}

template<typename T, typename U>
inline istream &operator>>(istream &_in, pair<T, U> &_p) {
    _in >> _p.first >> _p.second;
    return _in;
}

template<typename T>
inline ostream &operator<<(ostream &_out, const vector<T> &_v) {
    if (_v.empty()) { return _out; }
    _out << _v.front();
    for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) { _out << ' ' << *_it; }
    return _out;
}

template<typename T>
inline istream &operator>>(istream &_in, vector<T> &_v) {
    for (auto &_i : _v) { _in >> _i; }
    return _in;
}

const int MAXN = 1e6;
const int INF = 1e9;
const int MOD = 1e9 + 7;

int t[4 * MAXN];
int ans[MAXN];


void push(int v, int l, int r) {
    if (l != r && t[v] != 0) {
        if (t[2 * v] == 0) {
            t[2 * v] = t[v];
        }
        if (t[2 * v + 1] == 0) {
            t[2 * v + 1] = t[v];
        }
        t[v] = 0;
    }
}

void upd(int v, int l, int r, int tl, int tr, int ud) {
    if (t[v] != 0) {
        return;
    }
    push(v, l, r);
    if (tl <= l && r <= tr) {
        if (t[v] == 0) {
            t[v] = ud;
        }
        return;
    }
    if (r < tl || tr < l) {
        return;
    }
    int mid = (l + r) / 2;
    upd(2 * v, l, mid, tl, tr, ud);
    upd(2 * v + 1, mid + 1, r, tl, tr, ud);
}

void get_ans(int v, int l, int r) {
    push(v, l, r);
    if (l == r) {
        ans[l] = t[v];
        return;
    }
    int mid = (l + r) / 2;
    get_ans(2 * v, l, mid);
    get_ans(2 * v + 1, mid + 1, r);
}

int tp[MAXN];

set<pr<int, int>> segments;
vc<pr<int, int>> c_segments;
int n;
int color;
int dist = 0;

void add_segment(int l, int r, bool adds = 0) {
    if (l > r) {
        return;
    }
    if (adds) {
        c_segments.pb({l, r});
    }
    segments.insert({l, r});
}

void process_segment(int l, int r) {
    if (segments.find({l, r}) == segments.end()) {
        return;
    }
    dist = max(dist, (r - l) / 2);
    int mid = (l + r) / 2;
    if ((r - l) % 2 == 0) {
        if (tp[l] == 0) {
            upd(1, 0, n - 1, l, r, color);
        }
    } else {
        if (tp[l] == 0) {
            upd(1, 0, n - 1, l, mid, color);
        }
        if (tp[r] == 0) {
            upd(1, 0, n - 1, mid + 1, r, color);
        }
    }
}

void del_segment(int l, int r) {
    segments.erase({l, r});
}

void separate(int pos) {
    auto it = *prev(segments.lower_bound({pos + 1, 0}));
    //process_segment(it.fs, it.sc, 0);
    if (it.fs != it.sc) {
        segments.erase(it);
        add_segment(it.fs, pos - 1, 1);
        add_segment(pos, pos);
        add_segment(pos + 1, it.sc, 1);
    }
}

void change(int pos) {
    separate(pos);
    tp[pos] = 0;
    int l = pos;
    int r = pos;
    auto it = segments.find({pos, pos});
    if (it != segments.begin() && tp[pos - 1] != tp[pos]) {
        l = (*prev(it)).fs;
        segments.erase(prev(it));
    }
    if (next(it) != segments.end() && tp[pos + 1] != tp[pos]) {
        r = (*next(it)).sc;
        segments.erase(next(it));
    }
    segments.erase(it);
    add_segment(l, r, 1);
}

class medianrockthing {
public:
    void solve(std::istream &in, std::ostream &out) {
        in >> n;
        dist = 0;
        vc<int> a(n);
        in >> a;
        map<int, vc<int>> kek;
        for (int i = 0; i < n; i++) {
            kek[a[i]].pb(i);
            segments.insert({i, i});
            tp[i] = 1;
        }
        for (auto &vv : kek) {
            color = vv.fs;
            for (auto &v : vv.sc) {
                change(v);
            }
            for (auto v : c_segments) {
                process_segment(v.fs, v.sc);
            }
            c_segments.clear();
        }
        upd(1, 0, n - 1, 0, n - 1, (*kek.rbegin()).fs);
        get_ans(1, 0, n - 1);
        out << dist << '\n';
        for (int i = 0; i < n; i++) {
            out << ans[i] << ' ';
        }
    }
};


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	medianrockthing solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}