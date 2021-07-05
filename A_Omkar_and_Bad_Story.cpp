
#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(NULL),               \
        cout.tie(NULL)

#define display(a...)      \
    for (auto it : a)      \
        cout << it << ' '; \
    cout << endl;

    

int n;
map<ll,ll> mp;
void _run()
{
    
    cin >> n;
    vector<ll> arr(n);
    for(int i = 0 ; i < n ;i++)
        cin >> arr[i];
    mp.clear();
   
    for(int i = 0 ; i < n; i++)
        mp[arr[i]]++;
    
    queue<ll> q;
    for(int i =0 ; i < n ;i++)
    {
        for(int j = i + 1 ; j < n ; j++)
        {
            ll dif = abs(arr[i]-arr[j]);
            if(mp.find(dif) == mp.end())
            {
                q.push(dif);
                mp[dif]++;
            }
        }
    }
    //display(arr);
    while(!q.empty())
    {
        if(arr.size() > 300)
        {
            cout<<"NO\n";
            return;
        }

        ll curr = q.front();
        q.pop();
        arr.push_back(curr);
        for(int i = 0 ; i< arr.size() -1; i++)
        {
            ll dif = abs(arr[i] - curr);
            if(mp.find(dif) == mp.end())
            {
                q.push(dif);
                mp[dif]++;
            }
        }
    }
    cout<<"YES\n";
    cout << arr.size() << endl;
    display(arr);
}

/************TestCase Function**********/

int main()
{
    fast;
    int test = 1;
    cin >> test;
    while (test--)
        _run();
    // for(int i = 1 ; i <= test ; i++)
    // {
    //     int ans = _run();
    //     cout << "Case #"<<i << ": " << ans << endl;
    // }
    return 0;
}