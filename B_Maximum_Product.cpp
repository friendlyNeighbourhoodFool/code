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



void solve()
{
    ll n;
    cin >> n;
    vector<ll> pos,neg;
    ll zero=0;
    rep(i, 0, n)
    {
        ll t;
        cin >> t;
        if(t>0)pos.push_back(t);
        else if(t<0) neg.push_back(t);
        else zero++;
    }
    sort(pos.begin(), pos.end(),greater<ll>());
    sort(neg.begin(),neg.end());
    ll op1=LLONG_MIN,op2=LLONG_MIN,op3=LLONG_MIN,op4=LLONG_MIN,op5=LLONG_MIN,op6=LLONG_MIN,op7=LLONG_MIN;
    if(neg.size()>=5)op1=max(neg[0]*neg[1]*neg[2]*neg[3]*neg[4],neg[neg.size()-1]*neg[neg.size()-2]*neg[neg.size()-3]*neg[neg.size()-4]*neg[neg.size()-5]);
    if(neg.size()>=4&&pos.size()>=1)op2=neg[0]*neg[1]*neg[2]*neg[3]*pos[0];
    if(neg.size()>=3&&pos.size()>=2)op3=neg[0]*neg[1]*neg[2]*pos[1]*pos[0];
    if(neg.size()>=2&&pos.size()>=3)op4=neg[0]*neg[1]*pos[2]*pos[1]*pos[0];
    if(neg.size()>=1&&pos.size()>=4)op5=neg[0]*pos[1]*pos[2]*pos[3]*pos[0];
    if(pos.size()>=5)op6=pos[0]*pos[1]*pos[2]*pos[3]*pos[4];
    if(zero>0)op7=0;
    cout<<max(op1,max(op2,max(op3,max(op4,max(op5,max(op6,op7))))))<<endl;
}

int main()
{
    //	freopen("input.txt", "r", stdin);
    //	freopen("output.txt", "w", stdout);
    fast;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}