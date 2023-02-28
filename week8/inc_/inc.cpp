#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> point;
vector<int> A;
vector<int> order_ans;
int ans = 0;
int main()
{
    cin >> n;
    int b;
    for (int i = 0; i < n; i++)
    {
        cin >> b;
        int temp = 1;
        A.push_back(temp);
        point.push_back(b);
    }
    int max_p = 0;
    for (int i = 1; i < n; i++)
    {
        int max = 0;

        for (int j = 0; j <= i - 1; j++)
        {
            if (A[j] > max && point[i] > point[j])
            {
                max_p = j;
                max = A[j];
            }
        }
        A[i] = max + 1;
        if (A[i] > A[ans])
        {
            ans = i;
            // cout << '[' << point[ans] << ']';
        }
    }
    cout << A[ans] << '\n';
    int c = A[ans];
    int p = point[ans];
    int n = c - 1;
    for (int i = 0; i < c; i++)
    {
        int temp = 0;
        order_ans.push_back(temp);
    }
    order_ans[n] = p;
    for (int i = ans - 1; i >= 0; i--)
    {
        if (A[i] == c - 1 && point[i] < p)
        {
            n--;
            p = point[i];
            order_ans[n] = p;
            c--;
        }
    }
    for (auto i : order_ans)
    {
        cout << i << ' ';
    }
    return 0;
}