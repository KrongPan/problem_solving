#include <bits/stdc++.h>
// #include <Windows.h>
using namespace std;

int n, a, b, r;
float d;
int ans;
int main()
{
    cin >> n >> a >> b >> r;
    int x, y;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        d = sqrt(pow(abs(x - a), 2) + pow(abs(y - b), 2));
        if (d <= r)
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}