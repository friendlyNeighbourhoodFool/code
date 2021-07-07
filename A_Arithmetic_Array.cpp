
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define rep(i, j, n) for (int i = j; i < n; i++)

typedef long long ll;

int n;
vector<ll> a(1001);

int main()
{
    //	freopen("input.txt", "r", stdin);
    //	freopen("output.txt", "w", stdout);
    fast;
    int t = 1;
    cin >> t;
    while (t--)
    {
        cin >> n;
        ll sum = 0;
        for (int i = 0; i < n; i++)
            cin >> a[i], sum += a[i];
        if (sum==n)
        {
            cout << 0 << endl;
            continue;
        }
        else if (sum < n)
        {
            cout << 1 << endl;
            continue;
        }
        cout << sum - n << endl;    
    }
}