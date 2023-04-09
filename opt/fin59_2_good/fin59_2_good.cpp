#include <bits/stdc++.h>
using namespace std;

int table[21][21];
int n, m;
float min_ans = 2000000000;
int ans;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> table[i][j];
        }
    }
    for (int i = n; i >= 1; i--)
    {
        float total = 0;
        for (int j = m; j >= 1; j--)
        {
            for (int a = 1; a <= n; a++)
            {
                if (a != i)
                {
                    total += abs(table[a][j] - table[i][j]);
                }
            }
            for (int b = 1; b <= m; b++)
            {
                if (b != j)
                {
                    total += abs(table[i][b] - table[i][j]);
                }
            }
            total /= n + m - 2;
            //cout << '[' << total << ']';
            if (total <= min_ans)
            {
                min_ans = total;
                ans = table[i][j];
            }
        }
    }
    cout << ans;
    return 0;
}