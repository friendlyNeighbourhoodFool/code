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
#define rep(i, j, n) for (ll i = j; i < n; i++)
#define pre(i, j, n) for (ll i = j; i >= n; i--)
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

void solve()
{
    ll n, k, x;
    scanf("%lld%lld%lld", &n, &k, &x);
    //cout<<n<<k<<x;
    vector<ll> a(n);
    rep(i, 0, n) scanf("%lld", &a[i]);
    if (n == k)
    {
        printf("%lld\n", n);
        return;
    }
    //sort(a.begin(), a.end());
    //rep(i,0,n)cout<<a[i];
    vector<pair<ll, ll>> lcms;
    ll n1 = n;
    vector<ll> a1(a);
    while (a1.size() > k)
    {
        ll bit, slc = LLONG_MAX;
        unordered_set<ll> sidx;
        rep(i, 1, (((ll)1) << ((ll)a1.size())) + 1)
        {
            ll lc = 1;
            ll selected = 0;
            rep(j, 0, a1.size())
            {
                if ((((ll)1) << j) & i)
                {
                    lc = (lc * a1[j]) / __gcd(lc, a1[j]);
                    selected++;
                }
            }

            if (lc <= slc && selected > k)
            {
                if (lc < slc)
                    slc = lc, sidx.clear();
                rep(j, 0, a1.size())
                {
                    if ((((ll)1) << j) & i)
                    {
                        sidx.insert(j);
                    }
                }
                // rep(j, 0, a1.size())
                // {
                //     if (!((((ll)1) << j) & i))
                //     {
                //         if (lc == (lc * a1[j]) / __gcd(lc, a1[j]))
                //         {
                //             sidx.insert(j);
                //         }
                //     }
                // }
            }
        }
        //cout<<a1.size()<<endl<<sidx.size()<<endl;
        lcms.push_back({slc, (ll)((ll)a1.size() - (ll)sidx.size())});
        for (auto x : sidx)
        {
            a1[x] = -1;
        }
        vector<ll> a2;
        rep(i, 0, a1.size())
        {
            if (a1[i] != -1)
                a2.push_back(a1[i]);
        }
        //a1.clear();
        a1 = a2;
    }
    pair<ll, ll> p = {x, LLONG_MIN};
    auto it = lower_bound(lcms.begin(), lcms.end(), p);
    if (lcms.size() == 0)
    {
        printf("%lld\n", n);
        return;
    }
    // for (auto x : lcms)
    // {
    //     cout << x.first<<" "<<x.second << endl;
    // }

    if (it == lcms.begin())
    {
        if (it->first == x)
        {
            printf("%lld\n", it->second);
            //cout<<it->second<<endl;
        }
        else
            printf("%lld\n", n);
        return;
    }
    if(it == lcms.end())it--;
    if (it->first > x )
        it--;

    printf("%lld\n", it->second);
    return;
}

int main()
{
    //	freopen("input.txt", "r", stdin);
    //	freopen("output.txt", "w", stdout);
    //fast;
    int t = 1;
    scanf("%d", &t);
    while (t--)
        solve();
}