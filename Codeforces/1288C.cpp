#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define lp(i, l, r) for (int i = l; i <= r; ++i)
#define rp(i, r, l) for (int i = r; i >= l; --i)
#define ls(i, s) for (int i = 0; s[i]; ++i)
#define rs(i, s) for (int i = strlen(s) - 1; i >= 0; --i)
#define lv(i, a) for (int i = 0; i < a.size(); ++i)
#define rv(i, a) for (int i = (int)a.size() - 1; i >= 0; --i)
#define in(a) int a = (cin >> a, a)
#define ou(a) cout << a << endl
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define prec(a) cout << setprecision(a) << fixed
#define many for (int T = -1; T < 0 && cin >> T, T--;)
#define rang(a) begin(a), end(a)
#define gene template <class T>
#pragma GCC optimize("O3")
using namespace std;
using namespace __gnu_pbds;
gene void sort(vector<T> &a) { sort(rang(a)); }
gene void reve(vector<T> &a) { reverse(rang(a)); }
gene void uniq(vector<T> &a) { sort(a), a.erase(unique(rang(a)), end(a)); }
gene void merg(T l, T m, T r) { inplace_merge(l, m, r); }
gene T min(const vector<T> &a) { return *min_element(rang(a)); }
gene T max(const vector<T> &a) { return *max_element(rang(a)); }
gene T sum(const vector<T> &a) { return accumulate(rang(a), 0); }
gene T inf() { return numeric_limits<T>::max(); }
gene int updl(T &a, T b) { return b < a ? a = b, 1 : 0; }
gene int updg(T &a, T b) { return b > a ? a = b, 1 : 0; }
gene using bbst =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
gene auto &operator>>(istream &s, pair<T, T> &a) {
    return s >> a.first >> a.second;
}
gene auto &operator>>(istream &s, vector<T> &a) {
    for (int i = -1; i < 0 && (!a.size() && (cin >> i, a.resize(i), 0), i = 0),
             i < a.size();)
        s >> a[i++];
    return s;
}
gene auto &operator<<(ostream &s, const pair<T, T> &a) {
    return s << '(' << a.first << ", " << a.second << ')';
}
gene auto &operator<<(ostream &s, const vector<T> &a) {
    lv(i, a) cout << a[i] << (i + 1 == a.size() ? "" : " ");
    return s;
}
namespace modular_arithmetic {
template <class T = long long> struct integer {
    integer() : v(0) {}
    integer(T t) : v(t) { wrap_around(); }
    void wrap_around() {
        if (v < 0)
            v = (v % p + p) % p;
        else if (v >= p)
            v %= p;
    }
    auto &operator=(integer<T> a) {
        v = a.v;
        return *this;
    }
    auto operator-() {
        integer<T> a;
        a.v = (v ? p - v : 0);
        return a;
    }
    auto &operator+=(integer<T> a) { return *this = *this + a; }
    auto &operator-=(integer<T> a) { return *this = *this - a; }
    auto &operator*=(integer<T> a) { return *this = *this * a; }
    auto &operator/=(integer<T> a) { return *this = *this / a; }
    T v;
    static T p;
    static mt19937 g_32;
    static mt19937_64 g_64;
};
template <class T> T integer<T>::p = 1e9 + 7;
template <class T> mt19937 g_32(random_device{}());
template <class T> mt19937_64 g_64(random_device{}());
template <class T> auto operator+(integer<T> a, integer<T> b) {
    integer<T> c;
    c.v = a.v + b.v;
    if (c.v >= a.p)
        c.v -= a.p;
    return c;
}
template <class T> auto operator-(integer<T> a, integer<T> b) {
    integer<T> c;
    c.v = a.v - b.v;
    if (c.v < 0)
        c.v += a.p;
    return c;
}
template <class T> auto operator*(integer<T> a, integer<T> b) {
    integer<T> c;
    if (typeid(T) == typeid(long long))
        c.v = (a.v * b.v -
               (long long)(((long double)a.v * b.v + 0.5) / a.p) * a.p + a.p) %
              a.p;
    else if (typeid(T) == typeid(int))
        c.v = (long long)a.v * b.v % a.p;
    else
        c.v = a.v * b.v % a.p;
    return c;
}
template <class T> auto operator/(integer<T> a, integer<T> b) {
    return a * inverse(b);
}
template <class T> bool operator==(integer<T> a, integer<T> b) {
    return a.v == b.v;
}
template <class T> bool operator!=(integer<T> a, integer<T> b) {
    return a.v != b.v;
}
template <class T> auto &operator>>(istream &s, integer<T> &a) {
    s >> a.v;
    a.wrap_around();
    return s;
}
template <class T> auto &operator<<(ostream &s, integer<T> a) {
    return s << a.v;
}
template <class T> auto pow(integer<T> a, T b) {
    integer<T> r(1);
    for (; b; b >>= 1, a = a * a)
        if (b & 1)
            r = r * a;
    return r;
}
template <class T> auto inverse(integer<T> a) { return pow(a, a.p - 2); }
// Not tested.
template <class T> auto random() {
    if (typeid(T) == typeid(long long))
        return integer<T>::g_64();
    else if (typeid(T) == typeid(int))
        return integer<T>::g_32();
    else
        assert(0);
}
// Not tested.
template <class T> auto sqrt(integer<T> a) {
    vector<integer<T>> r;
    if (!a.v)
        r.push_back(decltype(r)(0));
    else if (pow(a, a.p - 1 >> 1).v == 1) {
        int s = a.p - 1, t = 0;
        integer<T> b = 1;
        for (; pow(b, a.p - 1 >> 1).v != a.p - 1; b = integer<T>::random())
            ;
        for (; s % 2 == 0; ++t, s /= 2)
            ;
        integer<T> x = pow(a, (s + 1) / 2), e = pow(a, s);
        for (int i = 1; i < t; ++i, e = x * x / a)
            if (pow(e, 1 << t - i - 1).v != 1)
                x = x * pow(b, (1 << i - 1) * s);
        r.push_back(x);
        r.push_back(-x);
    }
    return r;
}
template <class T> auto factorial(T a) {
    assert(a >= 0);
    integer<T> r(1);
    for (auto i = 1; i <= a; ++i)
        r *= i;
    return r;
}
template <class T> auto binary_coefficient(T n, T k) {
    assert(n >= 0 && k >= 0);
    if (n < k)
        return integer<T>();
    return factorial(n) / factorial(k) / factorial(n - k);
}
} // namespace modular_arithmetic
int main() {
    fast, prec(12);
    in(n);
    in(m);
    cout << modular_arithmetic::binary_coefficient(n + 2 * m - 1, n - 1)
         << endl;
    return 0;
}
