#include <bits/stdc++.h>
using namespace std;

string s;
string t;
int ans = 0;
int main()
{
    cin >> s;
    cin >> t;
    int i = 0;
    for (auto j : s)
    {
        // cout << s;
    }
    for (auto a : t)
    {
        if (s[i] == a)
        {
            i++;
        }
        if (i == s.size())
        {
            ans++;
            i = 0;
        }
    }
    cout << ans;
    return 0;
}