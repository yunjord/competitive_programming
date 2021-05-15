#ifdef LOCAL
#include <header.hpp>
#else
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#endif
#define lp(i, l, r) for (int i = int(l); i <= int(r); ++i)
#define rp(i, r, l) for (int i = int(r); i >= int(l); --i)
#define ls(i, s) for (int i = 0; s[i]; ++i)
#define rs(i, s) for (int i = strlen(s) - 1; i >= 0; --i)
#define lv(i, a) for (int i = 0; i < int(a.size()); ++i)
#define rv(i, a) for (int i = int(a.size()) - 1; i >= 0; --i)
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define prec(a) cout << setprecision(a) << fixed
#define freo freopen
#define many for (int C = 1, T = -1; T < 0 && cin >> T, C <= T; ++C)
#define goog "Case #" + to_string(C) + ":"
#define appl(x, f, a)                                                          \
    for (auto &x : a)                                                          \
    f
#define rang(a) begin(a), end(a)
#define gene template <class T>
#define elif else if
#define intm modular_arithmetic::integer
#define bcnt __builtin_popcount
#ifdef LOCAL
#define debu(...)                                                              \
    {                                                                          \
        vector<string> S(1);                                                   \
        int A = 0;                                                             \
        for (auto V : #__VA_ARGS__) {                                          \
            if (V == ',' && !A)                                                \
                S.push_back("");                                               \
            elif (S.back().size() || V != ' ') S.back().push_back(V),          \
                A += map<char, int>{{'(', 1}, {')', -1}}[V];                   \
        }                                                                      \
        cout << "\x1b[33mDebugging @ Line " << __LINE__ << ":\x1b[0m\n";       \
        debu_(S.begin(), __VA_ARGS__);                                         \
    }
#else
#define endl '\n'
#undef assert
#define assert
#define debu(...)
#endif
using namespace std;
using namespace __gnu_pbds;
template <class I, class T> void debu_(I i, const T &a) {
    cout << "\x1b[33m    " << *i << " = " << a << "\x1b[0m" << endl;
}
template <class I, class A, class... B>
void debu_(I i, const A &a, const B &... b) {
    cout << "\x1b[33m    " << *i << " = " << a << "\x1b[0m" << endl;
    debu_(++i, b...);
}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
gene T rint(T l, T r) { return uniform_int_distribution<T>(l, r)(rng); }
template <class A, class B> B conv(const A &a, B b = B()) {
    stringstream s;
    s << a, s >> b;
    return b;
}
vector<string> spli(const string &s) {
    vector<string> r;
    for (int i = 0, j; i < int(s.size()); ++i)
        if (s[i] != ' ') {
            r.push_back("");
            for (j = i; j < int(s.size()) && s[j] != ' '; ++j)
                r.back().push_back(s[j]);
            i = j - 1;
        }
    return r;
}
template <class T = int> T inf() { return numeric_limits<T>::max() / 2; }
gene T floor(const T &a, const T &b) {
    assert(b != 0);
    return (a > 0 && b > 0) || (a < 0 && b < 0)
               ? abs(a) / abs(b)
               : -(abs(a) + abs(b) - 1) / abs(b);
}
gene T ceil(const T &a, const T &b) {
    assert(b != 0);
    return (a > 0 && b > 0) || (a < 0 && b < 0) ? (abs(a) + abs(b) - 1) / abs(b)
                                                : -abs(a) / abs(b);
}
gene bool tmin(T &a, T b) { return b < a ? a = b, true : false; }
gene bool tmax(T &a, T b) { return b > a ? a = b, true : false; }
gene auto min(const T &a) { return *min_element(rang(a)); }
gene auto max(const T &a) { return *max_element(rang(a)); }
gene auto sum(const T &a) {
    return accumulate(rang(a), (typename T::value_type)0);
}
template <> auto sum(const vector<int> &a) { return accumulate(rang(a), 0ll); }
template <class T, int N, class I>
auto gath(const T (&a)[N], const vector<I> &b) {
    vector<T> r;
    for (auto i : b)
        r.push_back(a[i]);
    return r;
}
template <class T, class I> auto gath(const T &a, const vector<I> &b) {
    vector<typename T::value_type> r;
    for (auto i : b)
        r.push_back(a[i]);
    return r;
}
template <class T, class C = less<typename T::value_type>>
void sort(T &a, C c = C()) {
    sort(rang(a), c);
}
gene void reve(T &a) { reverse(rang(a)); }
gene void uniq(T &a) { sort(a), a.erase(unique(rang(a)), end(a)); }
gene void shuf(T &a) { shuffle(rang(a), rng); }
gene void merg(T l, T m, T r) { inplace_merge(l, m, r); }
gene auto vect(const vector<T> &v, int n) {
    assert(v.size() <= 1);
    return v.size() ? vector<T>(n, v[0]) : vector<T>(n);
}
template <class T, class... D> auto vect(const vector<T> &v, int n, D... m) {
    return vector<decltype(vect(v, m...))>(n, vect(v, m...));
}
gene void in(T &a) { cin >> a; }
template <class A, class... B> void in(A &a, B &... b) { cin >> a, in(b...); }
void ou() { cout << endl; }
gene void ou(const T &a) { cout << a << endl; }
template <class A, class... B> void ou(const A &a, const B &... b) {
    cout << a << ' ', ou(b...);
}
template <class F, class S> istream &operator>>(istream &s, pair<F, S> &a) {
    return s >> a.first >> a.second;
}
template <class F, class S>
ostream &operator<<(ostream &s, const pair<F, S> &a) {
    return s << '(' << a.first << ", " << a.second << ')';
}
gene istream &operator>>(istream &s, vector<T> &a) {
    for (int i = -1; i < 0 && (!a.size() && (cin >> i, a.resize(i), 0), i = 0),
             i < int(a.size());)
        s >> a[i++];
    return s;
}
gene ostream &operator<<(ostream &s, const vector<T> &a) {
    lv(i, a) cout << a[i] << (i + 1 == int(a.size()) ? "" : " ");
    return s;
}
gene using bbst =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
gene using heap = __gnu_pbds::priority_queue<T, greater<T>, pairing_heap_tag>;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef string str;
// The templates end here.
typedef struct t_incidence_cube {
    int s[51][51][51];
} IncidenceCube;
void InitIncidenceCube(IncidenceCube *c, int DIM) {
    int i, j, k;
    /* First, zero the cube */
    for (i = 0; i < DIM; i++)
        for (j = 0; j < DIM; j++)
            for (k = 0; k < DIM; k++)
                c->s[i][j][k] = 0;
    /* And then dump ones in the right place... */
    for (i = 0; i < DIM; i++)
        for (j = 0; j < DIM; j++)
            c->s[i][j][(i + j) % DIM] = 1;
}
auto PrintIncidenceCube(IncidenceCube *c, int DIM) {
    auto a = vect<int>({}, DIM, DIM);
    int i, j, k;
    int cur_i = 0, cur_j = 0;
    for (i = 0; i < DIM; i++) {
        for (j = 0; j < DIM; j++) {
            for (k = 0; k < DIM; k++) {
                if (c->s[i][j][k]) {
                    // printf("%2d ", k + 1);
                    a[cur_i][cur_j++] = k + 1;
                    break;
                }
            }
        }
        // printf("\n");
        ++cur_i, cur_j = 0;
    }
    // printf("\n");
    return a;
}
void ShuffleIncidenceCube(IncidenceCube *c, int DIM) {
    int i, j;

    for (i = 0; i < DIM * DIM * DIM; i++) {

        // Assume we have a "proper" matrix...

        // Pick a random zero from the incidence cube...
        int rx, ry, rz;
        do {
            rx = rint(0, DIM - 1);
            ry = rint(0, DIM - 1);
            rz = rint(0, DIM - 1);
        } while (c->s[rx][ry][rz]);

        int ox = -1, oy = -1, oz = -1;

        for (j = 0; j < DIM; j++) {
            if (c->s[j][ry][rz] == 1)
                ox = j;
            if (c->s[rx][j][rz] == 1)
                oy = j;
            if (c->s[rx][ry][j] == 1)
                oz = j;
        }

        // do the +/- 1 move...
        // These are all square with zeros in them...
        c->s[rx][ry][rz]++;
        c->s[rx][oy][oz]++;
        c->s[ox][ry][oz]++;
        c->s[ox][oy][rz]++;

        // These all have ones, except for maybe the last one...
        c->s[rx][ry][oz]--;
        c->s[rx][oy][rz]--;
        c->s[ox][ry][rz]--;
        c->s[ox][oy][oz]--;

        while (c->s[ox][oy][oz] < 0) {

            rx = ox;
            ry = oy;
            rz = oz;

            // Pick one of the two 1's that are in conflict
            if (drand48() < 0.5) {
                for (j = 0; j < DIM; j++) {
                    if (c->s[j][ry][rz] == 1) {
                        ox = j;
                    }
                }
            } else {
                for (j = DIM - 1; j >= 0; j--) {
                    if (c->s[j][ry][rz] == 1) {
                        ox = j;
                    }
                }
            }

            if (drand48() < 0.5) {
                for (j = 0; j < DIM; j++) {
                    if (c->s[rx][j][rz] == 1) {
                        oy = j;
                    }
                }
            } else {
                for (j = DIM - 1; j >= 0; j--) {
                    if (c->s[rx][j][rz] == 1) {
                        oy = j;
                    }
                }
            }

            if (drand48() < 0.5) {
                for (j = 0; j < DIM; j++) {
                    if (c->s[rx][ry][j] == 1) {
                        oz = j;
                    }
                }
            } else {
                for (j = DIM - 1; j >= 0; j--) {
                    if (c->s[rx][ry][j] == 1) {
                        oz = j;
                    }
                }
            }

            // do the +/- 1 move...
            // These are all square with zeros in them...
            c->s[rx][ry][rz]++;
            c->s[rx][oy][oz]++;
            c->s[ox][ry][oz]++;
            c->s[ox][oy][rz]++;

            // These all have ones, except for maybe the last one...
            c->s[rx][ry][oz]--;
            c->s[rx][oy][rz]--;
            c->s[ox][ry][rz]--;
            c->s[ox][oy][oz]--;
        }
    }
}
auto sample(int n) {
    IncidenceCube c;
    InitIncidenceCube(&c, n);
    ShuffleIncidenceCube(&c, n);
    return PrintIncidenceCube(&c, n);
}
void display(const vvi &a) { lv(i, a) ou(a[i]); }
int trace(const vvi &a) {
    int t = 0;
    lv(i, a) t += a[i][i];
    return t;
}
int main() {
    fast, prec(12);
    lp(n, 2, 10) {
        map<int, int> f;
        int m = 10000;
        lp(i, 1, m) {
            auto a = sample(n);
            ++f[trace(a)];
        }
        ou(n, f.size());
        for (auto t : f) {
            ou(t.first, 1. * t.second / m);
        }
        ou();
    }
    return 0;
}
