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

int a[100];
int n;
map<pair<int, char>, int> mp;

int fuck(char last, int idx)
{
    if (idx == n)
        return 0;
    if (mp.find({idx, last}) != mp.end())
        return mp[{idx, last}];
    if (a[idx] == 0)
    {
        return mp[{idx, last}] = 1 + fuck('r', idx + 1);
    }
    if (a[idx] == 1)
    {
        if (last == 'r' || last == 'g')
            return mp[{idx, last}] = fuck('c', idx + 1);
        if (last == 'c')
            return mp[{idx, last}] = fuck('r', idx + 1) + 1;
    }
    if (a[idx] == 2)
    {
        if (last == 'r' || last == 'c')
            return mp[{idx, last}] = fuck('g', idx + 1);
        if (last == 'g')
            return mp[{idx, last}] = fuck('r', idx + 1) + 1;
    }
    if (a[idx] == 3)
    {
        if (last == 'r')
            return mp[{idx, last}] = min(fuck('g', idx + 1), fuck('c', idx + 1));
        if (last == 'g')
            return mp[{idx, last}] = fuck('c', idx + 1);
        if (last == 'c')
            return mp[{idx, last}] = fuck('g', idx + 1);
    }
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << fuck('r', 0);
}

int main()
{
    //	freopen("input.txt", "r", stdin);
    //	freopen("output.txt", "w", stdout);
    fast;
    int t = 1;
    //cin>>t;
    while (t--)
        solve();
}