
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define rep(i, j, n) for (int i = j; i < n; i++)

typedef long long ll;




int main(){
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	fast;
	int t=1;
	cin>>t;
	while(t--){
        int n;
    cin>>n;
    vector<int> ev,od;
    rep(i,0,n){
        int t;
        cin>>t;
        if(t%2)od.push_back(t);
        else ev.push_back(t);
    }
    vector<int> a;
    rep(i,0,ev.size())a.push_back(ev[i]);
    rep(i,0,od.size())a.push_back(od[i]);
    int ans=0;
    rep(i,0,n){
        rep(j,i+1,n){
            if(__gcd(a[i],2*a[j])>1)ans++;
        }
    }
    cout<<ans<<endl;
    }
}