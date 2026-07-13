#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define file "test"
#define forr(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define ford(i, b, a) for (int i = (b), _a = (a); i >= _a; --i)
#define forf(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; ++i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define MASK(i) (1LL << (i))
#define bit(x, i) (((x) >> (i)) & 1)
#define bp __builtin_popcountll
const int maxn = 1e6 + 3;
const int MOD = 1e9 + 7; // 998244353 // 1e9 + 2277 // 1e9 + 5277
const int inf = 1e18;
const int oo = 1e9 + 7;
const float eps = 1e-6;

template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        if (x > y) {
            x = y;
            return 1;
        }
        return 0;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        if (x < y) {
            x = y;
            return 1;
        }
        return 0;
    }
/* END OF TEMPLATE. WHAT A SIGMA! TAKE A DEEP BREATH AND READY FOR CODING :D */

int a, b, n, fact[maxn], ifact[maxn];

int binpow(int a, int b, int m) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void init() {
    fact[0] = 1;
    forr(i, 1, n) fact[i] = fact[i - 1] * i % MOD;
    ifact[n] = binpow(fact[n], MOD - 2, MOD);
    ford(i, n - 1, 0) ifact[i] = ifact[i + 1] * (i + 1) % MOD;
}

int C(int n, int k) {
    return fact[n] * ifact[k] % MOD * ifact[n - k] % MOD;
}

bool check(int x, int a, int b) {
    while (x) {
        if (x % 10 != a && x % 10 != b) return 0;
        x /= 10;
    }
    return 1;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen(file".inp", "r", stdin);
    freopen(file".out", "w", stdout);
#endif
    cin >> a >> b >> n;
    init();
    int ans = 0;
    forr(i, 0, n) {
        int sum = a * i + b * (n - i);
        if (check(sum, a, b)) ans = (ans + C(n, i)) % MOD;
    }
    cout << ans;
    return 0;
}
