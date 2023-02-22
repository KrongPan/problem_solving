#include <bits/stdc++.h>
using namespace std;

int kruskal();
int find_parent(int v);
void union_compress(int A, int B);
int check;
int parent[200];
int Rank[200];
vector<pair<int, pair<int, int>>> graph;
int f, n;

int main()
{
    int a, b, w;
    cin >> f >> n;
    for (int i = 0; i < n; i++)
    {
        pair<int, pair<int, int>> temp;
        graph.push_back(temp);
    }
    for (int i = 0; i < n; i++)
    {
        for (int i = 0; i < f; i++)
        {
            bool temp = 0;
            parent[i] = i;
            Rank[i] = 1;
        }
        cin >> a >> b >> w;
        pair<int, pair<int, int>> temp;
        temp.second.first = a - 1;
        temp.second.second = b - 1;
        temp.first = w;
        graph.push_back(temp);
        sort(graph.begin(), graph.end());
        check = 0;
        cout << kruskal() << '\n';
    }

    return 0;
}

int find_parent(int v)
{
    if (parent[v] == v)
    {
        return v;
    }
    parent[v] = find_parent(parent[v]);
    return parent[v];
}

void union_compress(int A, int B)
{
    int temp;
    if (Rank[A] > Rank[B])
    {
        temp = A;
        A = B;
        B = temp;
    }
    parent[A] = B;
    Rank[A] += Rank[B];
}
int kruskal()
{
    int count = 0;
    int c = 1;
    for (int i = 0; i < graph.size(); i++)
    {
        if (c == n)
        {
            break;
        }
        int A = find_parent(graph[i].second.first), B = find_parent(graph[i].second.second), W = graph[i].first;
        if (A != B)
        {
            union_compress(A, B);
            count += W;
            c++;
            check++;
        }
        else
        {
            vector<pair<int, pair<int, int>>>::iterator it;
            it = graph.begin() + i;
            graph.erase(it);
            i--;
        }
    }
    //cout << '[' << check << ']';
    if(check < f-1)
    {
        count = -1;
    }
    return count;
}