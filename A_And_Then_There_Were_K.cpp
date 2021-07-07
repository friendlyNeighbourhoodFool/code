
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);


typedef long long ll;

void solve()
{
    ll n;
    cin>>n;
    if(n==1){
        cout<<0<<endl;
        return;
    }
    if(n%2==0){
        int ans = 2;
        while(ans<=n)ans*=2;
        ans/=2;
        cout<<ans-1<<endl;
        return;
    }else{
        int ans = 2;
        while(ans<=n)ans*=2;
        ans/=2;
        cout<<ans-1<<endl;
        return;
    }
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