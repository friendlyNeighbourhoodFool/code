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

ll ans = 0, r, c;
int arr[301][301];
int n[301][301];

priority_queue<pair<int, pair<int, int>>> mp;

int ze = 1;

void boobs()
{
    cin >> r >> c;
    int ma = INT_MIN, mi, mj;
    memset(arr, 0, sizeof arr);
    memset(n, 0, sizeof n);
    rep(i, 0, r)
    {
        rep(j, 0, c)
        {
            cin >> arr[i][j];
            n[i][j] = arr[i][j];
            mp.push({arr[i][j], {i, j}});
        }
    }
    //for (auto it = mp.begin(); it != mp.end(); it++)
    while(!mp.empty())
    {
        auto it = mp.top();
        mp.pop();
        if (it.first == 0)
            continue;
        int x = it.second.first;
        int y = it.second.second;
        if (x + 1 < r)
        {
            if (n[x + 1][y] < it.first - 1)
            {
                n[x + 1][y] = it.first - 1;
                mp.push({it.first - 1, {x + 1, y}});
            }
        }
        if (x - 1 >= 0)
        {
            if (n[x - 1][y] < it.first - 1)
            {
                n[x - 1][y] = it.first - 1;
                mp.push({it.first - 1, {x - 1, y}});
            }
        }
        if (y + 1 < c)
        {
            if (n[x][y + 1] < it.first - 1)
            {
                n[x][y + 1] = it.first - 1;
                mp.push({it.first - 1, {x, y + 1}});
            }
        }
        if (y - 1 >= 0)
        {
            if (n[x][y - 1] < it.first - 1)
            {
                n[x][y - 1] = it.first - 1;
                mp.push({it.first - 1, {x, y - 1}});
            }
        }
    }
    ll ans = 0;
    rep(i, 0, r)
    {
        rep(j, 0, c)
        {
            ans += n[i][j] - arr[i][j];
        }
    }
    cout << "Case #" << ze << ": " << ans << endl;
    ze++;
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