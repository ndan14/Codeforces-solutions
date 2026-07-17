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
const int maxn = 2e5;
const int maxk = 1e2;
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

int n, m, a[maxn + 2], fact[maxn + 2], ifact[maxn + 2], dp[maxk + 2][maxn + 2];

int add(int a, int b) {
    return (a % MOD + b % MOD) % MOD;
}

int sub(int a, int b) {
    return ((a % MOD - b % MOD) + MOD) % MOD;
}

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
    forr(i, 1, maxn) fact[i] = fact[i - 1] * i % MOD;
    ifact[maxn] = binpow(fact[maxn], MOD - 2, MOD);
    ford(i, maxn - 1, 0) ifact[i] = ifact[i + 1] * (i + 1) % MOD;
}   

int c(int n, int k) {
    if (k > n) return 0;
    return fact[n] * ifact[k] % MOD * ifact[n - k] % MOD;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen(file".inp", "r", stdin);
    freopen(file".out", "w", stdout);
#endif
    cin >> n >> m;
    forr(i, 1, n) cin >> a[i];
    init();
    while (m--) {
        int l, r, k;
        cin >> l >> r >> k;
        dp[k + 1][l] = add(dp[k + 1][l], 1);
        forr(i, 1, k + 1)
            dp[i][r + 1] = sub(dp[i][r + 1], c(r - l + k - i + 1, r - l));
    }
    ford(i, maxk + 1, 1)
        forr(j, 1, n) {
            dp[i][j] = add(dp[i][j], dp[i][j - 1]);
            dp[i - 1][j] = add(dp[i - 1][j], dp[i][j]);
        }
    forr(i, 1, n) cout << add(dp[0][i], a[i]) << " ";
    return 0;
}
