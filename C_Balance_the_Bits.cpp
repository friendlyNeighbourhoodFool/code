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
void pr()
{
    cout << yes << endl;
}

void pr2()
{
    cout << no << endl;
}

int n, oa, ob, la, lb, open, cnt;
string s;

bool cm1(char h)
{
    return h == '1';
}

bool cm2(int nn, int mm)
{
    return nn < mm;
}

void in()
{
    cin >> n;
    cin >> s;
}

void op1()
{
    oa++;
    ob++;
    cnt++;
}

void op2()
{
    oa--;
    ob--;
    cnt++;
}

void op3()
{
    oa++;
    ob--;
}

void op4()
{
    oa--;
    ob++;
}

void aa(string aaa,string bbb){
    cout<<aaa<<endl<<bbb<<endl;
}

void boobs()
{
    in();
    string a = "", b = "";
    oa = 0, ob = 0;
    la = 1, lb = 1;
    open = 0;
    rep(i, 0, n)
    {
        if (cm1(s[i]))
        {
            open++;
        }
    }
    if (open % 2)
    {
        pr2();
        return;
    }
    cnt = 0;
    open /= 2;
    rep(i, 0, n)
    {
        if (cm1(s[i]))
        {
            if (cm2(cnt, open))
            {
                a += '(';
                b += '(';
                op1();
            }
            else
            {
                a += ')';
                b += ')';
                op2();
            }
        }
        else
        {
            if (lb)
            {
                a += '(';
                b += ')';
                op3();
            }
            else
            {
                a += ')';
                b += '(';
                op4();
            }
            lb ^= 1;
        }
        if (oa < 0 || ob < 0)
        {
            pr2();
            return;
        }
    }
    if (oa || ob)
    {
        pr2();
        return;
    }
    pr();
    aa(a,b);
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
