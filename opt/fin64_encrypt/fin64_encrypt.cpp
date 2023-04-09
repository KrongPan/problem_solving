#include <bits/stdc++.h>
using namespace std;

int max_n = 20;
int d[20];
int table[4][5];
int n, s;
int main()
{
    cin >> n >> s;
    for(int i = 0; i < n; i++)
    {
        cin >> d[i];
    }
    for(int i = 1; i <= 20-n; i++)
    {
        d[n+i-1] = i;
    }
    // for(auto i:d)
    // {
    //     cout << '[' << i << ']';
    // }
    int i = 20-s;
    for(int a = 0; a < 4; a++)
    {
        for(int b = 0; b < 5; b++)
        {
            table[a][b] = d[i];
            i++;
            if(i == 20)
            {
                i = 0;
            }
        }
    }
    for(int a = 0; a < 5; a++)
    {
        for(int b = 0; b < 4; b++)
        {
            cout << table[b][a] << ' ';
        }
        //cout << '\n';
    }
    return 0;
}