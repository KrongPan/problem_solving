#include <bits/stdc++.h>
using namespace std;

int n;
void Merge_sort(int l, int r);
void merge(int l, int m, int r);
vector<int> ans;

vector<int> data_t;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while (true)
    {
        cin >> n;
        if (n == 0)
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
        Merge_sort(0, n-1);
        for (int i = 0; i < n - 1; i++)
        {
            cout << data_t[i] << ' ';
        }
        cout << data_t[n - 1] << '\n';
    }
    return 0;
}
void merge(int l, int m, int r)
{
    const int n1 = m - l + 1;
    const int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
    {
        L[i] = data_t[l + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = data_t[m + 1 + j];
    }
    int i, j, k;
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            data_t[k] = L[i];
            i++;
        }
        else
        {
            data_t[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        data_t[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        data_t[k] = R[j];
        j++;
        k++;
    }
}
void Merge_sort(int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        Merge_sort(l, m);
        Merge_sort(m + 1, r);
        merge(l, m, r);
    }
}