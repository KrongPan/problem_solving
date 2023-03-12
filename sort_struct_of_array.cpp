int kruskal();
int find_parent(int v);
void union_compress(int A, int B);

struct separate_a
{
    int A;
    int B;
    int C;
    bool si;
};
bool compare(separate_a a, separate_a b) {
    return a.A < b.A;
}
struct separate_a sep [20000];
int parent[1001];
int Rank[1001];
int n,m;
int main()
{
    cin >> n >> m;
    for(int i = 1; i <=n ; i++)
    {
        parent[i] = i;
        Rank[i] = 1;
    }
    for(int i = 1; i <= m; i++)
    {
        cin >> sep[i].A >> sep[i].B >> sep[i].C >> sep[i].si;
    }
    sort(sep+1, sep + n, compare);
    cout << kruskal();
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
    for (int i = 1 ; i <= n ; i++)
    {

        if(c == n)
        {
            return count;
        }
        int a = find_parent(sep[i].A), b = find_parent(sep[i].B), W = sep[i].C;
        cout << '[' << a << ',' << b << ']';
        if (a != b)
        {
            union_compress(a, b);
            count += W;
            c++;
        }
    }
    return -1;
}
