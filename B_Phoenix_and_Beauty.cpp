//think twice . code once
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

void solve()
{
    int n, k;
    cin >> n >> k;
    set<int> s;
    multiset<int> ms;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin>>t;
        if(s.find(t)==s.end())ms.insert(t);
        s.insert(t);
    }
    if(s.size()>k){
        cout<<-1<<endl;
        return;
    }
    while(ms.size()<k){
        ms.insert(1);
    }
    cout<<n*k<<endl;
    for(int i=0;i<n;i++){
        for(auto it = ms.begin();it!=ms.end();it++){
            cout<<*it<<" ";
        }
    }
    cout<<endl;

}

int main()
{
    //	freopen("input.txt", "r", stdin);
    //	freopen("output.txt", "w", stdout);
    fast;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}