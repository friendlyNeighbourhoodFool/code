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
        ll n, m;
        cin >> n >> m;
        ll a[n], b[m];
        rep(i, 0, n) cin >> a[i];
        rep(i, 0, m) cin >> b[i];
        rep(i, 1, n) a[i] -= a[0];
        if(n==1){
            rep(i,0,m)cout<<a[0]+b[i]<<" ";
            return;
        }
        ll g = a[1];
        rep(i, 2, n) g = abs(__gcd(g, a[i]));
        rep(i, 0, m) cout << abs(__gcd(g, a[0] + b[i])) << " ";
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