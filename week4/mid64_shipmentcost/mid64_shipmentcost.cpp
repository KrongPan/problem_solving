#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <queue>
using namespace std;

int S, T, A, B;

void print_map(vector<vector<int>> map);
void bfs();
int layer[100001];
int M, N;
vector<int> fac;
vector<int> sup;
vector<vector<int>> map;
int main()
{

    cin >> N >> M >> S >> T;

    for (int i = 0; i < N + 1; i++)
    {
        vector<int> temp;
        map.push_back(temp);
        layer[1 + i] = 2000000000;
    }
    for (int i = 0; i < M; i++)
    {
        cin >> A >> B;
        map[A].push_back(B);
        map[B].push_back(A);
    }
    // print_map(map);
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
    bfs();
    for(auto i: fac)
    {
        cout << layer[i] << '\n';
    }
}

void bfs()
{
    queue<int> q;
    for (auto i : sup)
    {
        q.push(i);
        layer[i] = 0;
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        int l = layer[u] + 1;
        for (auto m : map[u])
        {
            if (layer[m] > layer[u] + 1)
            {
                layer[m] = layer[u] + 1;
                q.push(m);
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