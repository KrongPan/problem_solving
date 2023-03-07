#include <bits/stdc++.h>
using namespace std;

bool is_bipa();
int col[100001];
int bi[100001];
set<pair<int,int>> p;
vector<int> adj[100001];
int n, m, a, b;
int main()
{
    cin >> n >> m;
    bool f = 1;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
    col[a] = 1;
    col[b] = 2;
    for (int i = 2; i <= m; i++)
    {
        //cout << '[' << i << ']';
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
        if (!is_bipa())
        {
            cout << i - 1;
            return 0;
        }
    }
    cout << m;
}
bool is_bipa()
{
    queue<int> q;
    if(col[a] == 0)
    {
        if(col[b] == 1)
        {
            col[a] = 2;
        }
        else if(col[b] == 2) 
        {
            col[a] = 1;
        }   
        else
        {
            p.insert({a,b});
            return 1;
        }     
    }
    q.push(a);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto i : adj[u])
        {
            //cout << '[' << col[u] << ',' << col[504] << ']';
            if (col[i] == 0)
            {
                q.push(i);
                if (col[u] == 1)
                {
                    col[i] = 2;
                }
                else
                {
                    col[i] = 1;
                }
            }
            if (col[i] == col[u])
            {
                return 0;
            }
        }
    }
    return 1;
}
