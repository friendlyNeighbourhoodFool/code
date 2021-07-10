
#include <bits/stdc++.h>

using namespace std;

#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

typedef long long ll;




ll xa,ya,xb,yb,xf,yf;

int main(){
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	fast;
	int t=1;
	cin>>t;
	while(t--){
        cin>>xa>>ya>>xb>>yb>>xf>>yf;
    if(xa==xb&&xb==xf){
        if((yf>yb&&yf>ya)||(yf<ya&&yf<yb)){
            cout<<abs(xa-xb)+abs(ya-yb)<<endl;
        }else {
            cout<<abs(xa-xb)+abs(ya-yb)+2<<endl;
        }
    }else if(yb==ya&&yb==yf){
        if((xf>xb&&xf>xa)||(xf<xa&&xf<xb)){
            cout<<abs(xa-xb)+abs(ya-yb)<<endl;
        }else {
            cout<<abs(xa-xb)+abs(ya-yb)+2<<endl;
        }
    }else{
        cout<<abs(xa-xb)+abs(ya-yb)<<endl;
    }
    }
}