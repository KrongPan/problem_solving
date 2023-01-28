#include <bits/stdc++.h>
using namespace std;

int main()
{  
    int n,m,i,j;
    cin >> n >> m;
    vector<bool> done(n+1 ,false);
    vector<int> ans;
    for (int i  = 0; i< n+1;i++)
    {
        ans.push_back(0);
    }
    while(true)
    {
        cin >> i >> j;
        
        if (i == 0 && j == 0)
        {
            break;
        }
        if(ans[i] == 0)
        {
            ans[i] = j;
        }
        else
        {
            if (done[j] != true)
            {
                while(ans[i] != 0)
                {
                    i = ans[i];
                }
                ans[i] = j;
            }
        }
        done[j] = true;
    }
    
    for (int i = 0; i < n+1; i++)
    {
        //cout << done[i];
        if(done[i] == false)
        {
            int j = i;
            while(ans[j] != 0)
            {
                cout << j << ' ';
                j = ans[j];
            }
            if( j!=0)
            {
                cout << j << ' ';
            }
        }
    }
}