#include <bits/stdc++.h>
using namespace std;

int main()
{  
    int n,m,a,b;
    
    while(true)
    {
        cin >> n >> m;
        if(n == 0 && m == 0)
        {
            return 0;
        }
        array<set<int>,101> w;
        bool seen[101];
        queue<int> ans;
        queue<int> q;
        for(int i = 0; i < m; i++)
        {
            cin >> a >> b;
            w[a].insert(b);
            seen[b] = 1;
        }
        for(int i = 1; i <= n; i++)
        {
            if(seen[i] == 0)
            {
                q.push(i);
                seen[i] = 1;
            }
        }
        while(q.size() != 0)
        {
            int u = q.front();
            q.pop();
            if(seen[u])
            {
                seen[u] = 0;
                ans.push(u);
                for(auto j: w[u])
                {
                    q.push(j);
                }
            }
        }
        while(ans.size() != 1)
        {
            cout << ans.front() << ' ';
            ans.pop();
        }
        cout << ans.front();
        cout << '\n';
    }
}