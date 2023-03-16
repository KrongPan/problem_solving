#include <bits/stdc++.h>
using namespace std;

const int MAXN = 330;
int dp[MAXN][MAXN];

int main()
{
    string X, Y;
    cin >> X >> Y;

    int lenX = X.size();
    int lenY = Y.size();

    // initialize base case
    for (int i = 1; i <= lenX; i++)
    {
        dp[i][0] = i;
    }
    for (int j = 1; j <= lenY; j++)
    {
        dp[0][j] = j;
    }

    // fill up the table using the DP formula
    for (int i = 1; i <= lenX; i++)
    {
        for (int j = 1; j <= lenY; j++)
        {
            dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1); // insert or delete
            if (X[i - 1] == Y[j - 1])
            {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]); // no cost for matching characters
            }
            else
            {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1); // replace
            }
        }
    }

    cout << dp[lenX][lenY] << endl;

    return 0;
}
