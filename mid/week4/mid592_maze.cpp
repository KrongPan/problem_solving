#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> adj;
vector<vector<bool>> visited;
int n;
bool dfs(int x, int y, int xe, int ye, bool door, vector<vector<bool>> visited);
int main()
{
    int q, xs, ys, xe, ye;
    char c;
    cin >> n >> q;
    vector<vector<bool>> visited;
    for (int i = 0; i < n; i++)
    {
        vector<bool> temp2;
        vector<char> temp;
        for (int j = 0; j < n; j++)
        {
            cin >> c;
            temp.push_back(c);
            temp2.push_back(false);
        }
        adj.push_back(temp);
        visited.push_back(temp2);
    }
    list<string> ans;
    for (int i = 0; i < q; i++)
    {

        cin >> xs >> ys >> xe >> ye;
        if (dfs(xs - 1, ys - 1, xe - 1, ye - 1, false, visited) == true)
        {
            ans.push_back("yes");
        }
        else
        {
            ans.push_back("no");
        }
        // cout << "-------------------------------";
    }
    for (auto a : ans)
    {
        cout << a << '\n';
    }
}

bool dfs(int x, int y, int xe, int ye, bool door, vector<vector<bool>> visited)
{

    if (x == xe && y == ye)
    {
        return true;
    }
    if (visited[x][y] == false && adj[x][y] != '#')
    {
        // cout << x+1 << ',' << y+1 << '\n';
        visited[x][y] = true;
        if (door == false && adj[x][y] == 'O')
        {
            // cout << "gu ger door";
            door = true;
        }
        else if (door == true && adj[x][y] == 'O')
        {
            // cout << "gu return";
            return false;
        }
        if (x + 1 < n)
        {
            if (dfs(x + 1, y, xe, ye, door, visited) == true)
            {
                return true;
            }
        }
        if (y + 1 < n)
        {
            if (dfs(x, y + 1, xe, ye, door, visited) == true)
            {
                return true;
            }
        }
        if (y - 1 >= 0)
        {
            if (dfs(x, y - 1, xe, ye, door, visited) == true)
            {
                return true;
            }
        }
        if (x - 1 >= 0)
        {
            if (dfs(x - 1, y, xe, ye, door, visited) == true)
            {
                return true;
            }
        }
    }
    return false;
}