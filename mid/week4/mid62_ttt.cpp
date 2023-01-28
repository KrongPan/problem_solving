#include <bits/stdc++.h>
using namespace std;

int n;
bool is_bipa(vector<vector<int>> map);
int main()
{
    int m, a, b;
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
        graph[b - 1].push_back(a - 1);
    }
    is_bipa(graph);
}

bool is_bipa(vector<vector<int>> graph)
{
    int v[graph.size()];
    int parent[graph.size()];
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
            list<int> layerC;
            layerC.push_back(1);
            int countlayer = 0;
            vector<int> count(n, 0);
            while (!q.empty())
            {
                countlayer++;
                if (countlayer == *layerC.begin())
                {
                    layerC.pop_front();
                    vector<int> count(n, 0);
                    countlayer = 0;
                }
                int ind = q.front();
                q.pop_front();
                int minicount = 0;
                for (auto it : graph[ind])
                {
                    if (v[it] == -1)
                    {
                        // cout << ind+1 << ',' << it+1;
                        // cout << '\n';
                        parent[it] = ind;
                        minicount++;
                        v[it] = !v[ind];
                        q.push_back(it);
                    }
                    else if (v[it] == v[ind])
                    {
                        count[it]++;
                        count[ind]++;
                        if (count[it] == 2)
                        {
                            cout << parent[it] + 1 << ' ' << it + 1;
                            return false;
                        }
                        else if (count[ind] == 2)
                        {
                            cout << parent[ind] + 1 << ' ' << ind + 1;
                            return false;
                        }
                    }
                }
                layerC.push_back(minicount);
                for (int c = 0; c < n; c++)
                {
                    if (count[c] == 1)
                    {
                        cout << parent[c] + 1 << ' ' << c + 1;
                        return false;
                    }
                }
            }
        }
    }
    return true;
}