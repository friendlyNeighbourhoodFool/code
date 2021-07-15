#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define rep(i, j, n) for (int i = j; i < n; i++)
#define pre(i, j, n) for (int i = j; i >= n; i--)


typedef long long ll;


void solve()
{
    int n;
    cin>>n;
    unordered_map<ll,vector<ll>> mp;
    for(int i=1;i<=n;i++){
        ll x;
        cin>>x;
        mp[x].push_back(i);
    }
    if(mp.size()==n){
        cout<<0<<endl;
        return;
    }
    ll ans = 0;
    for(auto it = mp.begin();it!=mp.end();it++){
        ll t1,t2;
        ll arr[it->second.size()]={0};
        arr[it->second.size()-1]=n-it->second[it->second.size()-1]+1;
        for(int i=it->second.size()-2;i>=0;i--){
            arr[i]=arr[i+1]+n-it->second[i]+1;
        }
        for(int i=0;i<it->second.size()-1;i++){
            t1=it->second[i];
            t2=arr[i+1];
            ans+=t1*t2;
        }
    }
    cout<<ans<<endl;
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