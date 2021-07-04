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

vector<pair<int,int>> adj[10001];
bool vis[10001] = {false};
vector<int> dis(10001,1e9);
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

void bfs(int v, int d)
{
    pq.push({0,v});
    dis[v]=0;
    while(!pq.empty()){
        int curr=pq.top().second;
        int curr_d=pq.top().first;
        pq.pop();
        if(dis[curr]<curr_d)continue;
        for(pair<int,int> edge:adj[curr]){
            if(curr_d+edge.second<dis[edge.first]){
                dis[edge.first]=curr_d+edge.second;
                pq.push({dis[edge.first],edge.first});
            }
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    if (m == n)
    {
        cout << 0 << endl;
        return;
    }
    if (m < n)
    {
        cout << n - m << endl;
        return;
    }
    adj[1].push_back({2,1});
    adj[2].push_back({1,1});
    adj[2].push_back({4,1});
    for (int i = 3; i < 10001; i++)
    {
        adj[i].push_back({i - 1,1});
        if (2 * i <= 10000)
        {
            adj[i].push_back({2 * i,1});
        }
    }
    
    bfs(n, 0);
    cout << dis[m];
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