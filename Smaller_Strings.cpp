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

bool sbs(const pair<ll,ll>& a, const pair<ll,ll> b)    {return a.second > b.second;}

//comparator fxn in stl sort should return false if swap is to be done
//return a.firt<b.first if first ke according increasing in comparator

void seive()
{
    memset(isPrime,true,sizeof(isPrime));
    isPrime[1] = false;
    isPrime[2] = true;
    for(int i = 2 ; i * i <= 100005 ; i++)
    {
        for(int j = i * i; j <= 100005 ; j += i)
        {
            isPrime[j] = false;
        }
    }
}

void factorial()
{
    fact[0] = fact[1] = 1;
    for(int i = 2 ; i < 100005 ; i++)
        fact[i] = (fact[i-1]%mod*i%mod)%mod;
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

int ze = 1;

void solve()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    if(s.size()==1){
        int ans = s[0]-97;
        cout<<"Case #"<<ze<<": "<<ans<<endl;
        ze++;
        return;
    }
    ll ans = 0;
    rep(i,0,ceil(n/(double)2)){
        ll avail = s[i]-97;
        //cout<<avail<<endl;
        ll u = ceil(n/(double)2);
        //cout<<u<<endl;
        if(u-i-1>0){
            ll y = power(k,u-i-1,mod);
        ans = (ans + (avail*y)%mod)%mod;}
        else ans=(ans+avail)%mod;
        //cout<<ans<<endl;
    }
    string s1 = s;
    rep(i,0,ceil(n/(double)2)){
        s1[n-i-1]=s[i];
    }
    //cout<<ans<<endl;
    //cout<<s1<<endl;
    if(s1<s)ans = (ans+1)%mod;
    cout<<"Case #"<<ze<<": "<<ans<<endl;
    ze++;
}

int main(){
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	fast;
	int t=1;
	cin>>t;
	while(t--)
		solve();
}