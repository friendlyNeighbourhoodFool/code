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

typedef long long ll;

string s;
int n;

int main()
{
    //	freopen("input.txt", "r", stdin);
    //	freopen("output.txt", "w", stdout);
    fast;
    int t = 1;
    cin >> t;
    while (t--)
    {

        cin >> n;

        cin >> s;
        int z = 0;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == '0')
                z++;
        if (z == 0)
        {
            cout << "DRAW" << endl;
            continue;
        }
        if (n == 1 or n % 2 == 0)
        {
            cout << "BOB" << endl;
            continue;
        }

        if (s[n / 2] == '0' and z == 1)
        {
            cout << "BOB" << endl;
            continue;
        }

        else if (s[n / 2] == '0')
        {
            cout << "ALICE" << endl;
            continue;
        }

        else if (s[n / 2] == '1')
        {
            cout << "BOB" << endl;
            continue;
        }
    }
}