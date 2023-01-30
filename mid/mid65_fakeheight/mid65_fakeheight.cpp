#include <bits/stdc++.h>
using namespace std;

vector<long long int> h;
long long int X, max_n, min_n;
int n, total, max_p, min_p;
int main()
{
    cin >> n;
    min_p = 100001;
    max_p = 100001;
    max_n = 0;
    min_n = LONG_LONG_MAX;
    for (int i = 0; i < n; i++)
    {
        cin >> X;
        h.push_back(X);
    }
    
    for (int i = 1; i < n - 1; i++)
    {
        int c = abs(h[i]-h[i-1]+h[i]-h[i+1]);
        if(c > max_n)
        {
            max_n = c;
            max_p = i;
        }
    }
    long long int a = (h[max_p-1]+h[max_p+1])/2;
    cout << a << '\n';
    //cout << max_n;
    long long int i = 0;
    bool b = 0;
    for(auto c:h)
    {
        if(b)
        {
            a+=i;
        }
        else
        {
            a-=i;
        }
        i++;
        b = !b;
        if (c == a)
        {
            h[max_p] = c;
        }
    }


    total = 0;
    for (int i = 0; i < n - 1; i++)
    {
        total += abs(h[i]-h[i+1]);
    }
    cout << total;
}
