/*
Champions Never Break. Believe in Yourself while Others Doubt You.
What defines us is .... How Will We Rise After Falling
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(NULL),               \
        cout.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
#define ld long double
#define mod 1000000009
#define debug(a...)        \
    cout << #a << ": ";    \
    for (auto it : a)      \
        cout << it << " "; \
    cout << endl;
#define fillall(x, val) memset(x, val, sizeof(x))
#define display(a...)      \
    for (auto it : a)      \
        cout << it << ' '; \
    cout << endl;
#define all(x) x.begin(), x.end()
#define maximum_int _INT_MAX_
#define minimum_int _WINT_MIN_

bool sortBySecond(const pair<ll, ll> &a, const pair<ll, ll> b)
{
    return a.second > b.second;
}
int ncr[1001][1001];
bool vis_ncr[1001][1001];
ll NCR(int n, int r)
{
    if (n < r)
        return 0;
    if (vis_ncr[n][r])
        return ncr[n][r];
    if (r == 0)
        return 1;
    if (r == 1)
        return n;
    if (n == 0)
        return 0;
    ncr[n][r] = (NCR(n - 1, r) % mod + NCR(n - 1, r - 1) % mod) % mod;
    vis_ncr[n][r] = true;
    return ncr[n][r];
}
bool isPrime[100005];
void _seive()
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
ll expo(int a, int b)
{
    if (b == 0)
        return 1;
    else if (b == 1)
        return a;
    else if (b % 2 == 0)
    {
        ll ret = expo(a, b / 2);
        ret = (ret % mod * ret % mod) % mod;
        return ret;
    }
    else
    {
        ll ret = expo(a, b / 2);
        ret = (ret % mod * ret % mod) % mod;
        ret = (ret % mod * a % mod) % mod;
        return ret;
    }
}
ll inverseMod(ll a, ll m) { return expo(a, m - 2) % m; }
ll fact[200006];
void factorial()
{
    fact[0] = fact[1] = 1;
    for (int i = 2; i < 100005; i++)
        fact[i] = (fact[i - 1] % mod * i % mod) % mod;
}
ll GCD(ll a, ll b)
{
    if (a == 0)
        return b;
    return GCD(b % a, a);
}
ll mult(ll a, ll b) { return (a % mod * b % mod) % mod; }
ll add(ll a, ll b)
{
    a += b;
    if (a >= mod)
        return a - mod;
    return a;
}
ll sub(ll a, ll b)
{
    a -= b;
    if (a < 0)
        return a + mod;
    return a;
}

/************Coding Arena***********/
map<ll, ll> mp;
ll ab;
int n;
void _run()
{
    cin >> n;
    mp.clear();
    vector<ll> a(n);
    ll sf = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            ab = a[i];
        else
            ab = ab & a[i];
        mp[a[i]]++;
    }
    if (mp[ab] < 2)
    {
        cout << 0 << endl;
        return;
    }
    sf = mp[ab];
    ll ans = 0;

    

    ans = ((sf % mod) * ((sf - 1) % mod)) % mod;
    
    ans = ((ans % mod) * (fact[n - 2] % mod)) % mod;
    cout << ans << endl;
}

/************TestCase Function**********/
int main()
{
    fast;
    //factorial();
    fact[0] = fact[1] = 1;
    for (int i = 2; i < 200006; i++)
        fact[i] = (fact[i - 1] % mod * i % mod) % mod;
    int test = 1;
    cin >> test;

    while (test--)
        _run();
    // for(int i = 1 ; i <= test ; i++)
    // {
    //     int ans = _run();
    //     cout << "Case #"<<i << ": " << ans << endl;
    // }
    return 0;
}