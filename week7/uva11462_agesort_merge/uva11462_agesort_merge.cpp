#include <bits/stdc++.h>
using namespace std;


int n;
vector<int> Merge_sort(vector<int> data, int n);
vector<int> merge(vector<int> A, vector<int> B, int na, int nb);
vector<int> ans;

int main()
{
    
    vector<int> data_t;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while (true)
    {

        cin >> n;
        if(n == 0)
        {
            break;
        }
        int s;
        data_t.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            data_t.push_back(s);
        }
        ans = Merge_sort(data_t, n);
        for(int i = 0; i < n-1; i++)
        {
            cout << ans[i] << ' ';
        }
        cout << ans[n-1] << ' ' << '\n';
    }

    return 0;
}

vector<int> merge(vector<int> A, vector<int> B, int na, int nb)
{
    vector<int> C;
    while (na != 0 && nb != 0)
    {
        if (A[0] > B[0])
        {
            C.push_back(B[0]);
            B.erase(B.begin());
            nb--;
        }
        else
        {
            C.push_back(A[0]);
            A.erase(A.begin());
            na--;
        }
    }
    while (na != 0)
    {
        C.push_back(A[0]);
        A.erase(A.begin());
        na--;
    }
    while (nb != 0)
    {
        C.push_back(B[0]);
        B.erase(B.begin());
        nb--;
    }
    return C;
}

vector<int> Merge_sort(vector<int> data,int n)
{
    if (n <= 1)
    {
        return data;
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
    vector<int> data_a(&data[0],&data[na]);
    vector<int> data_b(&data[na],&data[n]);
    data_a = Merge_sort(data_a, na);
    data_b = Merge_sort(data_b, nb);
    return merge(data_a, data_b, na, nb);
}