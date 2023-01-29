#include <iostream>
#include <vector>
#include <list>
#include <set>
using namespace std;

int main()
{
    int N, M, lv2, lv1;
    int count = 0;
    cin >> N >> M;
    lv2 = 0;
    lv1 = 0;
    vector<char> row(M,' ');
    vector<vector<char>> map(N, row);
    vector<vector<bool>> visited;
    list<int> x;
    list<int> y;
    set<char> ind;
    char in;
    for (int i = 0; i < N; i++)
    {
        vector<int> temp;
        vector<bool> tempv;
        for (int j = 0; j < M; j++)
        {
            cin >> in;
            if (in == '#')
            {
                tempv.push_back(true);
            }
            else
            {
                tempv.push_back(false);
            }
            map[i][j] = in;
        }
        visited.push_back(tempv);
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] != '#' && visited[i][j] == false)
            {
                x.push_back(i);
                y.push_back(j);
                visited[i][j] = true;
                while (x.size() != 0)
                {
                    cout << *x.begin() << ',' << *y.begin() << "\n";
                    count++;
                    if(map[*x.begin()][*y.begin()] == '*' || map[*x.begin()][*y.begin()] == '$')
                    {
                        ind.insert(map[*x.begin()][*y.begin()]);
                    }
                    if (*x.begin() - 1 >= 0 && visited[*x.begin() - 1][*y.begin()] == false)
                    {
                        x.push_back(*x.begin() - 1);
                        y.push_back(*y.begin()); 
                        visited[i-1][j] = true;
                    }
                    if (*y.begin() - 1 >= 0 && visited[*x.begin()][*y.begin() - 1] == false)
                    {
                        x.push_back(*x.begin());
                        y.push_back(*y.begin() - 1); 
                        visited[i][j-1] = true;
                    }
                    if (*y.begin() + 1 < M && visited[*x.begin()][*y.begin() + 1] == false)
                    {
                        x.push_back(*x.begin());
                        y.push_back(*y.begin() + 1); 
                        visited[i][j+1] = true;
                    }
                    if (*x.begin() + 1 < N && visited[*x.begin() + 1][*y.begin()] == false)
                    {
                        x.push_back(*x.begin() + 1);
                        y.push_back(*y.begin()); 
                        visited[i+1][j] = true;
                    }
                    x.erase(x.begin());
                    y.erase(y.begin());
                }
                if (ind.size() == 2)
                {
                    lv2 += count;
                }
                else if (ind.size() == 1)
                {
                    lv1 += count;
                }
                ind.clear();
                count = 0;
            }
        }
    }
    cout << lv2 << ' ' << lv1;
}