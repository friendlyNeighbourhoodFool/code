
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

typedef long long ll;

ll n, m, i, j;
ll distcor1, distcor2, distcor3, distcor4;

int main()
{
    //	freopen("input.txt", "r", stdin);
    //	freopen("output.txt", "w", stdout);
    fast;
    int t = 1;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> i >> j;
        distcor1 = abs(i - 1) + abs(j - 1);
        distcor2 = abs(i - 1) + abs(j - m);
        distcor3 = abs(i - n) + abs(j - 1);
        distcor4 = abs(i - n) + abs(i - m);
        if (distcor1 >= max(distcor2, max(distcor3, distcor4)))
        {
            cout << n << ' ' << m << ' ' << 1 << ' ' << 1 << endl;
        }
        else if (distcor2 >= max(distcor3, max(distcor1, distcor4)))
        {
            cout << n << ' ' << 1 << ' ' << 1 << ' ' << m << endl;
        }
        else if (distcor3 >= max(distcor4, max(distcor2, distcor1)))
        {
            cout << 1 << ' ' << m << ' ' << n << ' ' << 1 << endl;
        }
        else
        {
            cout << 1 << ' ' << 1 << ' ' << n << ' ' << m << endl;
        }
    }
}