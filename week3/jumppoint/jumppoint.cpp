#include <iostream>
#include <vector>
#include <math.h>
#include <list>
using namespace std;

int main()
{
    int N, R, a, b, count;
    count = 0;
    vector<int> x;
    vector<int> y;
    list<int> q1;
    list<int> q2;
    int lev = 0;
    cin >> N >> R;
    vector<vector<int>> jump;
    vector<bool> vis;
    vis.push_back(false);
    vis.push_back(false);
    x.push_back(0);
    y.push_back(0);
    for (int i = 0; i < N; i++)
    {
        vis.push_back(false);
        cin >> a >> b;
        x.push_back(a);
        y.push_back(b);
    }
    x.push_back(100);
    y.push_back(100);
    vector<int> temp;
    N += 2;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)
            {
                continue;
            }
            if (sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2)) <= R)
            {
                temp.push_back(j);
            }
        }
        jump.push_back(temp);
        temp.clear();
    }
    /*
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < jump[i].size(); j++)
        {
            cout << jump[i][j] << ',';
        }
        cout << '\n';
    }
    */
    q1.push_back(0);
    while (q1.size() != 0)
    {
        if (vis[*q1.begin()] == false)
        {
            vis[*q1.begin()] = true;
            for(int i = 0; i < jump[*q1.begin()].size(); i++)
            {
                if (jump[*q1.begin()][i] != N-1)
                {
                    q2.push_back(jump[*q1.begin()][i]);
                }
                else 
                {
                    count++;
                    cout << count;
                    return 0;
                }
            }
        }
        q1.erase(q1.begin());
        if(q1.size() == 0)
        {
            q1 = q2;
            count++;
            q2.clear();
            //cout << '|' << q1.size() << '|';
        }
    }
    cout << -1;
    return 0;
}