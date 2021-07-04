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

vector<ll> posb, negb, poss, negs;
int n, m;
//vector<ll> mpp, mpn;
ll tp = 0, tn = 0;
vector<ll> mpp(200001), mpn(200001);

ll calc_neg()
{
    ll ans = 0;
    rep(i, 0, negs.size())
    {
        auto it = lower_bound(negb.begin(), negb.end(), negs[i]);
        if (it == negb.begin() && *it > negs[i])
        {
            ans = max(ans, (ll)0);
            continue;
        }
        if (it == negb.end() || *it > negs[i])
            it--;
        ll box_train = it - negb.begin() + 1;
        ll p = negs[i] - box_train + 1;
        auto it2 = lower_bound(negs.begin(), negs.end(), p);
        if (it2 == negs.end())
            it2--;
        ll idx = it2 - negs.begin();
        //auto it3 = find(negs.begin(), negs.end(), negs[i]);
        ll extra = i - idx;
        //cout<<extra+1<<endl;
        ll mia = 0;
        mia = max((ll)0,tn- mpn[i]);
        //mia = max(mia, (ll)0);
        ans = max(extra + 1 + mia, ans);
        //cout << extra << " " << ans << endl;
    }
    //cout<<ans<<endl;
    return ans;
}

ll calc_pos()
{
    //int idx69 = 0;
    ll ans = 0;
    rep(i, 0, poss.size())
    {
        auto it = lower_bound(posb.begin(), posb.end(), poss[i]);
        if (it == posb.begin() && *it > poss[i])
        {
            ans = max(ans, (ll)0);
            continue;
        }
        if (it == posb.end() || *it > poss[i])
            it--;
        ll box_train = it - posb.begin() + 1;
        ll p = poss[i] - box_train + 1;
        auto it2 = lower_bound(poss.begin(), poss.end(), p);
        if (it2 == poss.end())
            it2--;
        ll idx = it2 - poss.begin();
        //auto it3 = find(poss.begin(), poss.end(), poss[i]);
        ll extra = i - idx;
        //cout<<extra+1<<endl;
        ll mia = 0;
        mia = max((ll)0, tp-mpp[i]);

        ans = max(extra + 1 + mia, ans);
        //cout<<ans<<endl;
        //cout<<ans<<endl;
    }
    return ans;
}

void boobs()
{

    scanf("%d", &n);
    scanf("%d", &m);
    //cin >> n >> m;
    // memset(mpp, 0, sizeof mpp);
    // memset(mpn, 0, sizeof mpn);
    rep(i,0,200001)mpp[i]=0;
    rep(i,0,200001)mpn[i]=0;
    rep(i, 0, n)
    {
        ll c;
        scanf("%lld", &c);
        //cin >> c;
        if (c < 0)
            negb.push_back(-1 * c);
        else
            posb.push_back(c);
    }
    reverse(negb.begin(), negb.end());
    rep(i, 0, m)
    {
        ll c;
        scanf("%lld", &c);
        //cin >> c;
        if (c < 0)
        {
            negs.push_back(-1 * c);
        }
        else
        {
            poss.push_back(c);
        }
    }
    //cout<<tp<<" "<<tn<<endl;
    ll ans = 0;
    reverse(negs.begin(), negs.end());
    int i1 = 0, i2 = 0;
    int emma = 0;
    while (i2 < poss.size())
    {
        if (i1 == posb.size())
        {
            mpp[i2] = emma;
            i2++;
            continue;
        }
        if (posb[i1] == poss[i2])
        {
            emma++;
            mpp[i2] = emma;
            i1++;
            i2++;
            continue;
        }
        mpp[i2] = emma;
        if (posb[i1] < poss[i2])
            i1++;
        else
            i2++;
    }
    tp=emma;
    i1 = 0;
    i2 = 0, emma = 0;
    while (i2 < negs.size())
    {
        if (i1 == negb.size())
        {
            mpn[i2] = emma;
            i2++;
            continue;
        }
        if (negb[i1] == negs[i2])
        {
            emma++;
            mpn[i2] = emma;
            i1++;
            i2++;
            continue;
        }
        mpn[i2] = emma;
        if (negb[i1] < negs[i2])
            i1++;
        else
            i2++;
    }
    tn=emma;
    if (poss.size() > 0 && posb.size() > 0)
        ans += calc_pos();
    if (negs.size() > 0 && negb.size() > 0)
        ans += calc_neg();
    // rep(i,0,poss.size())cout<<poss[i]<<" ";
    // cout<<endl;
    // rep(i,0,posb.size())cout<<posb[i]<<" ";
    // cout<<endl;
    printf("%lld\n", ans);
    //cout << ans << endl;
}

int main()
{
    //	freopen("input.txt", "r", stdin);
    //	freopen("output.txt", "w", stdout);
    //fast;
    int t = 1;
    scanf("%d", &t);
    //cin >> t;
    while (t--)
    {
        boobs();
        tp = 0;
        tn = 0;
        posb.clear();
        negb.clear();
        poss.clear();
        negs.clear();
        //mpp.clear();
        //mpn.clear();
    }
}