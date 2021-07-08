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
    ll n, k;
    cin >> n >> k;
    n -= (k - 3);
    if (n % 2 == 1)
    {
        n--;
        cout << 1 << " " << n / 2 << " " << n / 2 << " ";
        rep(i, 0, k - 3) cout << 1 << " ";
        cout << endl;
        return;
    }
    if (n % 4 == 0)
    {
        cout << n / 2 << " " << n / 4 << " " << n / 4 << endl;
        rep(i, 0, k - 3) cout << 1 << " ";
        cout << endl;
        return;
    }
    cout << 2 << " " << n / 2 - 1 << " " << n / 2 - 1 << endl;
    rep(i, 0, k - 3) cout << 1 << " ";
    cout << endl;
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