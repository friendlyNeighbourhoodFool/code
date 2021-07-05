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

long long binexp(long long x, int y)
{
    long long res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x);
        y = y >> 1;
        x = (x * x);
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

int n;
vector<ll> a(100001);

ll maxN;



ll occ[200001];
unordered_set<ll> pri;
vector<ll> powers[200001];

void factorise(ll num)
{
    unordered_set<ll> tmp;
    ll tmp2[num + 1];
    memset(tmp2, 0, sizeof tmp2);
    while (num > 1)
    {
        tmp.insert(factor[num]);
        tmp2[factor[num]]++;
        num /= factor[num];
    }
    for (auto x : tmp)
    {
        occ[x]++;
        powers[x].push_back(tmp2[x]);
        pri.insert(x);
    }
}

int main()
{
    //	freopen("input.txt", "r", stdin);
    //	freopen("output.txt", "w", stdout);
    //fast;
    scanf("%d", &n);
    maxN = LLONG_MIN;
    rep(i, 0, n)
    {
        scanf("%lld", &a[i]);
        maxN = max(maxN, a[i]);
    }
    memset(factor, -1, sizeof factor);
    precomp();
    rep(i, 0, n)
        factorise(a[i]);
    ll ans = 1;
    // rep(i, 2, 25) cout << factor[i] << " ";
    // return 0;
    for (auto x : pri)
    {
        sort(powers[x].begin(), powers[x].end());
        if (occ[x] == n - 1)
        {
            ans *= binexp(x, powers[x][0]);
        }
        else if (occ[x] == n)
        {
            ans *= pow(x, powers[x][1]);
        }
    }
    printf("%lld", ans);
}