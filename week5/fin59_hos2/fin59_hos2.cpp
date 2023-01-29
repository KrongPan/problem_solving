#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
int bfs_all(int h);
int n, h;
int main()
{
    int m, a, b;
    cin >> n >> m >> h;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        adj.push_back(temp);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a >>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        int ans = bfs_all(i);
        //cout << "ans" << ' ' << ans << '\n';
        if (ans > max)
        {
            max = ans;
        }
    }
    cout << max;
    return 0;
}
int bfs_all(int v)
{
    bool seen[n] = {false};
    seen[v] = true;
    int layer[n];
    layer[v] = 0;
    list<int> q;
    int count = 0;
    q.push_back(v);
    while (!q.empty())
    {
        int u = q.front();
        /*
        for(auto i:q)
        {
            cout << '>' << i+1 << ' ';
        }
        */
        seen[u] = true;
        q.pop_front();
        for (int i:adj[u])
        {
            if (seen[i] == false)
            {
                count++;
                layer[i] = layer[u] + 1;
                q.push_back(i);
            }
            seen[i] = true;
            if (layer[i] > h)
            {
                //cout << "end" << '\n';
                return count;
            }
        }
        //cout << '\n';
    }
    count++;
    //cout << "end" << '\n';
    return count;
}