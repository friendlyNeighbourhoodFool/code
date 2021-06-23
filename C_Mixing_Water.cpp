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

void seive()
{
    memset(isPrime,true,sizeof(isPrime));
    isPrime[1] = false;
    isPrime[2] = false;
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

vector<ll> steps;

ll bs(ll h,ll c,ll t){
    ll l=0,r=steps.size()-1,mid;
    while(l<=r){
        mid=(l+r)/2;
        ll cs=steps[mid]/2;
        ll hs=steps[mid]-cs;
        ld tc=((cs*c)+(hs*h))/(ld)(hs+cs);
        if(tc<t)r=mid-1;
        else if(tc>t)l=mid+1;
        else break;
    }
    //op1
    ll mid1=mid+1;
    ll cs=steps[mid1]/2;
    ll hs=steps[mid1]-cs;
    ld tc1=((cs*c)+(hs*h))/(ld)(hs+cs);
    //op2
    ll mid2=mid-1;
    cs=steps[mid2]/2;
    hs=steps[mid2]-cs;
    ld tc2=((cs*c)+(hs*h))/(ld)(hs+cs);
    //op3
    cs=steps[mid]/2;
    hs=steps[mid]-cs;
    ld tc=((cs*c)+(hs*h))/(ld)(hs+cs);
    //return statements
    if(abs(tc1-t)<abs(tc2-t)&&abs(tc1-t)<abs(tc-t))return steps[mid1];
    else if(abs(tc2-t)<=abs(tc1-t)&&abs(tc2-t)<=abs(tc-t)) return steps[mid2];
    else return steps[mid];
}

void solve()
{
    ll h,c,t;
    cin>>h>>c>>t;
    if((h+c)/2==t){
        cout<<2<<endl;
        return;
    }
    ll ans = bs(h,c,t);
    ll mid1=ans;
    ll cs=ans/2;
    ll hs=ans-cs;
    ld tc1=((cs*c)+(hs*h))/(ld)(hs+cs);
    ld tc2=(c+h)/(ld)2;
    if(abs(tc2-t)<=abs(tc1-t))ans=2;
    cout<<ans<<endl;
}

void pr(){
    int turu=0;
    for(int h=2;h<5122;h++){
        for(int t=1;t<=h;t++){
            for(int c=1;c<=t;c++){
                if(h==c&&c==t)continue;
                //cout<<h<<" "<<c<< " "<<t<<endl;
                turu++;
                if(turu==5121){
                    cout<<h<<" "<<c<< " "<<t<<endl;
                    return;
                }
            }
        }
    }
}

int main(){
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	fast;
	int t=1;
    //pr();
    //return 0;
	cin>>t;
    for(int i=1;i<1000001;i+=2)steps.push_back(i);
	while(t--)
		solve();
}