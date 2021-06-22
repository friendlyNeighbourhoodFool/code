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
    vector<int> a, b;
    rep(i, 0, n)
    {
        int t;
        cin >> t;
        a.push_back(t);
    }
    cin >> m;
    rep(i, 0, m)
    {
        int t;
        cin >> t;
        b.push_back(t);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int idx1 = 0, idx2 = 0, ans = 0;
    while (idx1 < n && idx2 < m)
    {
        if (a[idx1] < b[idx2] - 1)
        {
            idx1++;
            continue;
        }
        if (a[idx1] > b[idx2] + 1)
        {
            idx2++;
            continue;
        }
        if (abs(a[idx1] - b[idx2]) <= 1)
        {
            idx1++;
            idx2++;
            ans++;
            continue;
        }
    }
    cout << ans << endl;
}

int main()
{
    //	freopen("input.txt", "r", stdin);
    //	freopen("output.txt", "w", stdout);
    fast;
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
}