#include <bits/stdc++.h>
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
#define rang(a) a.begin(), a.end()
#define gene template <class T>
#pragma GCC optimize("O3")
using namespace std;
gene void sort(vector<T> &a) { sort(rang(a)); }
gene void reve(vector<T> &a) { reverse(rang(a)); }
gene T min(const vector<T> &a) { return *min_element(rang(a)); }
gene T max(const vector<T> &a) { return *max_element(rang(a)); }
gene T sum(const vector<T> &a) { return accumulate(rang(a), 0); }
gene T inf() { return numeric_limits<T>::max(); }
gene int updl(T &a, T b) { return b < a ? a = b, 1 : 0; }
gene int updg(T &a, T b) { return b > a ? a = b, 1 : 0; }
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
             i<a.size(); s>> a[i++])
        ;
    return s;
}
gene auto &operator<<(ostream &s, const pair<T, T> &a) {
    return s << '(' << a.first << ", " << a.second << ')';
}
gene auto &operator<<(ostream &s, const vector<T> &a) {
    lv(i, a) cout << a[i] << (i + 1 == a.size() ? "" : " ");
    return s;
}
int main() {
    fast, prec(12);
    many {
        in(h);
        in(m);
        ou(24 * 60 - h * 60 - m);
    }
    return 0;
}
