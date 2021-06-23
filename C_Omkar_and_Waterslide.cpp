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

vector<int> nums;

void boobs()
{
    nums.push_back(109497);
    nums.push_back(983516);
    nums.push_back(698308);
    nums.push_back(409009);
    nums.push_back(310455);
    nums.push_back(528595);
    nums.push_back(524079);
    nums.push_back(18036);
    nums.push_back(341150);
    nums.push_back(641864);
    nums.push_back(913962);
    nums.push_back(421869);
    nums.push_back(943382);
    nums.push_back(295019);
    multiset<int> s;
    int b = nums.size() / 2;
    while (b--)
    {
        //cout<<1<<endl;
        int mg = INT_MIN, me1, me2;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == -1)
                continue;
            for (int j = i+1; j < nums.size(); j++)
            {
                if (nums[j] == -1 || j == i)
                    continue;
                if (__gcd(nums[i], nums[j]) >= mg)
                {
                    mg = __gcd(nums[i], nums[j]);
                    me1 = i;
                    me2 = j;
                }
            }
        }
        s.insert(mg);
        nums[me1] = -1;
        nums[me2] = -1;
        //cout<<me1<<" "<<me2<<endl;
    }
    // for(int i=0;i<nums.size();i++){
    //     cout<<nums[i]<<endl;
    // }
    int i = 1;
    int ans = 0;
    for (auto it = s.begin(); it != s.end(); it++)
    {
        //cout << *it << endl;
        ans += i * (*it);
        i++;
    }
    return ans;
}

int main()
{
    //	freopen("input.txt", "r", stdin);
    //	freopen("output.txt", "w", stdout);
    fast;
    int t = 1;
    //cin>>t;
    while (t--)
        boobs();
}