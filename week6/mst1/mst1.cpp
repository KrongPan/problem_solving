#include <bits/stdc++.h>
using namespace std;

int kruskal();
void union_compress(int A, int B);
int find_parent(int node);

int parent[1000];
int Rank[1000];
pair<int, pair<int, int>> graph[100000];
int n, m;
int main()
{
    int a, b, w;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        Rank[i] = 1;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> w;
        graph[i].second.first = a - 1;
        graph[i].second.second = b - 1;
        graph[i].first = w;
    }
    sort(graph, graph + m);
    /*
        for(int i = 0; i < 1000; i++)
        {
            cout << parent[i] << '\n';
        }
    */
    //////////////////////////////////////////////////////////////kruskal
    cout << kruskal();
    /*
        for (int i = 0; i < n; i++)
        {
            cout << parent[i] << '\n';
        }
    */
}

int kruskal()
{
    int count = 0;
    int c = 1;
    for (auto i : graph)
    {
        int A = i.second.first, B = i.second.second, W = i.first;
        if (find_parent(A) != find_parent(B))
        {
            union_compress(A, B);
            count += W;
        }
    }
    return count;
}
int find_parent(int v)
{
    while (parent[v] != v)
    {
        v = parent[v];
    }
    return v;
}

void union_compress(int A, int B)
{
    int temp;
    A = find_parent(A);
    B = find_parent(B);
    if (Rank[A] > Rank[B])
    {
        temp = A;
        A = B;
        B = temp;
    }
    parent[A] = B;
    Rank[A] += Rank[B];
}