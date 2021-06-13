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


void solve()
{
    ll a,b,k;
    cin>>a>>b>>k;
    // if(k==1){
    //     cout<<yes<<endl;
    //     return;
    // }
    vector<ll> f,s;
    for(int i=2;i*i<=a;i++){
        if(a%i==0){
            while(a%i==0){
                f.push_back(i);
                a/=i;
            }
        }
    }
    if(a>1)f.push_back(a);
    for(int i=2;i*i<=b;i++){
        if(b%i==0){
            while(b%i==0){
                s.push_back(i);
                b/=i;
            }
        }
    }
    if(b>1)s.push_back(b);
    unordered_map<ll,ll> ff,ss;
    for(int i=0;i<f.size();i++)ff[f[i]]=f.size()-1;
    for(int i=0;i<s.size();i++)ss[s[i]]=s.size()-1;
    ff[1]=f.size()-1;
    ss[1]=s.size()-1;
    for(auto x:ff){
        auto it = ss.find(x.first);
        if(it!=ss.end()){
            if(it->second+x.second>=k){
                cout<<yes<<endl;
                return;
            }
        }
    }
    cout<<no<<endl;
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