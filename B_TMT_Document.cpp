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


const string no = "NO", yes = "YES";

string s;
int n,cntt,cntm;


void pr(){
    reverse(s.begin(),s.end());
}

void nig(){
    cout<<yes<<endl;
}


void solve()
{
    cin>>n;
    cin>>s;
    cntt=0,cntm=0;
    //vector<int> mind;
    rep(i,0,n){
        if(s[i]=='T')cntt++;
        else cntm++;
    }
    if(cntt!=2*cntm||s[0]=='M'||s[n-1]=='M'){
        cout<<no<<endl;
        return;
    }
    cntt=0,cntm=0;
    rep(i,0,n){
        if(s[i]=='T')cntt++;
        else cntm++;
        if(s[i]=='M'&&cntt<cntm){
            cout<<no<<endl;
            return;
        }
    }
    cntt=0,cntm=0;
    pr();
    
    rep(i,0,n){
        if(s[i]=='T')cntt++;
        else cntm++;
        if(s[i]=='M'&&cntt<cntm){
            cout<<no<<endl;
            return;
        }
    }
    
    // int idx=0;
    // while(idx<n){
        
    // }
    nig();
    
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