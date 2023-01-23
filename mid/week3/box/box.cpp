using namespace std;
#include <iostream>
#include <vector>

int N, M, i, j;

string parth(vector<vector<char>> map)
{
    if (i == N - 1)
    {
        return "yes";
    }
    if (map[i][j] == '.' && map[i][j - 1] == '.' && i < M - 1)
    {
        map[i - 1][j] == 'x';
        map[i - 1][j - 1] == 'x';
        i++;
        parth(map);
    }
    else if (map[i - 1][j + 1] == '.' && map[i][j + 1] == '.' && j < M - 1)
    {
        map[i - 1][j - 1] == 'x';
        map[i][j - 1] == 'x';
        j++;
        parth(map);
    }
    else if (map[i - 1][j - 1] == '.' && map[i][j - 1] == '.' && j > 1)
    {
        map[i - 1][j - 1] == 'x';
        map[i][j - 1] == 'x';
        j--;
        parth(map);
    }
    else
    {
        return "no";
    }
    return "no";
}

int main()
{
    vector<vector<char>> map;
    char in, before;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> in;
            map[i][j] = in;
        }
    }
    i = 1;
    j = 1;
    cout << parth(map);
    return 0;
}