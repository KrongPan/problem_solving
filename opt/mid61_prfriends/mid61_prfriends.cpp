#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n)
{
    bool p = true;
    if (n == 0 || n == 1)
    {
        p = false;
    }
    for (int i = 2; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
        {
            p = false;
            break;
        }
    }
    if (p)
        return true;
    else
        return false;
}
int c = 0;
int main()
{
    int a,b;
    int x1, x2;
    x1 = -999;
    cin >> a >> b;
    for(int i = a; i <= b; i++)
    {
        if(is_prime(i))
        {
            x2 = i;
            if(x2 - x1 == 2)
            {
                c++;
            }
            x1 = x2;
        }
    }
    cout << c;
    return 0;
}