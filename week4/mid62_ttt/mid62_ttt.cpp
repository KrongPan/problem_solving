#include <bits/stdc++.h>
using namespace std;

int n,m;
void is_bipa();
int ttt[1001][1001];
int bi[1001];
set<int> seen;
queue<int> q;
int main()
{
    int a, b;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        ttt[a][b] = 1;
    }
    bi[1] = 1;
    is_bipa();
}

void is_bipa()
{   
    for(int u = 1; u <= n; u++)
    {
        for(int i = 1; i <= n; i++)
        {
            if(ttt[u][i] == 1 && (bi[i] == 0 || bi[i] == bi[u]))
            {
                q.push(i);
                if(bi[u] == bi[i])
                {
                    if(seen.find(u) == seen.end() || seen.find(i) == seen.end() )
                    {
                        seen.insert(i);
                        seen.insert(u);
                        cout << u << ' ' << i << '\n';
                    }

                }
                else if(bi[u] == 1)
                {
                    bi[i] = 2;
                }
                else if(bi[u] == 2)
                {
                    bi[i] = 1;
                }
            }
        }
    }
}