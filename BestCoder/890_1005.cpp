#ifdef LOCAL
#include <header.hpp>
#else
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#endif
#define lp(i, l, r) for (auto i = regu(l); i <= decltype(i)(r); ++i)
#define rp(i, r, l) for (auto i = regu(r); i >= decltype(i)(l); --i)
#define lv(i, a) for (int i = 0; i < int(a.size()); ++i)
#define rv(i, a) for (int i = int(a.size()) - 1; i >= 0; --i)
#define lm(i, m) for (auto i = m; i; i = (m) & (i - 1))
#define many for (int C = 1, T = -1; T < 0 && cin >> T, C <= T; ++C)
#define goog "Case #" + to_string(C) + ":"
#define rang(a) begin(a), end(a)
#define elif else if
#ifndef LOCAL
#define endl '\n'
#undef assert
#define assert
#endif
using namespace std;
using namespace __gnu_pbds;
const auto eps = 1e-8, pi = acos(-1);
template <class T> int comp(const T &a, const T &b) {
    return a < b - eps ? -1 : (a > b + eps);
}
#if __cplusplus > 201103L
template <class T> auto regu(const T &a) { return int(a); }
template <> auto regu(const int64_t &a) { return a; }
template <> auto regu(const uint64_t &a) { return int64_t(a); }
#else
template <class T> int64_t regu(const T &a) { return int(a); }
template <> int64_t regu(const int64_t &a) { return a; }
template <> int64_t regu(const uint64_t &a) { return a; }
#endif
template <class T> int barr(const T &a, const int &i) {
    return int(a >> i & 1);
}
template <class T> int bcnt(const T &a) { return __builtin_popcount(a); }
template <> int bcnt(const int64_t &a) { return __builtin_popcountll(a); }
template <class T> int blen(const T &a) { return a ? 1 + blen(a / 2) : 0; }
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template <class T> T rint(T l, T r) {
    return uniform_int_distribution<T>(l, r)(rng);
}
template <class A, class B> B conv(const A &a, B b = B()) {
    stringstream s;
    s << a, s >> b;
    return b;
}
template <class T = int> T inf() { return numeric_limits<T>::max() / 2; }
template <class T> T sign(const T &a) { return a == 0 ? 0 : (a < 0 ? -1 : 1); }
template <class T> T floor(const T &a, const T &b) {
    assert(b != 0);
    return sign(a) * sign(b) > 0 ? abs(a) / abs(b)
                                 : -(abs(a) + abs(b) - 1) / abs(b);
}
template <class T> T ceil(const T &a, const T &b) {
    assert(b != 0);
    return sign(a) * sign(b) > 0 ? (abs(a) + abs(b) - 1) / abs(b)
                                 : -abs(a) / abs(b);
}
template <class T> bool tmin(T &a, T b) { return b < a ? a = b, true : false; }
template <class T> bool tmax(T &a, T b) { return b > a ? a = b, true : false; }
#if __cplusplus > 201103L
template <class T> auto min(const T &a) { return *min_element(rang(a)); }
template <class T> auto max(const T &a) { return *max_element(rang(a)); }
template <class T> auto sum(const T &a) {
    return accumulate(rang(a), (typename T::value_type)0);
}
template <> auto sum(const vector<int> &a) { return accumulate(rang(a), 0ll); }
template <> auto sum(const vector<string> &a) {
    return accumulate(rang(a), string());
}
template <class C, class V> auto find(C &c, const V &v) {
    return find(rang(c), v);
}
template <class C, class V> auto find(const C &c, const V &v) {
    return find(rang(c), v);
}
#endif
template <class T, class C = less<typename T::value_type>>
void sort(T &a, C c = C()) {
    sort(rang(a), c);
}
template <class T> void reve(T &a) { reverse(rang(a)); }
template <class T> void uniq(T &a) {
    sort(a), a.erase(unique(rang(a)), end(a));
}
template <class T> void shuf(T &a) { shuffle(rang(a), rng); }
template <class T> void merg(T l, T m, T r) { inplace_merge(l, m, r); }
#if __cplusplus > 201103L
template <class T> auto vect(const T &v, int n) { return vector<T>(n, v); }
template <class T, class... D> auto vect(const T &v, int n, D... m) {
    return vector<decltype(vect(v, m...))>(n, vect(v, m...));
}
#endif
template <class F, class S> istream &operator>>(istream &s, pair<F, S> &a) {
    return s >> a.first >> a.second;
}
template <class F, class S>
ostream &operator<<(ostream &s, const pair<F, S> &a) {
    return s << a.first << " " << a.second;
}
template <class T> istream &operator>>(istream &s, vector<T> &a) {
    for (int i = -1; i < 0 && (!a.size() && (cin >> i, a.resize(i), 0), i = 0),
             i < int(a.size());)
        s >> a[i++];
    return s;
}
template <class T> ostream &operator<<(ostream &s, const vector<T> &a) {
    lv(i, a) cout << a[i] << (i + 1 == int(a.size()) ? "" : " ");
    return s;
}
template <class T> T in() {
    T a;
    cin >> a;
    return a;
}
template <class T> istream &in(T &a) { return cin >> a; }
template <class A, class... B> istream &in(A &a, B &... b) {
    return cin >> a, in(b...);
}
void ou() { cout << endl; }
template <class T> void ou(const T &a) { cout << a << endl; }
template <class A, class... B> void ou(const A &a, const B &... b) {
    cout << a << ' ', ou(b...);
}
bool yep(const bool &a) { return ou(a ? "yes" : "no"), a; }
bool Yep(const bool &a) { return ou(a ? "Yes" : "No"), a; }
bool YEP(const bool &a) { return ou(a ? "YES" : "NO"), a; }
#if __cplusplus > 201103L
template <class T> struct func {
    func(T &&t_) : t(forward<T>(t_)) {}
    template <class... A> auto operator()(A &&... a) const {
        return t(*this, forward<A>(a)...);
    }
    T t;
};
#endif
template <class T> struct hash_safe {};
template <> struct hash_safe<int> {
    size_t operator()(unsigned long long a) const {
        static unsigned long long d =
            chrono::steady_clock::now().time_since_epoch().count();
        a += d + 0x9e3779b97f4a7c15, a = (a ^ (a >> 30)) * 0xbf58476d1ce4e5b9;
        a = (a ^ (a >> 27)) * 0x94d049bb133111eb;
        return a ^ (a >> 31);
    }
};
template <> struct hash_safe<long long> {
    size_t operator()(unsigned long long a) const {
        return hash_safe<int>()(a);
    }
};
template <class A, class B> struct hash_safe<pair<A, B>> {
    size_t operator()(pair<A, B> a) const {
        auto h = hash_safe<A>()(a.first), g = hash_safe<B>()(a.second);
        return (h >> 16 << 16) + (g >> 16);
    }
};
template <class T> using unordered_set_safe = unordered_set<T, hash_safe<T>>;
template <class T>
using unordered_multiset_safe = unordered_multiset<T, hash_safe<T>>;
template <class K, class V>
using unordered_map_safe = unordered_map<K, V, hash_safe<K>>;
template <class K, class V>
using unordered_multimap_safe = unordered_multimap<K, V, hash_safe<K>>;
#define unordered_set unordered_set_safe
#define unordered_multiset unordered_multiset_safe
#define unordered_map unordered_map_safe
#define unordered_multimap unordered_multimap_safe
template <class T, class C = less<T>>
using bbst =
    tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;
template <class T, class C = greater<T>>
using heap = __gnu_pbds::priority_queue<T, C, pairing_heap_tag>;
using ll = long long;
using ld = long double;
using str = string;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vvi = vector<vi>;
namespace minimum_cost_maximum_flow {
template <class F = int, class C = int> struct minimum_cost_maximum_flow {
    struct edge {
        edge(int _v, F _c, C _w) : v(_v), c(_c), w(_w) {}
        int v;
        F c;
        C w;
    };
    minimum_cost_maximum_flow(int _n, int _src, int _snk,
                              F _all = numeric_limits<F>::max())
        : n(_n), src(_src), snk(_snk), bg(_n), vis(n), dis(n), all(_all),
          flow(0), cost(0) {}
    void add(int u, int v, F c, C w) {
        bg[u].push_back(int(eg.size()));
        eg.push_back(edge(v, c, w));
        bg[v].push_back(int(eg.size()));
        eg.push_back(edge(u, 0, -w));
    }
    int spfa() {
        vector<int> in(n, 0);
        queue<int> qu;
        fill(vis.begin(), vis.end(), 0);
        dis[src] = 0;
        vis[src] = in[src] = 1;
        qu.push(src);
        while (!qu.empty()) {
            int u = qu.front();
            qu.pop();
            in[u] = 0;
            for (int i = 0; i < int(bg[u].size()); ++i) {
                edge &e = eg[bg[u][i]];
                if (e.c != 0 && (!vis[e.v] || dis[u] + e.w < dis[e.v])) {
                    dis[e.v] = dis[u] + e.w;
                    vis[e.v] = 1;
                    if (!in[e.v]) {
                        in[e.v] = 1;
                        qu.push(e.v);
                    }
                }
            }
        }
        return vis[snk];
    }
    F dfs(int u, F f) {
        if (u == snk)
            return f;
        F g = f;
        vis[u] = 1;
        for (int i = 0; i < int(bg[u].size()); ++i) {
            edge &e = eg[bg[u][i]], &ev = eg[bg[u][i] ^ 1];
            if (e.c != 0 && dis[e.v] == dis[u] + e.w && !vis[e.v]) {
                F t = dfs(e.v, min(g, e.c));
                g -= t;
                e.c -= t;
                ev.c += t;
                cost += t * e.w;
                if (g == 0)
                    return f;
            }
        }
        return f - g;
    }
    pair<F, C> run() {
        while (all != 0 && spfa()) {
            F t;
            do {
                fill(vis.begin(), vis.end(), 0);
                flow += (t = dfs(src, all));
                all -= t;
            } while (t != 0);
        }
        return make_pair(flow, cost);
    }
    int n, src, snk;
    vector<vector<int>> bg;
    vector<edge> eg;
    vector<int> vis;
    vector<C> dis;
    F all, flow;
    C cost;
};
} // namespace minimum_cost_maximum_flow
// The templates end here.
int main() {
    ios::sync_with_stdio(0);
    cout << setprecision(16) << fixed;
    cin.tie(0);
    many {
        int n, a, b, c;
        in(n, a, b, c);
        minimum_cost_maximum_flow::minimum_cost_maximum_flow<int> f(11, 9, 10);
        f.add(9, 0, a, 0);
        f.add(9, 1, b, 0);
        f.add(9, 2, c, 0);
        vector<str> t{"012", "021", "102", "120", "201", "210"};
        vi cnt(6);
        lp(i, 1, n) {
            str tmp;
            in(tmp);
            ++cnt[find(rang(t), tmp) - t.begin()];
        }
        lv(i, cnt) f.add(i + 3, 10, cnt[i], 0);
        lp(u, 0, 2) lp(v, 0, 5) {
            int cost = 3 - (find(rang(t[v]), '0' + u) - t[v].begin());
            f.add(u, v + 3, inf(), -cost);
        }
        ou(-f.run().second);
    }
    return 0;
}
