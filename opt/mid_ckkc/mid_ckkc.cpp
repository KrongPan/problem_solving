#include <bits/stdc++.h>
using namespace std;

int x;
vector<int> d;
char ans = 'K';
int main()
{
    cin >> x;
    int y;
    while(true)
    {
        cin >> y;
        if(y == 0)
        {
           break; 
        }
        else
        {
            d.push_back(y);
        }
    }
    if(d.size() > 0)
    {
        sort(d.begin(),d.end());
    }
    for(int i = 2559; i <= x; i++)
    {
        if(d.size() > 0)
        {
            if(i == d[0])
            {
                d.erase(d.begin());
                continue;
            }
        }
        if(ans == 'K')
        {
            ans = 'C';
        }
        else
        {
            ans = 'K';
        }
    }
    cout << ans;
    return 0;
}