
#include <bits/stdc++.h>


using namespace std;

#define endl '\n'
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);




int main(){
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	fast;
	int t=1;
	cin>>t;
	while(t--){
        int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a>c&&a>d&&b>c&&b>d)cout<<"NO\n";
    else if(c>a&&c>b&&d>a&&d>b)cout<<"NO\n";
    else cout<<"YES\n";
    }
}