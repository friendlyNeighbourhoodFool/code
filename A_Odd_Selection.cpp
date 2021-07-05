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
    int n, x, co = 0, ce = 0;
    cin >> n >> x;
    rep(i, 0, n)
    {
        int t;
        cin >> t;
        if (t % 2 == 0)
            ce++;
        else
            co++;
    }
    if (co % 2 == 0)
        co--;
    int xo = (x % 2 == 0) ? min(co, x - 1) : min(co, x);
    int xe = min(ce, x - xo);
    if(xo==0){
        cout<<"No\n";
        return;
    }
    if (xe <= x - 1 && xo + xe == x)
        cout << "Yes\n";
    else
        cout << "No\n";
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