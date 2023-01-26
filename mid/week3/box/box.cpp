using namespace std;
#include <iostream>
#include <vector>

int N, M;
vector<vector<char>> map;
int parth(int i, int j)
{
    //cout << '[' << i << ',' << j << ']' << '\n';
    map[i][j] = 'x';
    if (i == N - 2)
    {
        return 1;
    }
    if (map[i + 2][j] == '.' && map[i + 2][j+1] == '.')
    {
        if(parth(i + 1, j) == 1)
        {
            return 1;
        }
    }
    if (map[i][j + 2] == '.' && map[i + 1][j + 2] == '.' && j + 2 < M)
    {
        if(parth(i, j + 1))
        {
            return 1;
        }
    }
    if (map[i][j - 1] == '.' && map[i + 1][j - 1] == '.' && j - 1 > 0)
    {
        if(parth(i, j - 1))
        {
            return 1;
        }
    }
    if(i>0)
    {
        if (map[i - 1][j] == '.' && map[i - 1][j + 1] == '.' && i-1 > 0)
        {
            if(parth(i - 1, j))
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int i,j;
    cin >> N >> M;
    
    char in, before;
    for (int i = 0; i < N; i++)
    {
        vector<char> temp;
        for (int j = 0; j < M; j++)
        {
            cin >> in;
            temp.push_back(in);
        }
        map.push_back(temp);
    }
    for (i = 0; i < M - 1; i++)
    {
        if (map[0][i] == '.' && map[0][i + 1] == '.' && map[1][i] == '.' && map[1][i + 1] == '.')
        {
            //cout << i;
            if (parth(0, i) == 1)
            {
                cout << "yes";
                return 0;
            }
        }
    }
    cout << "no";
    return 0;
}