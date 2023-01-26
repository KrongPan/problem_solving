#include <iostream>
#include <vector>
#include <list>
#include <array>
using namespace std;

void print_map(vector<vector<int>> map);
int bfs(vector<vector<int>> map, int s, int t);
int M, N;
int main()
{
    int S, T, A, B;
    vector<int> fac;
    vector<int> sup;
    cin >> N >> M >> S >> T;
    vector<vector<int>> map;
    for (int i = 0; i < N+1; i++)
    {
        vector<int> temp;
        map.push_back(temp);
    }
    for (int i = 0; i < M; i++)
    {
        cin >> A >> B;
        map[A].push_back(B);
        map[B].push_back(A);
    }
    //print_map(map);
    for (int i = 0; i < S; i++)
    {
        cin >> A;
        sup.push_back(A);
    }
    for (int i = 0; i < T; i++)
    {
        cin >> A;
        fac.push_back(A);
    }
    for (int i = 0; i < T; i++)
    {
        int min = 2000000000;
        for (int j = 0; j < S; j++)
        {
            int total = bfs(map,fac[i],sup[j]);
            if (min > total)
            {
                min = total;
            }
            //cout << total << '\n';
        }
        cout << min << '\n';
    }
}

int bfs(vector<vector<int>> map, int s, int t)
{
    bool visited[N+1];
    list<int> q;
    int layer[N+1];
    layer[s] = 0;
    q.push_back(s);
    for (int i = 0; i < N+1; i++)
    {
        visited[i] = false;
    }
    visited[s] = true;
    while (!q.empty())
    {
        int u = q.front();
        //cout << layer[u];
        q.pop_front();
        //cout << '[' << u << ',' << t << ']';
        if(u == t)
        {
            return layer[u];
        }
        
        for (int i = 0; i < map[u].size(); i++)
        {
            int v = map[u][i];
            if (visited[v] == false)
            {
                layer[v] = layer[u]+1;
                q.push_back(v);
                visited[v] = true;
            }
        }
    }
}

void print_map(vector<vector<int>> map)
{
    cout << "-------------------" << '\n';
    for (int i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < map[i].size(); j++)
        {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "-------------------" << '\n';
}