#include <iostream>
#include <vector>
#include <list>
#include <set>
using namespace std;

bool is_bipa(vector<vector<int>> map);
int main()
{
    int k, n, m, a, b;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> n >> m;
        vector<vector<int>> map;
        for (int i = 0; i < n + 1; i++)
        {
            vector<int> temp;
            map.push_back(temp);
        }
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            map[a].push_back(b);
            map[b].push_back(a);
        }
        if (is_bipa(map) == true)
        {
            cout << "yes" << '\n';
        }
        else
        {
            cout << "no" << '\n';
        }
    }
}

bool is_bipa(vector<vector<int>> graph)
{
    int v[graph.size()];
    for (int i = 0; i < graph.size(); i++)
    {
        v[i] = -1;
    }
    for (int i = 0; i < graph.size(); i++)
    {
        if (v[i] == -1)
        {
            v[i] = 0;
            list<int> q;
            q.push_back(i);
            while (!q.empty())
            {
                int ind = q.front();
                q.pop_front();
                for (auto it : graph[ind])
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