#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, s, t, a, b, c;
    cin >> n >> m >> s >> t;
    vector<vector<int>> bridg[n];
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        vector<int> temp;
        temp.push_back(b-1);
        temp.push_back(c);
        bridg[a-1].push_back(temp);
    }
}