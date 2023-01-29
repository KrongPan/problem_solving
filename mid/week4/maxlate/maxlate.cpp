#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, d, c;
    int total = 0;
    int max = 0;
    cin >> n;
    array<int,100000> p = {0};
    int td = 0;
    for (int i = 1; i < n + 1; i++)
    {
        cin >> d >> c;
        p[d] = c;
    }
    for (int i = 1; i < 100000 + 1; i++)
    {
        td += p[i];
        if (p[i] != 0 && td - i - 10 > 0)
        {
            // cout << '[' << i << ']';
            if (total < (td - i - 10) * 1000)
            {
                total = (td - i - 10) * 1000;
                //cout << total << '\n';
                if (total > max)
                {
                    max = total;
                }
            }
        }
    }
    cout << max;
}