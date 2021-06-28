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


void boobs()
{
    string s;
    cin>>s;
    int idx=-1;
    rep(i,0,s.size()-1){
        if(s[i]=='1'&&s[i+1]=='1'){
            idx=i;
            break;
        }
    }
    if(idx==-1){
        cout<<yes<<endl;
        return;
    }
    bool flag = true;
    rep(i,idx+2,s.size()-1){
        if(s[i]=='0'&&s[i+1]=='0'){
            flag = false;
            break;
        }
    }
    if(flag)cout<<yes<<endl;
    else cout<<no<<endl;
    
}

int main(){
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	fast;
	int t=1;
	cin>>t;
	while(t--)
		boobs();
}