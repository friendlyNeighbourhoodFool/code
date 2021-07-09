#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int n,q;
vector<int> a(100004);
void query()
{
	int l,r;
    cin >> l >> r;
    l--;
    r--;
    ll ans = 0;
    ans += a[r];
    if(l > 0)
        ans -= a[l-1];
   	cout << ans << endl;
}
int main()
{
	
    cin >> n >> q;
    string s;
    cin >> s;
    for(int i = 0 ; i < n ; i++)
        a[i] = s[i] -'a'+1;
    for(int i = 1 ; i < n ; i++)
        a[i] += a[i-1];
    for(int i = 0 ; i < q ; i++)
    {
        query();
    }   
}