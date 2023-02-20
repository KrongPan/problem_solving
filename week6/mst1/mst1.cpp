#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m,a,b,w;
    cin >> n >> m;
    vector<vector<pair<int, int>>> tree;
    for (int i = 0; i < n; i++)
    {
        vector<pair<int, int>> temp;
        tree.push_back(temp);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> w;
        tree[a-1].push_back(pair(b-1,w));
    }
/////////////////////////////////////////////////////////////////////////////
    set<int> seen;
    int count = 0;
    int node = 0;
    for (int i = 0; i < n; i++)
    {
        cout << node << '\n';
        int min = 999999;
        pair<int,int> temp;
        for(auto j: tree[node])
        {
            if(j.second < min && seen.end() == (seen.find(j.first)))
            {
                min = j.second;
                temp = j;
            }
        }
        count += temp.second;
        seen.insert(temp.first);
        node = temp.first;
    }
    cout << count;
}

