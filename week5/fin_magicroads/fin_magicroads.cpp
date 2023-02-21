#include <iostream>
#include <vector>
#include <list>
using namespace std;

void bfs(int s);

const int MAX_N = 100000;

bool seen_c[MAX_N];
int layer1[MAX_N];
bool magic[MAX_N];
int ans = 1;

vector<pair<int,bool>> adj[MAX_N];
int deg[MAX_N];
int n, m, k, h;

int main()
{
    cin >> n >> m >> k >> h;
    for (int i = 0; i < n; i++)
    {
        deg[i] = 0;
        layer1[i] = -1;
    }
    for (int i = 0; i < k; i++)
    {
        int ma;
        cin >> ma;
        magic[ma-1] = 1;
    }
    for (int i = 0; i < m; i++)
    {
        int u, v;
        bool ma;
        pair<int,int> temp;
        cin >> u >> v >> ma;
        u--;
        v--;
        temp.first = v;
        temp.second = ma;
        adj[u].push_back(temp);
        temp.first = u;
        adj[v].push_back(temp);
        deg[u]++;
        deg[v]++;
    }
///////////////////////////////////////////////////////////////input_end
    bfs(0);
    cout << ans;
}

void bfs(int s)
{
    list<int> Q;
    bool is_magic;
    bool seen[MAX_N];
    int layer2[MAX_N];
    Q.push_back(s);
    seen[s] = true;
    seen_c[s] = 1;
    if(s == 0)
    {
        layer2[s] = 0;
        is_magic = 0;
    }
    else
    {
        layer2[s] = layer1[s];
        is_magic = 1;
    }

    while (!Q.empty())
    {
        int u = Q.front();
        //cout << '[' << u+1 << ',' << layer2[u] << ']' << '\n';
        Q.pop_front();
        bool is_die = 0;
        if(layer2[u] > h)
        {
            is_die = 1;
            if(!is_magic)
            {
                continue;
            }
        }
        for (int d = 0; d < deg[u]; d++)
        {
            int v = adj[u][d].first;
            if(magic[v])
            {
                //cout << "go_to";
                magic[v] = 0;
                seen_c[v] = 1;
                ans++;
                //cout << "plus";
                layer1[v] = layer2[u] + 1;
                bfs(v);
            }
            if(is_die)
            {
                if (!seen[v] && adj[u][d].second)
                {
                    Q.push_back(v);
                    seen[v] = true;
                    if(!seen_c[v])
                    {
                        //cout << "plus";
                        seen_c[v] = 1;
                        ans++;
                    }
                }
            }
            else
            {
                if (!seen[v] && (is_magic || !adj[u][d].second))
                {
                    Q.push_back(v);
                    seen[v] = true;
                    layer2[v] = layer2[u] + 1;
                    if(!seen_c[v] && layer2[v] <= h)
                    {
                        //cout << "plus" << '\n';
                        seen_c[v] = 1;
                        ans++;
                    }
                }
            }
        }
    }
}
