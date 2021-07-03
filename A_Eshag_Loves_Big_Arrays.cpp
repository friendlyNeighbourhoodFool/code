
#include <bits/stdc++.h>


using namespace std;

#define endl '\n'
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define rep(i, j, n) for (int i = j; i < n; i++)

typedef long long ll;



void solve()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    rep(i,0,n)cin>>arr[i];
    sort(arr.begin(),arr.end());
    int p0=0;
    while(p0<arr.size()-1&&arr[p0]==arr[p0+1]){
        p0++;
    }
    p0++;
    cout<<n-p0<<endl;
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