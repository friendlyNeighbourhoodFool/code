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
    multiset<int> s;
    rep(i, 1, n + 1) s.insert(i);
    cout << 2 << endl;
    auto it = s.end();
    it--;
    int n1 = *it;
    it--;
    it--;
    int n2 = *it;
    s.erase(n1);
    s.erase(n2);
    cout << n2 << " " << n1<<endl;
    s.insert((n1 + n2) / 2);
    while (s.size() > 1)
    {
        auto it = s.end();
        it--;
        n1 = *it;
        it--;
        n2 = *it;
        s.erase(n1);
        s.erase(n2);
        cout << n1 << " " << n2 << endl;
        s.insert((n1 + n2) / 2);
    }
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