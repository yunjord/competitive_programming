#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#define lp(i, l, r) for (int i = l; i <= r; ++i)
#define rp(i, r, l) for (int i = r; i >= l; --i)
#define ls(i, s) for (int i = 0; s[i]; ++i)
#define rs(i, s) for (int i = strlen(s) - 1; i >= 0; --i)
#define lv(i, a) for (int i = 0; i < int(a.size()); ++i)
#define rv(i, a) for (int i = int(a.size()) - 1; i >= 0; --i)
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define prec(a) cout << setprecision(a) << fixed
#define many for (int T = -1; T < 0 && cin >> T, T--;)
#define appl(f, a) for (auto i = begin(a); i != end(a); f, ++i)
#define rang(a) begin(a), end(a)
#define tstr(a) to_string(a)
#define gene template <class T>
#ifndef LOCAL
#define endl '\n'
#define assert
#endif
using namespace std;
using namespace __gnu_pbds;
gene T inf() { return numeric_limits<T>::max(); }
gene int tmin(T &a, T b) { return b < a ? a = b, 1 : 0; }
gene int tmax(T &a, T b) { return b > a ? a = b, 1 : 0; }
#if __cplusplus >= 201402L
gene auto min(const T &a) { return *min_element(rang(a)); }
gene auto max(const T &a) { return *max_element(rang(a)); }
gene auto sum(const T &a) { return accumulate(rang(a), 0); }
gene auto gath(const T &a, const vector<int> &b) {
    vector<typename T::value_type> r;
    for (auto i : b)
        r.push_back(a[i]);
    return r;
}
#endif
gene void sort(T &a) { sort(rang(a)); }
gene void reve(T &a) { reverse(rang(a)); }
gene void uniq(T &a) { sort(a), a.erase(unique(rang(a)), end(a)); }
gene void shuf(T &a) { random_shuffle(rang(a)); }
gene void merg(T l, T m, T r) { inplace_merge(l, m, r); }
#if __cplusplus >= 201703L
template <typename... T> void in(T &... a) { ((cin >> a), ...); }
template <typename... T> void ou(T... a) { ((cout << a << ' '), ...); }
#endif
#if __cplusplus >= 201402L
template <class F, class S> auto &operator>>(istream &s, pair<F, S> &a) {
    return s >> a.first >> a.second;
}
template <class F, class S> auto &operator<<(ostream &s, const pair<F, S> &a) {
    return s << '(' << a.first << ", " << a.second << ')';
}
gene auto &operator>>(istream &s, vector<T> &a) {
    for (int i = -1; i < 0 && (!a.size() && (cin >> i, a.resize(i), 0), i = 0),
             i < int(a.size());)
        s >> a[i++];
    return s;
}
gene auto &operator<<(ostream &s, const vector<T> &a) {
    lv(i, a) cout << a[i] << (i + 1 == int(a.size()) ? "" : " ");
    return s;
}
#endif
gene using bbst =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
gene using heap = __gnu_pbds::priority_queue<T, greater<T>, pairing_heap_tag>;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
template <class T> struct dijkstras_algorithm {
    int n, m;
    vector<vector<int>> to;
    vector<vector<T>> cost;
    T inf;
    vector<pair<T, int>> tree;
    vector<T> distance;
    dijkstras_algorithm(int _n)
        : n(_n), m(1 << (int)ceil(log2(n) + 1e-8)), to(n), cost(n),
          inf(numeric_limits<T>::max()), tree(2 * m, make_pair(inf, 0)),
          distance(n, inf) {}
    void add_edge(int u, int v, T w) {
        assert(v >= 0 && v < n);
        to.at(u).push_back(v);
        cost.at(u).push_back(w);
    }
    int update(T &a, T b, T c) {
        if (b != inf && c != inf && b + c < a) {
            a = b + c;
            return 1;
        }
        return 0;
    }
    void modify(int u, T d) {
        for (tree[u + m] = make_pair(d, u), u = (u + m) >> 1; u; u >>= 1)
            tree[u] = min(tree[u << 1], tree[u << 1 ^ 1]);
    }
    void run() {
        for (int i = 0; i < n; ++i)
            tree[i + m] = make_pair(distance[i], i);
        for (int i = m - 1; i >= 1; --i)
            tree[i] = min(tree[i << 1], tree[i << 1 ^ 1]);
        for (int u = tree[1].second;
             tree[1].first != inf ? (modify(u, inf), 1) : 0; u = tree[1].second)
            for (int i = 0; i < int(to[u].size()); ++i) {
                int v = to[u][i];
                T c = cost[u][i];
                if (update(distance[v], distance[u], c))
                    modify(v, distance[v]);
            }
    }
};
namespace static_tree {
template <class T> struct static_tree {
    int n, root, num_leaves, block_size, num_blocks;
    vector<vector<pair<int, T>>> to;
    vector<T> depth;
    vector<int> father, level, tour_index, closest_size, block_type;
    vector<pair<int, int>> tour;
    vector<vector<pair<int, int>>> st;
    vector<vector<int>> block_min;
    static_tree(int _n, int _root = 0)
        : n(_n), root(_root), num_leaves(0), to(n), depth(n), father(n),
          level(n), tour_index(n) {}
    void add_edge(int u, int v, T w = 1) {
        to[u].emplace_back(v, w), to[v].emplace_back(u, w);
    }
    void build_depth(int u, int p, vector<bool> &visited) {
        bool no_child = true;
        vector<pair<int, T>> new_to;
        father[u] = p, visited[u] = true, new_to.reserve(to[u].size());
        for (auto e : to[u]) {
            int v = e.first;
            T w = e.second;
            if (v != p) {
                assert(!visited[v]);
                depth[v] = depth[u] + w, level[v] = level[u] + 1;
                no_child = false, build_depth(v, u, visited),
                new_to.push_back(e);
            }
        }
        to[u] = new_to, num_leaves += no_child;
    }
    void build_tour(int u) {
        tour_index[u] = int(tour.size()), tour.emplace_back(u, -1);
        for (int i = 0; i < int(to[u].size()); ++i) {
            int v = to[u][i].first;
            build_tour(v), tour_index[u] = int(tour.size());
            tour.emplace_back(u, i);
        }
    }
    pair<int, int> get_min(const pair<int, int> &a, const pair<int, int> &b) {
        int l_a = level[a.first], l_b = level[b.first];
        if (l_a != l_b)
            return l_a < l_b ? a : b;
        if (a.second < b.second)
            return a;
        return b;
    }
    void build_st() {
        block_size = max(1, int(log2(tour.size()) / 2));
        num_blocks =
            int(tour.size()) / block_size + bool(tour.size() % block_size);
        closest_size.resize(num_blocks + 1, 0);
        for (int i = 2; i <= num_blocks; ++i) {
            closest_size[i] = closest_size[i - 1];
            if ((1 << (closest_size[i] + 1)) <= i)
                ++closest_size[i];
        }
        st = vector<vector<pair<int, int>>>(
            num_blocks, vector<pair<int, int>>(closest_size[num_blocks] + 1));
        for (int h = 0; h <= closest_size[num_blocks]; ++h)
            for (int i = 0; i < num_blocks; ++i) {
                pair<int, int> &t = st[i][h];
                if (!h) {
                    t = tour[i * block_size];
                    for (int j = i * block_size;
                         j < (i + 1) * block_size && j < int(tour.size()); ++j)
                        t = get_min(t, tour[j]);
                } else if (i + (1 << (h - 1)) >= num_blocks)
                    t = st[i][h - 1];
                else
                    t = get_min(st[i][h - 1], st[i + (1 << (h - 1))][h - 1]);
            }
    }
    void build_block() {
        block_type.resize(num_blocks);
        for (int i = 0; i < num_blocks; ++i) {
            int m = 0;
            for (int j = i * block_size + 1; j < (i + 1) * block_size; ++j) {
                m <<= 1;
                if (j < int(tour.size()) && tour[j].first > tour[j - 1].first)
                    ++m;
            }
            block_type[i] = m;
        }
        block_min = vector<vector<int>>(1 << (block_size - 1),
                                        vector<int>(block_size * block_size));
        for (int m = 0; m < (1 << (block_size - 1)); ++m) {
            for (int i = 0; i < block_size; ++i) {
                pair<int, int> t(0, i);
                int v = 0, k = i * block_size;
                block_min[m][k + i] = i;
                for (int j = i + 1; j < block_size; ++j) {
                    if ((m >> (block_size - 1 - j)) & 1)
                        ++v;
                    else
                        --v;
                    if (v < t.first)
                        t = make_pair(v, j);
                    block_min[m][k + j] = t.second;
                }
            }
        }
    }
    void build() {
        vector<bool> visited(n);
        build_depth(root, -1, visited);
        assert(*min_element(begin(visited), end(visited)) == 1);
        tour.reserve(n - 1 + num_leaves), build_tour(root);
        build_st(), build_block();
    }
    pair<int, int> query_st(int l, int r) {
        int s = closest_size[r - l + 1];
        return get_min(st[l][s], st[r - (1 << s) + 1][s]);
    }
    pair<int, int> query_block(int l, int r) {
        int i = l / block_size, n_l = l % block_size, n_r = r % block_size;
        return tour[i * block_size +
                    block_min[block_type[i]][n_l * block_size + n_r]];
    }
    pair<int, int> rmq(int l, int r) {
        int block_l = l / block_size, block_r = r / block_size;
        pair<int, int> t = tour[l];
        if (block_l == block_r)
            return query_block(l, r);
        t = get_min(t, query_block(l, (block_l + 1) * block_size - 1));
        t = get_min(t, query_block(block_r * block_size, r));
        if (++block_l <= --block_r)
            t = get_min(t, query_st(block_l, block_r));
        return t;
    }
    pair<int, int> _lca(int u, int v) {
        int l = tour_index[u], r = tour_index[v];
        if (l > r)
            swap(l, r);
        return rmq(l, r);
    }
    int lca(int u, int v) { return _lca(u, v).first; }
    T distance(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }
    pair<int, T> move_to(int u, int v) {
        assert(u != v);
        pair<int, int> l = _lca(u, v);
        if (u != l.first)
            return make_pair(father[u], depth[u] - depth[father[u]]);
        return to[u][l.second];
    }
};
} // namespace static_tree
int main() {
    fast, prec(12);
    many {
        int n, q;
        cin >> n >> q;
        static_tree::static_tree<ll> st(n);
        lp(i, 1, n - 1) {
            int u, v, w;
            cin >> u >> v >> w;
            --u, --v;
            st.add_edge(u, v, w);
        }
        st.build();
        lp(i, 1, q) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            cout << st.distance(u, v) << endl;
        }
    }
    return 0;
}
int test() {
    fast, prec(12);
    int m = 1000000;
    for (int T = 1;; ++T) {
        cout << "Testing data " << T << endl;
        int n = rand() % m + 1;
        static_tree::static_tree<ll> st(n);
        dijkstras_algorithm<ll> sp(n);
        srand(T);
        lp(i, 2, n) {
            int u = i, v = rand() % (i - 1) + 1;
            --u, --v;
            int w = rand() % 2 + 1;
            st.add_edge(u, v, w);
            sp.add_edge(u, v, w);
            sp.add_edge(v, u, w);
        }
        cout << "Query:" << endl;
        int u = rand() % n;
        int v = rand() % n;
        cout << u << " " << v << endl;
        cout << "Debugging:" << endl;
        sp.distance[u] = 0;
        sp.run();
        st.build();
        auto d1 = sp.distance[v];
        auto d2 = st.distance(u, v);
        ll d3 = 0;
        while (u != v) {
            auto t = st.move_to(u, v);
            d3 += t.second;
            u = t.first;
        }
        cout << "Distances:" << endl;
        cout << d1 << endl << d2 << endl;
        cout << d3 << endl;
        assert(d1 == d2);
        assert(d1 == d3);
        cout << "Tested data " << T << endl << endl;
    }
    return 0;
}