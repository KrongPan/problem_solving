#include <bits/stdc++.h>
//#include <Windows.h>
using namespace std;

int n,m;
int d[101];
int g[101];
int e[101];
int main()
{
    cin >> n >> m;
    int a,b,c;
    for(int i = 1; i < n; i++)
    {
        cin >> d[i] >> g[i] >> e[i];
    }
    int l = 1;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        if(a >= d[l])
        {
            d[l] = 0;
        }
        if(b >= g[l])
        {
            g[l] = 0;
        }
        if(c >= e[l])
        {
            e[l] = 0;
        }
        if(d[l] == 0 && g[l] == 0 && e[l] == 0)
        {
            if(l < n)
            {
                l++;
            }
            else
            {
                break;
            }
        }
    }
    cout << l;
    return 0;
}