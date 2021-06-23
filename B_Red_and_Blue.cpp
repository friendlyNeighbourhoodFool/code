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
    int n, m;
    cin >> n;
    int r[n];
    cin >> r[0];
    rep(i, 1, n)
    {
        int t;
        cin >> t;
        r[i] = r[i - 1] + t;
    }
    cin >> m;
    int b[m];
    cin >> b[0];
    rep(i, 1, m)
    {
        int t;
        cin >> t;
        b[i] = b[i - 1] + t;
    }
    int ans = 0;
    rep(i, 0, n) ans = max(ans, r[i]);
    int ans1 = 0;
    rep(i, 0, m) ans1 = max(ans1, b[i]);
    cout << ans + ans1 << endl;
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