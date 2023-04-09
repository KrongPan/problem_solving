#include <bits/stdc++.h>
#include <Windows.h>
using namespace std;


vector<list<int>> v;
vector<bool> seen;
int n,m,k;
bool bfs(int a, int b, vector<bool>seen);

int main()
{
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
    {
        list<int> temp;
        v.push_back(temp);
        seen.push_back(false);
    }
    for(int i = 0; i < m; i++)
    {
        int a,b;
        cin >> a >> b;
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);
    }
    for(int i = 0; i < k; i++)
    {
        int a,b;
        cin >> a >> b;
        cout << bfs(a-1,b-1,seen) << '\n';
    }
}

bool bfs(int a,int b, vector<bool>seen)
{
    queue<int> q;
    q.push(a);
    while (!q.empty())
    {
        //Sleep(500);
        int u = q.front();
        
        seen[u] = 1;
        q.pop();
        for(auto i:v[u])
        {
            
            if(i == b)
            {
                return 1;
            }
            if(seen[i] == false)
            {
                //cout <<'['<< i << ',' << seen[i] << ']';
                seen[i] = 1;
                q.push(i);
            }
        }
        //cout << '\n';
    }
    return 0;
}