#include <bits/stdc++.h>
using namespace std;


int n,m;
int c;
int table[30][30];
int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> table[i][j];
        }
    }
    for(int i = 0; i < n; i++)
    {
        
        int s = 0;
        int x,y;
        for(int j = 0; j < m; j++)
        {
            c = 100000000;
            x = i;y = j;
            s = 0;
            while(x != -1)
            {
                s += table[x][y];
                x--;
            }
            if(c > s)
            {
                c = s;
            }
            s = 0;
            x = i;y = j;
            while(x != n)
            {
                s += table[x][y];
                x++;
            }
            if(c > s)
            {
                c = s;
            }
            s = 0;
            x = i;y = j;
            while(y != m)
            {
                s += table[x][y];
                y++;
            }
            if(c > s)
            {
                c = s;
            }
            s = 0;
            x = i;y = j;
            while(y != -1)
            {
                s += table[x][y];
                y--;
            }
            if(c > s)
            {
                c = s;
            }
            cout << c << ' ';
        }
        cout << '\n';
    }
}