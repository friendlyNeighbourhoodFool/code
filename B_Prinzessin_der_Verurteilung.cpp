
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(NULL),               \
        cout.tie(NULL)

#define debug(a...)        \
    cout << #a << ": ";    \
    for (auto it : a)      \
        cout << it << " "; \
    cout << endl;
#define fillall(x, val) memset(x, val, sizeof(x))
#define display(a...)      \
    for (auto it : a)      \
        cout << it << ' '; \
    cout << endl;
#define all(x) x.begin(), x.end()

int n;
string s;

void fxn(){
     for(int len = 1 ; len <= 4 ; len++)
    {
        string start = "";
        string end = "";
        int x = len;
        while(x--)
            start += 'a',end += 'z';
        //cout << start << endl;
        while(start != end)
        {
            if(s.find(start) == string::npos)
            {
                cout << start << endl;
                return;
            }
            else
            {
                int pos = start.length()-1;
                while(start[pos] == 'z')
                    pos--;
                start[pos]++;
                for(int i = pos + 1 ; i < (start.size()) ; i++)
                    start[i] = 'a';
            }
        }
        if(s.find(end) == string::npos)
        {
            cout <<   end << endl;
            return;
        }
    }
}

void _run()
{
    cin >> n;
    cin >> s;
    fxn();
}



int main()
{
    fast;
    int test = 1;
    cin >> test;
    while (test--)
        _run();
    // for(int i = 1 ; i <= test ; i++)
    // {
    //     int ans = _run();
    //     cout << "Case #"<<i << ": " << ans << endl;
    // }
    return 0;
}