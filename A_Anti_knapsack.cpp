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
    bool arr[n + 1] = {false};
    bool flag = true;
    vector<int> ans;
    for (int i = k-1; i >= 1; i--)
    {
        if (i < k)
        {
            if (arr[i] == false)
            {
                //printf("%d ", i);
                //flag = false;
                ans.push_back(i);
                arr[k - i] = true;
            }
        }
        else if (i == k)
        {
            continue;
        }
        else
        {
            //flag = false;
            ans.push_back(i);
            //printf("%d ", i);
        }
    }
    for(int i=k+1;i<=n;i++)
        ans.push_back(i);
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++)
        cout<<ans[i]<<" ";
    printf("\n");
}

int main()
{
    //	freopen("input.txt", "r", stdin);
    //	freopen("output.txt", "w", stdout);
    //fast;
    int t;
    cin >> t;
    while (t--)
        solve();
}