#include <bits/stdc++.h>
using namespace std;

int n,m;
int ans = 0;
vector<int> table;
int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        table.push_back(temp);
    }
    for(int i = 0; i < m; i++)
    {
        int d;
        cin >> d;
        ans = ans+d;
        ans += table[ans-1];
        if(ans < 1)
        {
            ans = 0;
        }
        else if(ans > n)
        {
            ans = n;
        }
    }
    cout << ans;
    return 0;
}