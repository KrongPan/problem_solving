#include <bits/stdc++.h>
using namespace std;

int n,m,k;
int c;
int table[201][201];
int main()
{
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> table[i][j];
        }
    }
    int max_t = 0;
    for(int j = 1; j <= m; j++)
    {
        int total = 0;
        for(int i = 1; i <= n; i++)
        {
            total+=table[i][j];
        }
        if(total > max_t)
        {
            max_t = total;
        }
    }
    cout << max_t;
    return 0;
}