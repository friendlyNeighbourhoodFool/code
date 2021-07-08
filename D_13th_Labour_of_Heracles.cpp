/*
'Cause I love the adrenaline in my veins
*/
#include <bits/stdc++.h>

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;

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

//comparator fxn in stl sort should return false if swap is to be done
//return a.first<b.first if first ke according increasing in comparator

void seive()
{
    memset(isPrime, true, sizeof(isPrime));
    isPrime[1] = false;
    isPrime[2] = true;
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

void solve()
{
    int n;
    cin >> n;
    vector<ll> w(n + 1);
    ll base = 0;
    rep(i, 1, n + 1) cin >> w[i], base += w[i];
    unordered_map<ll, vector<ll>> counter;
    ll in[n + 1] = {0};
    rep(i, 0, n - 1)
    {
        ll u, v;
        cin >> u >> v;
        in[u]++;
        in[v]++;
        counter[u].push_back(v);
        counter[v].push_back(u);
    }
    map<pair<ll, ll>, vector<pair<ll, ll>>> doub;
    for (auto it : counter)
    {
        if (in[it.first] > 1)
        {
            rep(i, 0, it.second.size())
            {
                doub[{w[it.first], it.first}].push_back({w[it.second[i]], it.second[i]});
            }
            sort(doub[{w[it.first], it.first}].rbegin(), doub[{w[it.first], it.first}].rend());
        }
    }
    ll ans[n] = {0};
    ans[1] = base;
    rep(i, 2, n)
    {
        if (doub.size() == 0)
        {
            ans[i] = ans[i - 1];
        }
        else
        {
            auto it = doub.end();
            it--;
            ll f = it->first.second, s = it->second[0].second;
            it->second.erase(it->second.begin());
            if (it->second.size() == 1)
                doub.erase({w[f], f});
            if (doub.find({w[s], s}) != doub.end())
            {
                pair<ll, ll> p = {w[f], f};
                auto it1 = find(doub[{w[s], s}].begin(), doub[{w[s], s}].end(), p);
                doub[{w[s], s}].erase(it1);
                if (doub[{w[s], s}].size() == 1)
                {
                    doub.erase({w[s], s});
                }
            }
            if (in[f] > 1)
            {
                base += w[f], in[f]--;
            }
            if (in[s] > 1)
            {
                base += w[s], in[s]--;
            }
            ans[i] = base;
        }
    }
    rep(i, 1, n) cout << ans[i] << " ";
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
        solve();
}