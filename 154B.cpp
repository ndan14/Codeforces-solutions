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
const int maxn = 1e5 + 3;
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

int n, m, active[maxn], minprime[maxn], mul[maxn], owner[maxn];

void sieve() {
    for (int i = 2; i * i <= n; ++i)
        if (!minprime[i])
            for (int j = i * i; j <= n; j += i)
                if (!minprime[j])
                    minprime[j] = i;
    forr (i, 2, n) 
        if (!minprime[i])
            minprime[i] = i;
}

void fact(int x, bool type) {
    int tmp = x;
    vi primes;
    while (tmp > 1) {
        int p = minprime[tmp];
        primes.pb(p);
        while (tmp % p == 0) tmp /= p;
    }
    if (!type) {
        for (int a : primes) owner[a] = 0;
        cout << "Success";
    }
    else {
        int ans = -1;
        for (int a : primes) 
            if (owner[a]) {
                ans = owner[a];
                break;
            }
        if (ans == -1) {
            active[x] = 1;
            for (int a : primes) owner[a] = x;
            cout << "Success";
        }
        else cout << "Conflict with " << ans;
    }
}

void on(int x) {
    if (active[x]) {
        cout << "Already on";
        return;
    }
    fact(x, 1);
}

void off(int x) {
    if (!active[x]) {
        cout << "Already off";
        return;
    }
    active[x] = 0;
    fact(x, 0);
}

void solve() {
    char q;
    int num;
    cin >> q >> num;
    if (q == '+') on(num);
    else off(num);
    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen(file".inp", "r", stdin);
    freopen(file".out", "w", stdout);
#endif
    cin >> n >> m;
    sieve();
    while (m--) solve();
    return 0;
}
