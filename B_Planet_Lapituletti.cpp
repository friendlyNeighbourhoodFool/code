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

map<char, int> mp;
int h, m;

bool isC(int c_h, int c_m)
{
    string hn, mn;
    hn[0] = '1';
    hn[1] = c_h % 10 + '0';
    c_h /= 10;
    if (c_h == 0)
        hn[0] = '0';
    else
        hn[0] = c_h % 10 + '0';
    //cout<<h[1]<<h[0]<<endl;
    mn[0] = '1';
    mn[1] = c_m % 10 + '0';
    c_m /= 10;
    if (c_m == 0)
        mn[0] = '0';
    else
        mn[0] = c_m % 10 + '0';
    char a = mn[0], b = mn[1], c = hn[0], d = hn[1];
    if (mp.find(a) != mp.end() && mp.find(c) != mp.end() && mp.find(d) != mp.end() && mp.find(b) != mp.end())
    {
        a = mp[mn[0]]+'0', b = mp[mn[1]]+'0', c = mp[hn[0]]+'0', d = mp[hn[1]]+'0';
        int f1 = (a - '0') + ((b - '0') * 10);
        int f2 = (c - '0') + ((d - '0') * 10);
        if (f1 < h && f2 < m)
            return true;
    }
    return false;
}

void solve()
{

    cin >> h >> m;
    string s;
    cin >> s;
    int c_h = (s[1] - '0') + ((s[0] - '0') * 10);
    int c_m = (s[4] - '0') + ((s[3] - '0') * 10);
    int a_h, a_m;
    // isC(c_h, c_m);
    // return;
    while (1)
    {
        if (isC(c_h, c_m))
        {
            //cout << c_h << ":" << c_m << endl;
            string hn, mn;
            hn[0] = '1';
            hn[1] = c_h % 10 + '0';
            c_h /= 10;
            if (c_h == 0)
                hn[0] = '0';
            else
                hn[0] = c_h % 10 + '0';
            //cout<<h[1]<<h[0]<<endl;
            mn[0] = '1';
            mn[1] = c_m % 10 + '0';
            c_m /= 10;
            if (c_m == 0)
                mn[0] = '0';
            else
                mn[0] = c_m % 10 + '0';
            char a = mn[0], b = mn[1], c = hn[0], d = hn[1];
            cout << c << d << ":" << a << b << endl;
            break;
        }
        if (c_m < m - 1)
            c_m++;
        else if (c_h == h - 1 && c_m == m - 1)
            c_h = 0, c_m = 0;
        else if (c_h < h - 1 && c_m == m - 1)
            c_h++, c_m = 0;
    }
}

int main()
{
    mp['0'] = 0;
    mp['1'] = 1;
    mp['2'] = 5;
    mp['5'] = 2;
    mp['8'] = 8;
    //	freopen("input.txt", "r", stdin);
    //	freopen("output.txt", "w", stdout);
    fast;
    int t;
    cin >> t;
    while (t--)
        solve();
}