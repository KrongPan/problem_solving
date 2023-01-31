#include <bits/stdc++.h>
using namespace std;

int shortestPath(int s, int e, int distance[]);
int n;
vector<list<pair<int, int>>> adj;
int main()
{
    int m, a, b, w;
    cin >> n >> m;
    int distance[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        distance[i] = 2000000000;
        list<pair<int, int>> temp;
        adj.push_back(temp);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> w;
        pair<int, int> temp;
        temp.first = b;
        temp.second = w;
        adj[a].push_back(temp);
        temp.first = a;
        adj[b].push_back(temp);
    }
    shortestPath(1, n, distance);
    return 0;
}

int shortestPath(int s, int e, int distance[])
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    bool seen[n + 1] = {false};
    distance[s] = 0;
    pq.push({0, s});
    while (!pq.empty())
    {
        int u = pq.top().second;
        if (distance[u] > pq.top().first)
        {
            distance[u] = pq.top().first;
        }
        // cout << u << " ";
        pq.pop();
        if (seen[u])
        {
            continue;
        }
        seen[u] = true;
        for (auto i : adj[u])
        {
            int v = i.first;
            int w = i.second;
            if (distance[v] > distance[u] + w)
            {
                distance[v] = distance[u] + w;
                //cout << distance[v] << ' ';
                pq.push({distance[v], v});
            }
        }
        // cout << '\n';
    }
    cout << distance[e];
    return 1;
}