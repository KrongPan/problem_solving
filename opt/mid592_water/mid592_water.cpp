#include <bits/stdc++.h>
using namespace std;

int n;
int ans = 0;
int yesterday = 0;
int main()
{
    cin >> n;
    int today;
    for(int i = 0; i < n; i++)
    {
        cin >> today;
        if(today < yesterday-10)
        {
            if(yesterday-today <= 70)
            {
                ans += (yesterday-today)*10;
            }
            else
            {
                ans += 700;
            }
        }
        yesterday = today;
    }
    cout << ans;
    return 0;
}
