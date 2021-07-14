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
}

int main()
{
    //	freopen("input.txt", "r", stdin);
    //	freopen("output.txt", "w", stdout);
    fast;
    int n;
    cin >> n;
    unordered_map<string, ll> mp;
    vector<pair<string, ll>> vec;
    rep(i, 0, n)
    {
        string s;
        cin >> s;
        ll num;
        cin >> num;
        vec.push_back({s, num});
        mp[s] += num;
    }
    map<ll, vector<string>> mp2;
    for (auto it : mp)
    {
        mp2[it.second].push_back(it.first);
    }
    auto it = mp2.end();
    it--;
    if (it->second.size() == 1)
    {
        cout << it->second[0];
        return 0;
    }
    sort(it->second.begin(), it->second.end());
    vector<string> tmp(it->second);
    mp.clear();
    rep(i, 0, n)
    {
        mp[vec[i].first] += vec[i].second;
        if (mp[vec[i].first] >= it->first && find(tmp.begin(), tmp.end(), vec[i].first) != tmp.end())
        {
            cout << vec[i].first;
            return 0;
        }
    }
}