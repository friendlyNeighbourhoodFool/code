#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(NULL),               \
        cout.tie(NULL)

#define debug(a...)        \
    cout << #a << ": ";    \
    for (auto it : a)      \
        cout << it << " "; \
    cout << endl;
#define fillall(x, val) memset(x, val, sizeof(x))
#define display(a...)      \
    for (auto it : a)      \
        cout << it << ' '; \
    cout << endl;


int main()
{
    fast;
    int test = 1;
    cin >> test;
    while (test--)
    {
        int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0  ; i < n ; i++)
        cin >> a[i];
    cout << (n/2 * 6) << endl;
    for(int  i = 1; i < n ; i+=2)
    {
        cout << 2 << ' ' << i << ' ' << i +1 << endl;
        cout << 1 << ' ' << i << ' ' << i +1 << endl;
        cout << 2 << ' ' << i << ' ' << i +1 << endl;
        cout << 2 << ' ' << i << ' ' << i  +1<< endl;
        cout << 1 << ' ' << i<< ' ' << i +1 << endl;
        cout << 2 << ' ' << i<< ' ' << i +1 << endl;
    }
    }
    return 0;
}