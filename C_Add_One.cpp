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

long long power(long long x, ll y, int p)
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

//ll dp[200009];

// void solve()
// {
//     ll n, m;
//     cin >> n >> m;
//     ll ans = 0;
//     while (n > 0)
//     {
//         int t = n % 10;
//         n /= 10;
//         ans = (ans + dp[m + t - 1])%mod;
//     }
//     cout<<ans<<endl;
// }

// void precomp()
// {
//     string s = "1";
//     dp[0] = 1;

//     rep(i, 1, 200009)
//     {
//         ll ans = 0;
//         string snext = "";
//         rep(j, 0, s.size())
//         {
//             int k = s[j] - '0';
//             k++;
//             if (k <= 9)
//                 ans += 1;
//             else
//                 ans++;
//             snext += to_string(k);
//         }
//         s=snext;
//         dp[i] = ans % mod;
//     }
//     // rep(i,0,21)cout<<dp[i]<<endl;
//     // cout<<endl;
// }

int dp[101][27];

int solve(int idx,int curr,string s){
    if(idx==s.size())return 1;
    if(curr>26) return 0;
    if(dp[idx][curr]!=-1)return dp[idx][curr];
    if(curr*10+s[idx]-'0'<=26){
        if(s[idx]!='0'&&curr!=0)
        return dp[idx][curr]=solve(idx+1,curr*10+s[idx]-'0',s)+solve(idx+1,s[idx]-'0',s);
        else return dp[idx][curr]=solve(idx+1,curr*10+s[idx]-'0',s);
    }
        return dp[idx][curr]=solve(idx+1,s[idx]-'0',s);
}

int main()
{
    //	freopen("input.txt", "r", stdin);
    //	freopen("output.txt", "w", stdout);
    // fast;
    // int t = 1;
    // precomp();
    // cin >> t;
    // while (t--)
    //     solve();
    string s = "2101";
    bool flag = false;
        if(s[0]=='0')return 0;
        for(int i=1;i<s.size();i++){
            if(s[i]=='0'&&s[i-1]=='0')flag = true;
        }
        if(flag)return 0;
        memset(dp,-1,sizeof dp);
        return solve(0,0,s);
}
