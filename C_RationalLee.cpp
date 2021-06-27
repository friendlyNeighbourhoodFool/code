#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define rep(i, j, n) for (int i = j; i < n; i++)
#define pre(i, j, n) for (int i = j; i >= n; i--)
#define debug(a...)        \
    cout << #a << ": ";    \
    for (auto it : a)      \
        cout << it << " "; \
    cout << endl;
#define deb(a) cout << #a << " " << a << endl;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const string no = "NO", yes = "YES";
const ll inf = 1e18;
const int mod = 1e9 + 7;
const ld pi = acosl(-1.0);

void solve()
{
    ll n, k;
    cin >> n >> k;
    ll a[n];
    rep(i, 0, n) cin >> a[i];
    ll w[k];
    rep(i, 0, k)
    {
        cin >> w[i];
    }
    sort(a, a + n);
    sort(w, w + k);
    ll idxl = 0, idxr = n - 1, ans = 0;
    ll idx = 0;
    while (w[idx] == 1 && idx < k)
    {
        ans += 2 * a[idxr];
        idxr--;
        idx++;
    }
    pre(i, k - 1, idx)
    {
        ans += a[idxr];
        idxr--;
        ans += a[idxl];
        idxl++;
        w[i] -= 2;
        if (w[i] != 0)
            idxl += w[i];
    }
    cout << ans << endl;
}

int main()
{
    //	freopen("input.txt", "r", stdin);
    //	freopen("output.txt", "w", stdout);
    fast;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}