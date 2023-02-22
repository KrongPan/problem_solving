#include <bits/stdc++.h>
using namespace std;

int n;
void Merge_sort(int l, int r);
void merge(int l, int m, int r);
long long int ans = 0;

vector<int> data_t;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        data_t.push_back(s);
    }
    Merge_sort(0, n - 1);
    cout << ans;
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
            ans += n1-i;
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