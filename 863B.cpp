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
const int maxn = 105;
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

int n, w[maxn], ans = inf;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen(file".inp", "r", stdin);
    freopen(file".out", "w", stdout);
#endif
    cin >> n;
    n <<= 1;
    forr(i, 1, n) cin >> w[i];
    sort(w + 1, w + n + 1);
    forf(i, 1, n)
        forr(j, i + 1, n) {
            int tot = 0, cur;
            bool flag = 0;
            forr(k, 1, n) 
                if (k != i && k != j) {
                    if (!flag) {
                        cur = w[k];
                        flag = 1;
                    }
                    else {
                        tot += w[k] - cur;
                        flag = 0;
                    }
                }
            minimize(ans, tot);
        }
    cout << ans;
    return 0;
}
