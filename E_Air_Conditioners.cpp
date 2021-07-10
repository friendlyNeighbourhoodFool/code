/*
Champions Never Break. Believe in Yourself while Others Doubt You.
What defines us is .... How Will We Rise After Falling
Lazy People Work A little bit and start worrying they should be winning....
Winners work as hard as possible and and yet worry about are they being lazy
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(NULL),               \
        cout.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
#define ld long double
#define mod 1000000007
#define slen(x) x.length()
#define debug(a...)        \
    cout << #a << ": ";    \
    for (auto it : a)      \
        cout << it << " "; \
    cout << endl;
#define fillall(x, val) memset(x, val, sizeof(x))
#define display(a...)      \
    for (auto it : a)      \
        cout << it << ' '; \
    cout << endl;
#define all(x) x.begin(), x.end()
#define maximum_int _INT_MAX_
#define minimum_int _WINT_MIN_
#define INF LLONG_MAX
#define NEG_INF LLONG_MIN

bool sortBySecond(const pair<ll, ll> &a, const pair<ll, ll> b)
{
    return a.second > b.second;
}
int ncr[1001][1001];
bool vis_ncr[1001][1001];
ll NCR(int n, int r)
{
    if (n < r)
        return 0;
    if (vis_ncr[n][r])
        return ncr[n][r];
    if (r == 0)
        return 1;
    if (r == 1)
        return n;
    if (n == 0)
        return 0;
    ncr[n][r] = NCR(n - 1, r) + NCR(n - 1, r - 1);
    vis_ncr[n][r] = true;
    return ncr[n][r];
}
// template<typename... T>
// void log(T&&... args) {
//     ((cout << args << " "), ...);
//     cout << "\n";
// }
template <typename K, typename V>
void printMapMultipleValue(map<K, V> const &mp, string name)
{
    cout << name << ":\n";
    for (auto const &pa : mp)
    {
        cout << pa.first << " : ";
        cout << "{";
        for (auto const &x : pa.second)
            cout << x << ',';
        cout << "}\n";
    }
}
template <typename K, typename V>
void printMap(map<K, V> const &mp, string name)
{
    cout << name << ":" << endl;
    for (auto const &pa : mp)
        cout << "{" << pa.first << " : " << pa.second << "}" << endl;
}

bool isPrime[100006];
void _seive()
{
    memset(isPrime, true, sizeof(isPrime));
    isPrime[1] = false;
    isPrime[0] = false;
    for (int i = 2; i * i <= 100005; i++)
    {
        for (int j = i * i; j <= 100005; j += i)
        {
            isPrime[j] = false;
        }
    }
}
ll expo(int a, int b)
{
    if (b == 0)
        return 1;
    else if (b == 1)
        return a;
    else if (b % 2 == 0)
    {
        ll ret = expo(a, b / 2);
        ret = (ret % mod * ret % mod) % mod;
        return ret;
    }
    else
    {
        ll ret = expo(a, b / 2);
        ret = (ret % mod * ret % mod) % mod;
        ret = (ret % mod * a % mod) % mod;
        return ret;
    }
}
ll inverseMod(ll a, ll m) { return expo(a, m - 2) % m; }
ll fact[100005];
void factorial()
{
    fact[0] = fact[1] = 1;
    for (int i = 2; i < 100005; i++)
        fact[i] = (fact[i - 1] % mod * i % mod) % mod;
}
ll GCD(ll a, ll b)
{
    if (a == 0)
        return b;
    return GCD(b % a, a);
}
ll mult(ll a, ll b) { return (a % mod * b % mod) % mod; }
ll add(ll a, ll b)
{
    a += b;
    if (a >= mod)
        return a - mod;
    return a;
}
ll sub(ll a, ll b)
{
    a -= b;
    if (a < 0)
        return a + mod;
    return a;
}

/************Coding Arena***********/

ll n, k, already;
vector<ll> a(100), t(100);
ll ans[300001];
set<pair<ll, ll>> pq;

void in1()
{
    for (int i = 0; i < k; i++)
        cin >> a[i];
}

void in2()
{
    for (int i = 0; i < k; i++)
        cin >> t[i];
}

void init()
{
    for (int i = 1; i < n + 1; i++)
        ans[i] = LLONG_MAX;

    for (int i = 0; i < k; i++)
    {
        pq.insert({t[i], a[i]});
        ans[a[i]] = t[i];
    }
}

int main()
{
    //	freopen("input.txt", "r", stdin);
    //	freopen("output.txt", "w", stdout);
    fast;
    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        cin >> n >> k;

        a.resize(k);
        in1();
        t.resize(k);
        in2();
        pq.clear();
        init();

        already = 0;
        while (!pq.empty())
        {
            auto it = pq.begin();
            ll currt = it->first, currpos = it->second;
            ll posl = currpos - 1, posr = currpos + 1;
            pq.erase(it);
            if (posl > 0 && ans[posl] > (currt + 1))
            {
                ans[posl] = currt + 1;
                pq.insert({currt + 1, posl});
            }
            if (posr <= n && ans[posr] > (currt + 1))
            {
                ans[posr] = currt + 1;
                pq.insert({currt + 1, posr});
            }
            // rep(i,1,n+1)cout<<ans[i]<<" ";
            // cout<<endl;
        }
        for (int i = 1; i < n + 1; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
}