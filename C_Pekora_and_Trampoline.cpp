
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define rep(i, j, n) for (int i = j; i < n; i++)

typedef long long ll;


void solve()
{
    int n;
    cin >> n;
    vector<ll> s(n), already(n, 0);
    rep(i, 0, n) cin >> s[i];
    //reverse(s.begin(),s.end());
    ll ans = 0;
    
    rep(i, 0, n)
    {
        if (s[i] > already[i] + 1)
            ans += s[i] - already[i] - 1, already[i] += s[i] - already[i] - 1;
        rep(j, 2, s[i] + 1) 
            if (i + j < n) already[i + j]++;
            else break;
        already[i] -= s[i] - 1;
        if (already[i] > 0 && i + 1 < n)
            already[i + 1] += already[i];
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