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
    int n;
    cin >> n;
    ll a[n];
    rep(i, 0, n) cin >> a[i];
    vector<ll> ans;
    ans.push_back(a[0]);
    rep(i, 1, n)
    {
        if (ans[ans.size() - 1] < 0)
        {
            if (a[i] < 0)
            {
                ans[ans.size() - 1] = max(a[i], ans[ans.size() - 1]);
            }
            else
            {
                ans.push_back(a[i]);
            }
        }
        else
        {
            if (a[i] < 0)
            {
                ans.push_back(a[i]);
            }
            else
            {
                ans[ans.size() - 1] = max(a[i], ans[ans.size() - 1]);
            }
        }
    }
    ll pr = 0;
    rep(i, 0, ans.size()) pr += ans[i];
    cout << pr << endl;
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