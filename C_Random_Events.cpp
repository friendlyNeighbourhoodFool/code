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

bool sbs(const pair<ll,ll>& a, const pair<ll,ll> b)    {return a.second > b.second;}

//comparator fxn in stl sort should return false if swap is to be done
//return a.first<b.first if first ke according increasing in comparator

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


// void solve()
// {
//     int n, m;
//     cin>>n>>m;
//     vector<int> a(n+1);
//     rep(i,1,n+1)cin>>a[i];
//     int last=-1;
//     pre(i,n,1){
//         if(a[i]!=i){
//             last=i;
//             break;
//         }
//     }
//     ld ans = 1;
//     rep(i,0,m){
//         int r;
//         ld p;
//         cin>>r>>p;
//         if(r>=last)ans*=1-p;
//     }
//     if(last==-1){
//         cout<<1<<endl;
//         return;
//     }
//     cout<<1.00-ans<<endl;
// }

//int A[]={6, -3, -10, 0, 2};
//int A[]={-1, -3, -10, 0, 60};
//int A[]={-2, -40, 0, -2, -3};
int A[]={-1,-1};
unordered_map<string,int> mp;

int solve(int idx,int ans){
    if(idx<0)return ans;
    string key = to_string(idx)+to_string(ans);
    if(mp.find(key)!=mp.end())return mp[key];
    return mp[key]=max(ans,max(solve(idx-1,ans*A[idx]),solve(idx-1,1)));
}

int main(){
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	fast;
    mp.clear();
	int ans = solve(1,1);
    //cout<<ans<<endl;
    // return 0;
    if(ans == 1)
        {
            int ma = INT_MIN;
            for(int i = 0 ; i < sizeof A ; i++)
            {
                ma=max(ma,A[i]);
                if(A[i]==1)cout<< 1;
                if(A[i]==-1){
                    int cnt = 0;
                    while(A[i]==-1){
                        cnt++;
                        i++;
                    }
                    if(cnt>=2){cout<< 1;return 0;}
                    i--;
                }
            }
            cout<< ma;
        }
        cout<<ans;
}