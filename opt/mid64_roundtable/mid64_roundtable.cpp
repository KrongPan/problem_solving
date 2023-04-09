#include <bits/stdc++.h>
using namespace std;

vector<int> p;
int n;
int pl[200001];
int mi[200001];
int ans = 0;
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        p.push_back(i-c);
    }
    for(auto i:p)
    {
        //cout << i << ' ';
        if(i>=0)
        {
            pl[i]++;
            if(pl[i]+mi[(n-i)] > ans)
            {
                ans = pl[i]+mi[(n-i)];
            }
        }
        else
        {
            i = abs(i);
            mi[i]++;
            if(mi[i]+pl[n-i] > ans)
            {
                ans = mi[i]+pl[n-i];
            }
        }
    }
    cout << ans;
    return 0;
}
