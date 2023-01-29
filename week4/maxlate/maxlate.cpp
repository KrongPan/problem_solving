#include <bits/stdc++.h>
using namespace std;

int maxt = 10000;
int main()
{
    int n, d, c;
    int tp = 0;
    int max = 0;
    cin >> n;
    int  p[maxt+1];
    for (int i = 0; i < maxt + 1; i++)
    {
        p[i] = 0;
    }
    int td = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> d >> c;
        p[d] = c;
    }
    for (int i = 1; i < maxt + 1; i++)
    {
        td += p[i];
        int total = 0;
        if (td - i - 10 > 0)
        {
            // cout << '[' << i << ']';
            total = (td - i - 10) * 1000;
            // cout << total << '\n';
            if (total > max)
            {
                max = total;
            }
        }
    }
    cout << max;
    return 0;
}