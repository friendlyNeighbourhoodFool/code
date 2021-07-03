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

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> eo, oo, oe, ee;
    rep(i, 0, s.size())
    {
        if ((i + 1) % 2 == 0)
        {
            if ((s[i] - '0') % 2 == 0)
                ee.push_back(s[i] - '0');
            else
                oe.push_back(s[i] - '0');
        }
        else
        {
            if ((s[i] - '0') % 2 == 0)
                eo.push_back(s[i] - '0');
            else
                oo.push_back(s[i] - '0');
        }
    }
    // cout<<eo.size()<<" "<<ee.size()<<" "<<oe.size()<<" "<<oo.size()<<endl;
    // return;
    int chal = n - 1;
    bool flag = true;
    while (chal--)
    {
        if (flag)
        {
            if (eo.size() >= 1)
                eo.pop_back();
            else
                oo.pop_back();
            flag = !flag;
        }
        else
        {
            if (oe.size() >= 1)
                oe.pop_back();
            else
                ee.pop_back();
            flag = !flag;
        }
    }
    if (eo.size() >= 1 || ee.size() >= 1)
        cout << 2 << endl;
    else
        cout << 1 << endl;
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