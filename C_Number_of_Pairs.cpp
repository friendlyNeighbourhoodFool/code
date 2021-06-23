
#include <bits/stdc++.h>


using namespace std;

#define endl '\n'
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define rep(i, j, n) for (int i = j; i < n; i++)

typedef long long ll;




int main()
{
    //	freopen("input.txt", "r", stdin);
    //	freopen("output.txt", "w", stdout);
    fast;
    int t = 1;
    cin >> t;
    while (t--){
        ll n, l, r;
    cin >> n >> l >> r;
    vector<ll> a(n);
    unordered_map<ll,ll> mp;
    rep(i, 0, n) cin >> a[i],mp[a[i]]=i;
    sort(a.begin(), a.end());
    vector<ll> mi(n, -1), ma(n, -1);
    rep(i, 0, n)
    {
        if(a[i]>r)continue;
        //for crossing min;
        ll rem = l - a[i];
        auto it = lower_bound(a.begin(), a.end(), rem);
        if (it == a.end())
        {
            mi[i] = -1;
            continue;
        }
        else
        {
            // if (it - a.begin() == i)
            // {
            //     auto tmp = it;
            //     it++;
            //     if (it != a.end() && *it + a[i] >= l && *it + a[i] <= r)
            //         mi[i] = it - a.begin();
            // }
             if (*it + a[i] >= l && *it + a[i] <= r)
            {
                mi[i] = it - a.begin();
            }
        }
        //for staying within r;
        rem = r - a[i];
        it = upper_bound(a.begin(), a.end(), rem);
        if (it == a.end() || *it > rem)
            it--;
        // if (it - a.begin() == i)
        // {
        //     auto tmp = it;
        //     it--;
        //     if (it - a.begin() > 0 && *it + a[i] >= l && *it + a[i] <= r)
        //         ma[i] = it - a.begin();
        // }
         if (*it + a[i] >= l && *it + a[i] <= r)
            ma[i] = it - a.begin();
    }
    //debug(mi);
    ll ans = 0;
    rep(i, 0, n)
    {
        if (mi[i] != -1 && ma[i] != -1)
        {
            if(i>=min(mi[i],ma[i])&&i<=max(mi[i],ma[i]))
            ans += abs(ma[i] - mi[i]);
            else ans+=abs(ma[i]-mi[i])+1;
        }
        //cout<<ans<<endl;
    }
    //cout<<ans<<endl;
    ans /= 2;
    cout << ans << endl;
    }
}