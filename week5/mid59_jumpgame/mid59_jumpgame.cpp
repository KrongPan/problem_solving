#include <bits/stdc++.h>
using namespace std;

const int table_size = 20;
int table[table_size][table_size] = {0};
bool seen[table_size][table_size] = {false};
bool is_true;
void dfs_jump(int x, int y, int before);
int n, k;
int main()
{
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            cin >> table[i][j];
        }
    }
    is_true = false;
    dfs_jump(0, 0, table[0][0]);
    if (is_true)
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }
}
void dfs_jump(int x, int y, int before)
{
    // cout << x+1 << ',' << y+1  << '[' << is_true << ']' << '\n';
    if (is_true == true)
    {
        return;
    }
    if (x == n - 1 && y == n - 1)
    {
        is_true = true;
        return;
    }
    if (x >= n || y >= n || x < 0 || y < 0 || seen[x][y])
    {
        return;
    }
    seen[x][y] = true;
    if (table[x][y] <= before + k)
    {
        dfs_jump(x, y + 1, table[x][y]);
        dfs_jump(x + 1, y, table[x][y]);
        dfs_jump(x - 1, y, table[x][y]);
        dfs_jump(x, y - 1, table[x][y]);
    }
    return;
}