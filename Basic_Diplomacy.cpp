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

bool isPrime[100005];
ll fact[100005];

bool sbs(const pair<ll, ll> &a, const pair<ll, ll> b) { return a.second > b.second; }

void seive()
{
    memset(isPrime, true, sizeof(isPrime));
    isPrime[1] = false;
    isPrime[2] = false;
    for (int i = 2; i * i <= 100005; i++)
    {
        for (int j = i * i; j <= 100005; j += i)
        {
            isPrime[j] = false;
        }
    }
}

void factorial()
{
    fact[0] = fact[1] = 1;
    for (int i = 2; i < 100005; i++)
        fact[i] = (fact[i - 1] % mod * i % mod) % mod;
}

long long power(long long x, int y, int p)
{
    long long res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

long long modInverse(long long n, int p)
{
    return power(n, p - 2, p);
}

long long nCrModPFermat(long long n, int r, int p)
{
    if (n < r)
        return 0;
    if (r == 0)
        return 1;
    long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;
    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}

void boobs()
{
    ll n, m;
    cin >> n >> m;
    map<ll, ll> mp;
    rep(i, 1, n + 1) mp[i] = 0;
    vector<ll> in[100000];
    bool flag = true;
    rep(i, 0, m)
    {
        ll k;
        cin >> k;
        while (k--)
        {
            ll f;
            cin >> f;
            mp[f]++;
            in[i].push_back(f);
        }
    }
    // for(auto it = mp.begin();it!=mp.end();it++)cout<<it->second<<" ";
    // cout<<endl;
    // return;
    map<ll, ll> already;
    vector<ll> ans;
    rep(i, 0, m)
    {
        vector<pair<ll, ll>> op;
        for (auto x : in[i])
        {
            pair<ll, ll> p = {mp[x]- already[x], x};
            op.push_back(p);
            //mp[x]--;
        }
        sort(op.begin(), op.end());
        // rep(i, 0, op.size()) cout << op[i].second << " ";
        // cout << endl;
        int idx = 0;
        while (idx < op.size() && already[op[idx].second] >= ceil(m / (double)2))
        {
            idx++;
        }
        if (idx == op.size())
        {
            cout << no << endl;
            return;
        }
        already[op[idx].second]++;
        ans.push_back(op[idx].second);
    }
    cout << yes << endl;
    rep(i, 0, m) cout << ans[i] << " ";
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