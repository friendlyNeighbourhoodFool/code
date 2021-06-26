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

void run()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int countNumBit1(int mask)
{
    int ret = 0;
    while (mask)
    {
        mask &= (mask - 1);
        ++ret;
    }
    return ret;
}
const ll N = 500 + 9;
int arr[N];
int cnt, cur, n, x;
int main()
{
    run();
    int T = 1;
    cin >> T;
    while (T--)
    {
        cin >> n >> x;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cur = x;
        cnt = 0;
        bool ok = 1;
        while (1)
        {
            int f = -1, s = -1;
            for (int i = 0; i < n; i++)
            {

                for (int j = i + 1; j < n; j++)
                {
                    if (arr[i] > arr[j])
                    {
                        f = i;
                        s = j;
                        break;
                    }
                }
            }
            if (f == -1)
                break;

            for (int i = 0; i <= f; i++)
            {
                if (arr[i] > cur)
                {
                    swap(cur, arr[i]);
                    cnt++;
                }
            }

            if (arr[f] > arr[s])
            {
                ok = 0;
                break;
            }
        }
        if (ok)
            cout << cnt << "\n";
        else
            cout << "-1\n";
    }
}