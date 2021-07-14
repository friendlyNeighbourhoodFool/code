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

int n;
int ze = 1;

bool cmpo(string a, string b)
{
    return a <= b;
}

void solve()
{
    cin >> n;
    ll a;
    string s[n];
    rep(i, 0, n)
    {
        cin >> a;
        s[i] = "";
        while (a)
        {
            s[i] += a % 10 + '0';
            a /= 10;
        }
        reverse(s[i].begin(), s[i].end());
    }
    ll ans = 0;
    rep(i, 1, n)
    {
        if ((s[i].length()) <= (s[i - 1].length()))
        {
            ans += (s[i - 1].length()) - (s[i].length());
            int sm = 0, bg = 0;
            for (int j = 0; j < s[i].length(); j++)
            {
                if (s[i][j] > s[i - 1][j])
                {
                    bg = 1;
                    break;
                }
                if (s[i][j] < s[i - 1][j])
                {
                    sm = 1;
                    break;
                }
            }
            if (sm)
            {
                for (int j = s[i].length(); j < s[i - 1].length(); j++)
                {
                    s[i] += '0';
                }
            }
            else if (bg)
            {
                for (int j = s[i].length(); j < s[i - 1].length(); j++)
                {
                    s[i] += s[i - 1][j];
                }
            }
            else
            {
                int f = 0;
                int ind = -1;
                for (int j = s[i].length(); j < s[i - 1].length(); j++)
                {
                    if (s[i - 1][j] != '9')
                    {
                        f = 1;
                        ind = j;
                    }
                }
                if (!f)
                {
                    for (int j = s[i].length(); j < s[i - 1].length(); j++)
                    {
                        if (!f)
                        {
                            s[i] += '0';
                        }
                    }
                }
                else
                {
                    for (int j = s[i].length(); j < s[i - 1].length(); j++)
                    {
                        if (j == ind)
                        {
                            s[i] += s[i - 1][j] + 1;
                        }
                        else if (j < ind)
                        {
                            s[i] += s[i - 1][j];
                        }
                        else
                        {
                            s[i] += '0';
                        }
                    }
                }
            }
            if (cmpo(s[i], s[i - 1]))
            {
                s[i] += '0';
                ans++;
            }
        }
    }
    cout << "Case #" << ze << ": " << ans << endl;
    ze++;
}

int main()
{
    fast;
    int t = 1;
    cin >> t;
    rep(i, 0, t)
    {
        solve();
    }
    return 0;
}