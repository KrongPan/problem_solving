#include <bits/stdc++.h>
using namespace std;


const int max_map = 30;
void dfs_cont(int x, int y, int cont, int count);
int adj[max_map][max_map] = {0};
bool seen[max_map][max_map] = {false};
bool is_true;

int min_c = 2000000000;
int R, C, A, B, X, Y, input;
int main()
{
    cin >> R >> C >> A >> B >> X >> Y;
    A--;
    B--;
    X--;
    Y--;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> adj[i][j];
        }
    }
    dfs_cont(A, B, adj[A][B], 0);
    cout << min_c;
}
void dfs_cont(int x, int y, int cont, int count)
{
    
    
    if (x >= R || y >= C || x < 0 || y < 0 || seen[x][y])
    {
        return;
    }
    //cout << x + 1 << ',' << y + 1 << '[' << count << ']' << '\n';
    if (cont != adj[x][y] && !seen[x][y])
    {
        count++;
    }
    if (x == X && y == Y)
    {
        //cout << "end" << ' ' << count << '\n';
        if (count < min_c)
        {
            min_c = count;
        }
        seen[x][y] = false;
        return;
    }
    
    seen[x][y] = true;
    dfs_cont(x, y + 1, adj[x][y], count);
    dfs_cont(x + 1, y, adj[x][y], count);
    dfs_cont(x - 1, y, adj[x][y], count);
    dfs_cont(x, y - 1, adj[x][y], count);
    seen[x][y] = false;
    return;
}