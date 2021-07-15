/*
'Cause I love the adrenaline in my veins
*/
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

void boobs()
{
    ll n;
    cin >> n;
    vector<ll> v1, v2;
    v1.push_back(0);
    v2.push_back(0);
    rep(i, 1, n + 1)
    {
        ll t;
        cin >> t;
        if (i % 2)
            v1.push_back(v1[v1.size() - 1] + t);
        else
            v2.push_back(v2[v2.size() - 1] + t);
    }
    ll l1[v1.size() + 1], l2[v2.size() + 1];
    l1[1] = v1[1];
    l2[1] = v2[1];
    rep(i, 2, v1.size() + 1)
    {
        if (v1[i]-v1[i-1] < l1[i - 1])
            l1[i] = v1[i]-v1[i-1];
        else
            l1[i] = l1[i - 1];
    }
    rep(i, 2, v2.size() + 1)
    {
        if (v2[i]-v2[i-1] < l2[i - 1])
            l2[i] = v2[i]-v2[i-1];
        else
            l2[i] = l2[i - 1];
    }
    ll ans = n * v1[1] + n * v2[1];
    rep(i, 3, n + 1)
    {
        if (i % 2)
        {
            ll idx1 = i / 2 + 1, idx2 = i / 2;
            ll forv1 = l1[idx1], forv2 = l2[idx2];
            ll upv1 = v1[idx1], upv2 = v2[idx2];
            ll cost = upv1  + (n - idx1 ) * (forv1) + upv2  + (n - idx2 ) * (forv2);
            ans = min(cost, ans);
        }
        else
        {
            ll idx1 = i / 2, idx2 = i / 2;
            ll forv1 = l1[idx1], forv2 = l2[idx2];
            ll upv1 = v1[idx1], upv2 = v2[idx2];
            ll cost = upv1  + (n - idx1 ) * (forv1) + upv2  + (n - idx2 ) * (forv2);
            ans = min(cost, ans);
        }
        //cout<<ans<<endl;
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
        boobs();
}