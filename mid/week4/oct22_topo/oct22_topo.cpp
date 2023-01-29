#include <iostream>
#include <vector>
#include <list>
using namespace std;

void topoSort(vector<vector<int>> graph, int V);
int main()
{
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> graph;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        graph.push_back(temp);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
    }
    topoSort(graph, n);
}

void topoSort(vector<vector<int>> graph, int V)
{

    vector<int> in_degree(V, 0);
    vector<int> ans;
    for (int u = 0; u < V; u++)
    {
        for (int x : graph[u])
            in_degree[x]++;
    }

    list<int> q;
    for (int i = 0; i < V; i++)
    {
        if (in_degree[i] == 0)
        {
            q.push_back(i);
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop_front();
        ans.push_back(u + 1);
        for (int x : graph[u])
        {
            if (--in_degree[x] == 0)
            {
                q.push_back(x);
            }
        }
    }
    if (ans.size() == graph.size())
    {
        for (int i : ans)
        {
            cout << i << '\n';
        }
    }
    else
    {
        cout << "no";
    }
}