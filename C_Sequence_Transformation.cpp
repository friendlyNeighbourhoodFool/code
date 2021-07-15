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
    int n;
    cin >> n;
    int a[n + 1];
    int last[n + 1] = {-1}, ans[n + 1] = {-1};
    rep(i, 1, n + 1)
    {
        cin >> a[i];
        if (ans[a[i]] == -1)
            ans[a[i]] = 0;
        if (last[a[i]] == -1)
        {
            last[a[i]] = i;
            if (i != 1)
                ans[a[i]]++;
            continue;
        }
        if (i - last[a[i]] > 1)
            ans[a[i]]++;
        last[a[i]] = i;
    }
    rep(i, 1, n)
    {
        if (last[a[i]] != n)
            ans[a[i]]++;
    }
    int mia_khalifa = INT_MAX;
    rep(i, 1, n)
    {
        if (ans[a[i]] == -1)
            continue;
        mia_khalifa = min(mia_khalifa, ans[a[i]]);
    }
    cout << mia_khalifa << endl;
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