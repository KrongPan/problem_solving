#include <bits/stdc++.h>
using namespace std;


bool seen[21][21];
int a,b;
int n,q;
bool gogo(int r,int c,int o,char m[][21]);
int main()
{
    cin >> n >> q;
    char m[21][21];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> m[i][j];
        }
    }
    int r,c;
    for(int i = 0; i < q; i++)
    {
        cin >> r >> c >> a >> b;
        char t[21][21];
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                t[i][j] = m[i][j];
                seen[i][j] = 0;
            }
        }
        if(gogo(r,c,0,t))
        {
            cout << "yes" << '\n';
        }
        else
        {
            cout << "no" << '\n';
        }
    }
}
bool gogo(int r,int c,int o,char m[][21])
{
    //cout << '[' << r << ',' << c << ']' << '\n';
    if(r == a && c == b)
    {
        a = 999;
        return 1;
    }
    if(seen[r][c])
    {
        return 1;
    }
    else
    {
        seen[r][c] = 1;
    }
    if(m[r][c] == '.')
    {
        if(r+1 <= n)
        {
            gogo(r+1,c,o,m);
        }
        if(c+1 <= n)
        {
            gogo(r,c+1,o,m);
        }
        if(r-1 > 0)
        {
            gogo(r-1,c,o,m);
        }
        if(c-1 > 0)
        {
            gogo(r,c-1,o,m);
        }
    }
    else if (m[r][c] == 'O')
    {
        if(o+1 < 2)
        {
            
            seen[r][c] = 0;
            o++;
            m[r][c] = '.';
            gogo(r,c,o,m);
        }
    }
    else
    {
        if(a == 999)
        {
            return 1;
        }
        return 0;
    }
    if(a == 999)
    {
        return 1;
    }
    return 0;
}