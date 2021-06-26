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
int ze = 1;

void boobs()
{
    int n;
    cin >> n;
    string smainl, smainr, temp, aux;
    cin >> temp;
    int i1 = temp.size() - 1;
    while (temp[i1] != '*')
    {
        smainr += temp[i1];
        i1--;
    }
    reverse(smainr.begin(), smainr.end());
    i1=0;
    while (temp[i1]!='*')
    {
        smainl += temp[i1];
        i1++;
    }
    i1 = 0;
    int i2 = temp.size() - 1;
    while (temp[i2] != '*')
        i2--;
    while (temp[i1] != '*')
        i1++;
    i1++;
    while (i1 < i2)
        if (temp[i1] == '*')
            i1++;
        else
            aux += temp[i1], i1++;
    //reverse(smainl.begin(), smainl.end());
    n--;
    bool flag = true;
    while (n--)
    {
        string sl, sr;
        cin >> temp;
        i1 = temp.size() - 1;
        while (temp[i1] != '*')
        {
            sr += temp[i1];
            i1--;
        }
        reverse(sr.begin(), sr.end());
        i1=0;
        while (temp[i1] != '*')
        {
            sl += temp[i1];
            i1++;
        }
        //reverse(sl.begin(), sl.end());
        i1 = 0;
        i2 = temp.size() - 1;
        while (temp[i2] != '*')
            i2--;
        while (temp[i1] != '*')
            i1++;
        i1++;
        while (i1 < i2)
            if (temp[i1] == '*')
                i1++;
            else
                aux += temp[i1], i1++;
        i1 = smainr.size()-1, i2 = sr.size()-1;
        if (flag)
            while (i1 >= 0 && i2 >= 0)
            {
                if (sr[i2] != smainr[i1])
                    flag = false;
                i1--, i2--;
            }
        if (flag)
            if (sr.length() > smainr.length())
                smainr = sr;
        i1 = 0, i2 = 0;
        if (flag)
            while (i1 < smainl.size() && i2 < sl.size())
            {
                if (sl[i2] != smainl[i1])
                    flag = false;
                i1++, i2++;
            }
        if (flag)
            if (sl.size() > smainl.size())
                smainl = sl;
    }
    if (flag)
    {
        cout << "Case #" << ze << ": " << smainl + aux + smainr;
        cout << endl;
    }
    else
        cout << "Case #" << ze << ": "
             << "*\n";
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