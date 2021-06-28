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

ll factor[200001];

void factorise_sieve()
{
    int maxN = 200001;
    for (int i = 1; i <= maxN; i++)
        factor[i] = i;
    for (int i = 2; i <= maxN; i += 2)
        factor[i] = 2;
    for (int i = 3; i * i <= maxN; i++)
    {
        if (factor[i] == i)
        {
            for (int j = i * i; j < maxN + 1; j += i)
                if (factor[j] == j)
                    factor[j] = i;
        }
    }
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

int n, m, sx, sy;
bool vis[101][101];

bool isValid(int x, int y)
{
    if (x > n || x < 1 || y > m || y < 1)
        return false;
    if (vis[x][y] == true)
        return false;
    return true;
}

void solve(int x, int y)
{
    vis[x][y] = true;
    cout << x << " " << y << endl;
    for (int i = -(n - 1); i <= n - 1; i++)
    {
        if (isValid(x + i, y))
            solve(x + i, y);
    }
    for (int i = -(m - 1); i <= m - 1; i++)
    {
        if (isValid(x, y + i))
            solve(x, y + i);
    }
}

int main()
{
    //	freopen("input.txt", "r", stdin);
    //	freopen("output.txt", "w", stdout);
    fast;
    cin >> n >> m >> sx >> sy;
    memset(vis, false, sizeof vis);
    solve(sx, sy);
}