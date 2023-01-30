#include <bits/stdc++.h>
using namespace std;

bool is_bipa();
vector<vector<int>> adj;
int n,k;
int main()
{
    int m,a,b;
    cin >> n >> m >> k;
    for (int i = 0; i < n + 1; i++)
        {
            vector<int> temp;
            adj.push_back(temp);
        }
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    if (is_bipa())
    {
        cout << "yes" << '\n';
    }
    else
    {
        cout << "no" << '\n';
    }
}
bool is_bipa()
{
    int v[adj.size()];
    for (int i = 0; i < adj.size(); i++)
    {
        v[i] = -1;
    }
    for (int i = 0; i < adj.size(); i++)
    {
        if (v[i] == -1)
        {
            v[i] = 0;
            list<int> q;
            q.push_back(i);
            while (!q.empty())
            {
                for(auto o:q)
                {
                    cout << o << ',';
                }
                cout << '\n';
                for(auto o:v)
                {
                    cout << o << ',';
                }
                cout << '\n';
                int ind = q.front();
                q.pop_front();
                if(adj[ind].size() >= k)
                {
                    for (auto it : adj[ind])
                    {
                        if (v[it] == -1)
                        {
                            q.push_back(it);
                        }
                    }
                    continue;
                }
                for (auto it : adj[ind])
                {
                    if (v[it] == -1)
                    {
                        v[it] = !v[ind];
                        q.push_back(it);
                    }
                    else if (v[it] == v[ind])
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}