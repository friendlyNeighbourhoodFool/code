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

typedef long long ll;

vector<pair<int, int>> arr[50001];
//int cost[50001],load[50001]; ll toll[50001];
bool vis[50001];
vector<int> ans[50001];

void dfs(int pr, int v, int pn)
{
    vis[v] = true;
    if (pr != 0)
    {
        for (auto x : ans[pr])
            ans[v].push_back(x);
        ans[v].push_back(pn);
    }
    for (auto child : arr[v])
    {
        if (vis[child.first] == false)
            dfs(v, child.first, child.second);
    }
}

int ze = 1;

void solve()
{
    // arr->clear();
    // ans->clear();
    int n, q;
    scanf("%d%d",&n,&q);
    //cin >> n >> q;
    rep(i, 0, 50001) ans[i].clear(),arr[i].clear();
    //rep(i, 0, n+1) arr[i].clear();
    int cost[n], load[n];
    ll toll[n];
    rep(i, 0, n - 1)
    {
        int u, v, l;
        ll a;
        scanf("%d%d%d%lld",&u,&v,&l,&a);
        //cin >> u >> v >> l;
        //cin >> a;
        arr[u].push_back({v, i});
        arr[v].push_back({u, i});
        load[i] = l;
        toll[i] = a;
    }
    memset(vis, false, sizeof vis);
    dfs(0, 1, -1);
    // for(int i=1;i<=7;i++){
    //     for(auto x:ans[i])cout<<x<<" ";
    //     cout<<endl;
    // }
    //cout << "Case #" << ze << ": ";
    printf("Case #%d: ",ze);
    rep(i, 0, q)
    {
        int c, w;
        cin >> c >> w;
        ll an = 0;
        bool fl = true;
        for (auto x : ans[c])
        {
            if (load[x] <= w && !fl)
                an = __gcd(an, toll[x]);
            else if (load[x] <= w && fl)
                an = toll[x], fl = false;
        }
        //cout << "Case #" << ze << ": " << an<<endl;
        printf("%lld ",an);
        //cout << an << " ";
    }
    ze++;
    printf("\n");
    //cout << endl;
}

int main()
{
    //	freopen("input.txt", "r", stdin);
    //	freopen("output.txt", "w", stdout);
    //fast;
    int t = 1;
    scanf("%d",&t);
    //cin >> t;
    while (t--)
        solve();
}