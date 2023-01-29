#include <bits/stdc++.h>
//#include <Windows.h>
using namespace std;

vector<vector<char>> adj;

list<int> ans;
int n, q;
int count = 0;
bool dfs(int x, int y, int xe, int ye, int layer, vector<vector<bool>> visited, bool dig);
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
    
    for (int i = 1; i < n-1; i++)
    {
        for (int j = 1; j < q-1; j++)
        {
            if (adj[i][j] == '.' && i!=xs-1 && j!= ys-1 && i!=xe-1 && j!=ye-1)
            {
                if (adj[i-1][j-1] == '.' && adj[i][j-1] == '.' && adj[i-1][j] == '.')
                {
                    adj[i][j] = '#';
                }
                else if (adj[i-1][j+1] == '.' && adj[i][j+1] == '.' && adj[i-1][j] == '.')
                {
                    adj[i][j] = '#';
                }
                else if (adj[i+1][j+1] == '.' && adj[i][j+1] == '.' && adj[i+1][j] == '.')
                {
                    adj[i][j] = '#';
                }
                else if (adj[i+1][j-1] == '.' && adj[i][j-1] == '.' && adj[i+1][j] == '.')
                {
                    adj[i][j] = '#';
                }
            }
        }
    }
    /*
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < q; j++)
        {
            cout << adj[i][j];
        }
        cout << '\n';
    }
    */
    dfs(xs - 1, ys - 1, xe - 1, ye - 1, 0, visited, false);
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

bool dfs(int x, int y, int xe, int ye, int layer, vector<vector<bool>> visited, bool dig)
{
    //Sleep(75);
    //cout << x + 1 << ',' << y + 1 << ',' << dig << '\n';
    if (adj[x][y] == '*' || adj[x][y] == '#')
    {
        return false;
    }
    if (x == xe && y == ye)
    {
        ans.push_back(layer);
        return true;
    }
    if (visited[x][y] == false && adj[x][y] != '#')
    {

        
        visited[x][y] = true;
        if (adj[x + 1][y] == '*' && dig == false)
        {
            // visited[x + 1][y] = true;
            dfs(x + 2, y, xe, ye, layer + 2, visited, true);
        }
        if (adj[x][y + 1] == '*' && dig == false)
        {
            // visited[x][y + 1] = true;
            dfs(x, y + 2, xe, ye, layer + 2, visited, true);
        }
        if (adj[x][y - 1] == '*' && dig == false)
        {
            // visited[x][y - 1] = true;
            dfs(x, y - 2, xe, ye, layer + 2, visited, true);
        }
        if (adj[x - 1][y] == '*' && dig == false)
        {
            // visited[x - 1][y] = true;
            dfs(x - 2, y, xe, ye, layer + 2, visited, true);
        }

        if (x + 1 < n && visited[x + 1][y] == false && adj[x + 1][y] != '#')
        {
            // cout << "[a]";
            dfs(x + 1, y, xe, ye, layer + 1, visited, dig);
        }
        if (y + 1 < n && visited[x][y + 1] == false && adj[x][y + 1] != '#')
        {
            // cout<< "[b]";
            dfs(x, y + 1, xe, ye, layer + 1, visited, dig);
        }
        if (y - 1 >= 0 && visited[x][y - 1] == false && adj[x][y - 1] != '#')
        {
            // cout << "[c]";
            dfs(x, y - 1, xe, ye, layer + 1, visited, dig);
        }
        if (x - 1 >= 0 && visited[x - 1][y] == false && adj[x - 1][y] != '#')
        {
            // cout << "[d]";
            dfs(x - 1, y, xe, ye, layer + 1, visited, dig);
        }
    }
    //cout << "return";
    return false;
}