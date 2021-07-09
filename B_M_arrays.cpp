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
#define debug(a...)        \
    cout << #a << ": ";    \
    for (auto it : a)      \
        cout << it << " "; \
    cout << endl;
#define deb(a) cout << #a << " " << a << endl;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const string no = "NO", yes = "YES";
const ll inf = 1e18;
const int mod = 1e9 + 7;
const ld pi = acosl(-1.0);

int n, m;
ll ans;

unsigned long long power(unsigned long long x, int y, int p)
{
    unsigned long long res = 1;

    x = x % p;

    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;

        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

void pri()
{
    cout << "1\n";
    return;
}

void nih(ll ans)
{
    cout << ans << endl;
}

bool fio(int i, int m)
{
    if (m % 2 == 0 && i == m / 2)
        return true;
    return false;
}

void boobs()
{
}

int main()
{
    //	freopen("input.txt", "r", stdin);
    //	freopen("output.txt", "w", stdout);
    fast;
    int t = 1;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        vector<int> rem(m, 0);
        rep(i, 0, n)
        {
            ll in;
            cin >> in;
            in %= m;
            rem[in]++;
        }
        if (n == 1)
        {
            pri();
            continue;
        }
        ans = 0;
        rep(i, 1, m)
        {
            if (fio(i, m))
            {
                break;
            }
            if (!rem[i] && !rem[m - i])
            {
                continue;
            }
            if (!rem[i] || !rem[m - i])
            {
                ans += max(rem[i], rem[m - i]);
                rem[i] = 0;
                rem[m - i] = 0;
                continue;
            }
            int mn = min(rem[i], rem[m - i]);
            ans++;
            rem[i] -= mn;
            rem[m - i] -= mn;
            rem[i] -= 1;
            rem[m - i] -= 1;
            if (rem[i] > 0 || rem[m - i] > 0)
            {
                ans += max(rem[i], rem[m - i]);
            }
            rem[i] = 0;
            rem[m - i] = 0;
        }
        if (rem[0])
        {
            ans++;
        }
        if (m % 2 == 0 && rem[m / 2])
        {
            ans++;
        }
        nih(ans);
        
    }
}