#include <bits/stdc++.h>
using namespace std;

int r, c, b, t;
int table[11][11];
int ans;
bool is_e;
int main()
{
    cin >> r >> c >> b >> t;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> table[i][j];
        }
    }
    ans = 0;
    for (int i = 1; i <= r; i++)
    {
        int g = b;
        ans++;
        is_e = 1;
        for (int j = 1; j <= c; j++)
        {
            while (table[i][j] != 0)
            {
                is_e = 0;
                // cout << '[' << ans << ']';
                if (g >= t)
                {
                    g -= t;
                    table[i][j]--;
                }
                else
                {
                    ans++;
                    g = b;
                    g -= t;
                    table[i][j]--;
                }
            }
        }
        if (is_e)
        {
            ans--;
        }
        // cout << '[' << ans << ']';
    }
    cout << ans;
    return 0;
}