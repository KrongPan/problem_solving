#include <bits/stdc++.h>
using namespace std;

int shortestPath(int s, int e, int distance[]);
int n;
vector<list<pair<int, int>>> adj;
int main()
{
    int m, a, b, w;
    cin >> n >> m;
    int distance[n+1];
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
    int parent[n];
    bool seen[n + 1] = {false};
    set<int> find;
    parent[s] = 0;
    distance[s] = 0;
    find.insert(s);
    while (s != e)
    {
        //cout << distance[n];
        int min = 2000000001;
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
        //cout << distance[u];
        seen[u] = true;
        for (auto i : adj[u])
        {
            //cout << i.first;
            find.insert(i.first);
            if ((distance[u] + i.second < distance[i.first]) && parent[u] != i.first)
            {
                distance[i.first] = distance[u] + i.second;
                parent[i.first] = u;
            }
        }
        //cout << '\n';
    }
    cout << distance[e];
    return 1;
}