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
    ll n, k;
    cin >> n >> k;
    ll mex = 0, ma = INT_MIN;
    vector<ll> vec;
    map<ll,ll> s;
    rep(i, 0, n)
    {
        ll t;
        cin >> t;
        vec.push_back(t);
        s.insert({t,1});
        ma = max(ma, t);
    }
    if(k==0){
        cout<<n<<endl;
        return;
    }
    sort(vec.begin(),vec.end());
    mex=0;
    rep(i,0,n){
        if(mex==vec[i])mex++;
        else break;
    }
    if (mex > ma)
        cout << n + k << endl;
    if (mex < ma)
    {
        ll c = ceil((mex + ma) / (double)2.0);
        if(s.find(c)==s.end())cout<<n+1<<endl;
        else cout<<n<<endl;
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
        solve();
}