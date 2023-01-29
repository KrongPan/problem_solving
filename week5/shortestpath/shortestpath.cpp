#include <bits/stdc++.h>
using namespace std;

int shortestPath(int s, int e, int distance[]);
vector<list<pair<int, int>>> adj;
int n;
int main()
{
    int m, a, b, w;
    cin >> n >> m;
    int distance[n];
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
        pair<int, int> temp2;
        temp2.first = a;
        temp2.second = w;
        adj[b].push_back(temp2);
    }
    /*
    for (auto i:adj) //print adj
    {
        for (auto j:i)
        {
            cout << j.first << ',' << j.second << ' ';
        }
        cout << '\n';
    }
    */
    shortestPath(1, n, distance);
    return 0;
}
int shortestPath(int s, int e, int distance[])
{
    bool seen[n + 1] = {false};
    set<int> find;
    int parent[n + 1];
    parent[s] = 0;
    distance[s] = 0;
    find.insert(s);
    while (s != e)
    {
        // cout << s << '\n';
        int min = 2000000000;
        int u = 0;
        for (auto i:find)
        {
            if (distance[i] < min && seen[i] == false)
            {
                // cout << "yay";
                min = distance[i];
                u = i;
            }
        }
        find.erase(u);
        s = u;
        seen[u] = true;
        for (auto i : adj[u])
        {
            find.insert(i.first);
            if ((distance[u] + i.second < distance[i.first]) && (i.first != parent[u]))
            {
                distance[i.first] = distance[u] + i.second;
                parent[i.first] = u;
            }
        }
    }
    cout << distance[e];
    return 1;
}