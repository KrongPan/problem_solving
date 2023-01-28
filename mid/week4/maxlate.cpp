#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, d, c;
    int total = 0;
    cin >> n;
    int p[10000];
    int td = 0;
    for (int i = 1; i < n + 1; i++)
    {
        cin >> d >> c;
        p[d] = c;
    }
    for (int i = 1; i < 10000 + 1; i++)
    {
        td += p[i];
        if (p[i] != 0 && td - i - 10 > 0)
        {
            // cout << '[' << i << ']';
            if (total < (td - i - 10) * 1000)
            {
                total = (td - i - 10) * 1000;
            }
        }
    }
    cout << total;
}