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
#define ll long long int
#define ld double
#define pb push_back
#define rep(i, j, n) for (ll i = j; i < n; i++)
#define pre(i, j, n) for (ll i = j; i >= n; i--)
#define all(x) x.begin(), x.end()
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef pair<ll, ll> pll;
#define br "\n"
#define ff first
#define ss second

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

void solve()
{
    long n, m;
    cin >> n;
    m = n;
    vector<vll> v(n, vll(m));
    ll a1[] = {0, 0, 1, 1};
    ll a2[] = {1, 1, 0, 0};
    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            char c;
            cin >> c;
            if (c == 'S' || c == 'F')
                v[i][j] = 2;
            else
                v[i][j] = c - '0';
        }
    }
    ll temp[] = {v[1][0], v[0][1], v[n - 1][m - 2], v[n - 2][m - 1]};
    ll ans = 0;
    rep(i, 0, 4)
    {
        if (temp[i] != a1[i])
            ans++;
    }
    vector<pll> p;
    if (ans <= 2)
    {
        if (temp[0] != a1[0])
            p.pb({2, 1});
        if (temp[1] != a1[1])
            p.pb({1, 2});
        if (temp[2] != a1[2])
            p.pb({n, m - 1});
        if (temp[3] != a1[3])
            p.pb({n - 1, m});
        cout << p.size() << br;
        for (auto x : p)
            cout << x.ff << " " << x.ss << br;
        return;
    }
    ans = 0;
    rep(i, 0, 4)
    {
        if (temp[i] != a2[i])
            ans++;
    }
    if (ans <= 2)
    {
        if (temp[0] != a2[0])
            p.pb({2, 1});
        if (temp[1] != a2[1])
            p.pb({1, 2});
        if (temp[2] != a2[2])
            p.pb({n, m - 1});
        if (temp[3] != a2[3])
            p.pb({n - 1, m});
        cout << p.size() << br;
        for (auto x : p)
            cout << x.ff << " " << x.ss << br;
        return;
    }
}

int main()
{
    fast;
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
}
