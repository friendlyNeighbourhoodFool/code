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

map<int, pair<int, int>> mp;
int arr[200001];
int n;

unsigned long long solve(unsigned long long x,
                         int y, int p)
{
    unsigned long long res = 1; // Initialize result

    x = x % p; // Update x if it is more than or
    // equal to p

    while (y > 0)
    {

        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

int main()
{
    //	freopen("input.txt", "r", stdin);
    //	freopen("output.txt", "w", stdout);
    fast;
    cin >> n;
    rep(i, 0, n) cin >> arr[i];
    int i = 0, j;
    while (i < n)
    {
        j = i + 1;
        while (j < n)
        {
            auto it = mp.find(arr[i] + arr[j]);
            if (it == mp.end())
                mp.insert({arr[i] + arr[j], {i, j}});
            else
            {
                if (it->second.first != i && it->second.first != j && it->second.second != i && it->second.second != j)
                {
                    cout << yes << endl;
                    cout << i + 1 << " " << j + 1 << " " << it->second.first + 1 << " " << it->second.second + 1 << " ";
                    return 0;
                }
            }
            j++;
        }
        i++;
    }
    cout << no << endl;
}