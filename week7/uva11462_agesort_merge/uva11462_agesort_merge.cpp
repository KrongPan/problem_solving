#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> Merge_sort(vector<int> data, int n);
vector<int> merge(vector<int> A, vector<int> B);
vector<vector<int>> ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> data_t;
    cin >> n;
    while (n)
    {
        int s;
        data_t.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            data_t.push_back(s);
        }
        ans.push_back(Merge_sort(data_t, n));
        cin >> n;
    }
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j];
            if (j != ans[i].size() - 1)
            {
                cout << ' ';
            }
        }
        if (i != ans.size() - 1)
        {
            cout << '\n';
        }
    }
}

vector<int> merge(vector<int> A, vector<int> B)
{
    vector<int> C;
    while (A.size() != 0 && B.size() != 0)
    {
        if (A[0] > B[0])
        {
            C.push_back(B[0]);
            B.erase(B.begin());
        }
        else
        {
            C.push_back(A[0]);
            A.erase(A.begin());
        }
    }
    while (A.size() != 0)
    {
        C.push_back(A[0]);
        A.erase(A.begin());
    }
    while (B.size() != 0)
    {
        C.push_back(B[0]);
        B.erase(B.begin());
    }
    return C;
}

vector<int> Merge_sort(vector<int> data,int n)
{
    if (n == 1)
    {
        return data;
    }
    vector<int> data_a;
    vector<int> data_b;
    for (int i = 0; i < n; i++)
    {
        if(i < n/2)
        {
            data_a.push_back(data[i]);
        }
        else
        {
            data_b.push_back(data[i]);
        }
    }
    int na,nb;
    if(n%2 == 0)
    {
        na = n/2;
        nb = na;
    }
    else
    {
        na = n/2;
        nb = na + 1;
    }
    data_a = Merge_sort(data_a, na);
    data_b = Merge_sort(data_b, nb);
    return merge(data_a, data_b);
}