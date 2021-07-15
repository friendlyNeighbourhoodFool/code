/*
Cause I love the adrenalin in my vein
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

string s;
vector<int> st[27];
bool vis[27];
deque<int> dq;

bool dfs(int node, int par)
{
    vis[node] = true;
    for (auto x : st[node])
    {
        if (!vis[x])
        {
            if (dfs(x, node))
                return true;
        }
        else if (vis[x] && x != par)
        {
            return true;
        }
    }
    return false;
}

void solve()
{
    cin >> s;
    int n = s.size();
    if(n==1){
        cout<<yes<<endl;
        for(char jj='a';jj<='z';jj++)cout<<jj;
        cout<<endl;
        return;
    }
    memset(vis, false, sizeof vis);
    dq.clear();
    rep(i, 0, 27)
        st[i].clear();
    rep(i, 0, n - 1)
    {
        bool f1 = true, f2 = true;
        rep(j, 0, st[s[i] - 'a'].size()) if (st[s[i] - 'a'][j] == s[i + 1] - 'a') f1 = false;
        rep(j, 0, st[s[i + 1] - 'a'].size()) if (st[s[i + 1] - 'a'][j] == s[i] - 'a') f2 = false;
        if (f1)
            st[s[i] - 'a'].push_back(s[i + 1] - 'a');
        if (f2)
            st[s[i + 1] - 'a'].push_back(s[i] - 'a');
    }
    rep(i, 0, 27)
    {
        if (st[i].size() > 2)
        {
            cout << no << endl;
            return;
        }
    }
    if (dfs(s[0] - 'a', -1))
        cout << no << endl;
    else
    {
        cout << yes << endl;
        memset(vis, false, sizeof vis);
        dq.push_back(s[0] - 'a');
        int c = st[s[0] - 'a'][0];
        vis[s[0] - 'a'] = true;
        while (!vis[c])
        {
            dq.push_front(c);
            vis[c] = true;
            for (auto hh : st[c])
            {
                if (vis[hh] == false)
                    c = hh;
            }
        }
        if (st[s[0] - 'a'].size() > 1)
            c = st[s[0] - 'a'][1];
        while (!vis[c])
        {
            dq.push_back(c);
            vis[c] = true;
            for (auto hh : st[c])
            {
                if (vis[hh] == false)
                    c = hh;
            }
        }
        string ans = "";
        memset(vis, false, sizeof vis);
        while (!dq.empty())
        {
            int cc = dq.front();
            dq.pop_front();
            ans += (cc + 'a');
            vis[cc] = true;
        }
        for (int i = 0; i < 26; i++)
            if (vis[i] == false)
                ans += (i + 'a');
        cout << ans << endl;
    }
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