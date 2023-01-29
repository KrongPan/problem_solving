#include <iostream>
#include <vector>
using namespace std;

typedef struct dataM
{
    int bi;
    int ci;
    int si;
} dataM;

void print_map(vector<vector<dataM>> *map);

int main()
{
    int n, m, a, b, c, s;
    cin >> n >> m;
    vector<vector<dataM>> map[n];
    for (int i = 0; i < m; i++)
    {
        vector<dataM> temp;
        dataM data;
        cin >> a >> b >> c >> s;
        data.bi = b-1;
        data.ci = c;
        data.si = s;
        temp.push_back(data);
        map[a-1].emplace_back(temp);
        
    }
     
}

void print_map(vector<vector<dataM>> map[])
{
    cout << "-------------------" << '\n';
    cout << map[2].size();
    for (vector<dataM> i : map[2])
    {
        for (dataM j : i)
        {
            cout << j.bi+1 << ' ' << j.ci << ' ' << j.si ;
        }
        cout << '\n';
    }
    cout << "-------------------" << '\n';
}