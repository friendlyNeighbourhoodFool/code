//think twice . code once
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define rep(i, j, n) for (int i = j; i < n; i++)
#define pre(i, j, n) for (int i = j; i >= n; i--)

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;

const string no = "NO", yes = "YES";
ll mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    int a[n + 1], b[n + 1], pos[n + 1];
    rep(i, 1, n + 1) cin >> a[i], pos[a[i]] = i;
    rep(i, 1, n + 1) cin >> b[i];
    int cnt[n + 1] = {0};
    rep(i, 1, n + 1)
    {
        int shift = pos[b[i]];
        int c = i - shift;
        if (c < 0)
            c = n + c;
        cnt[c]++;
    }
    int ans = INT_MIN;
    rep(i, 0, n + 1) ans = max(ans, cnt[i]);
    cout << ans << endl;
}

int main()
{
    //	freopen("input.txt", "r", stdin);
    //	freopen("output.txt", "w", stdout);
    fast;
    int t = 1;
    //cin>>t;
    while (t--)
        solve();
}