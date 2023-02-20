#include <bits/stdc++.h>
using namespace std;

void union_compress(int A, int B);
int find_parent(int node);

int parent[100000];
int Rank[100000];
queue<string> ans;
int n, m;

int main()
{
    int b, a;
    char w;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        Rank[i] = 1;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> w >> a >> b;
        a--; b--;
        a = find_parent(a);
        b = find_parent(b);
        if(w == 'q')
        {
            if(a == b)
            {
                ans.push("yes");
            }
            else
            {
                ans.push("no");
            }
        }
        else if (w == 'c')
        {
            union_compress(a, b);
        }
    }
    while(ans.size() != 0)
    {
        cout << ans.front() << '\n';
        ans.pop();
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