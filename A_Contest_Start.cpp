#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        ll n , x, t;
        cin >> n >> x >> t;
        ll b = t/x;
        ll ans = 0;
        if(b < n)
        {
            cout << (n - b)* b + (b*(b-1))/2 << endl;
        }
        else
        {
            cout << (n*(n-1))/2 << endl;
        }
        
    }
}