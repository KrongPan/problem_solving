#include <bits/stdc++.h>
using namespace std;

int n,m,ans;
int p[101];
int c[101];
int main()
{
    cin >> n >> m;
    int a,b;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        if(c[a] < 5)
        {
            c[a]++;
            if(p[a] < b)
            {
                p[a] = b;
            }
        }
        else
        {
            p[a] = 0;
        }
    }
    ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ans+=p[i];
        //cout << p[i] << ' ';
    }
    //cout << '\n';
    cout << ans;
    return 0;
}