#include <bits/stdc++.h>
// #include <Windows.h>
using namespace std;

vector<vector<char>> adj;

list<int> ans;
bool dig = false;
int n, q;
int count = 0;
bool dfs(int x, int y, int xe, int ye, int layer, vector<vector<bool>> visited);
int main()
{
    int xs, ys, xe, ye;
    char c;
    cin >> n >> q;
    cin >> xs >> ys >> xe >> ye;
    vector<vector<bool>> visited;
    for (int i = 0; i < n; i++)
    {
        vector<bool> temp2;
        vector<char> temp;
        for (int j = 0; j < q; j++)
        {
            cin >> c;
            temp.push_back(c);
            temp2.push_back(false);
        }
        adj.push_back(temp);
        visited.push_back(temp2);
    }
    dfs(xs - 1, ys - 1, xe - 1, ye - 1, 0, visited);
    if (ans.size() == 0)
    {
        cout << -1;
    }
    else
    {
        int min = 2000000000;
        for (auto a : ans)
        {
            if (a < min)
            {
                min = a;
            }
        }
        cout << min;
    }
}

bool dfs(int x, int y, int xe, int ye, int layer, vector<vector<bool>> visited)
{
    // Sleep(75);
    if (adj[x][y] == '*' || adj[x][y] == '#')
    {
        return false;
    }
    if (x == xe && y == ye)
    {
        dig = false;
        ans.push_back(layer);
        return true;
    }
    if (visited[x][y] == false && adj[x][y] != '#')
    {
        // cout << x + 1 << ',' << y + 1 << ',' << dig << '\n';
        visited[x][y] = true;
        if (x + 1 < n && visited[x + 1][y] == false && adj[x + 1][y] != '#')
        {
            // cout << "[a]";
            if (adj[x + 1][y] == '*' && dig == false)
            {
                // visited[x + 1][y] = true;
                dig = true;
                dfs(x + 2, y, xe, ye, layer + 2, visited);
            }
            else if (adj[x + 1][y] != '*')
            {
                dfs(x + 1, y, xe, ye, layer + 1, visited);
            }
        }
        if (y + 1 < n && visited[x][y + 1] == false && adj[x][y + 1] != '#')
        {
            // cout<< "[b]";
            if (adj[x][y + 1] == '*' && dig == false)
            {
                // visited[x][y + 1] = true;
                dig = true;
                dfs(x, y + 2, xe, ye, layer + 2, visited);
            }
            else if (adj[x][y + 1] != '*')
            {
                dfs(x, y + 1, xe, ye, layer + 1, visited);
            }
        }
        if (y - 1 >= 0 && visited[x][y - 1] == false && adj[x][y - 1] != '#')
        {
            // cout << "[c]";
            if (adj[x][y - 1] == '*' && dig == false)
            {
                // visited[x][y - 1] = true;
                dig = true;
                dfs(x, y - 2, xe, ye, layer + 2, visited);
            }
            else if (adj[x][y - 1] != '*')
            {
                dfs(x, y - 1, xe, ye, layer + 1, visited);
            }
        }
        if (x - 1 >= 0 && visited[x - 1][y] == false && adj[x - 1][y] != '#')
        {
            // cout << "[d]";
            if (adj[x - 1][y] == '*' && dig == false)
            {
                // visited[x - 1][y] = true;
                dig = true;
                dfs(x - 2, y, xe, ye, layer + 2, visited);
            }
            else if (adj[x - 1][y] != '*')
            {
                dfs(x - 1, y, xe, ye, layer + 1, visited);
            }
        }
    }
    // cout << "return";
    return false;
}