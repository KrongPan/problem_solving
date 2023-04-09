#include <bits/stdc++.h>
using namespace std;

vector<int> t;
vector<int> m;
int n,q;
int main()
{
    cin >> n >> q;
    for(int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        t.push_back(c);
    }
    for(int i = 0; i < q; i++)
    {
        int a,b;
        cin >> a >> b;
        if(a == 1)
        {
            int min = 10000000;
            for(int i = 0; i < b; i++)
            {
                if(t[i] < min)
                {
                    min = t[i];
                }
            }
            cout << min;
        }
        else if(a == 2)
        {
            for(int i = 0; i < n; i++)
            {
                if(t[i] < b)
                {
                    cout << i;
                    break;
                }
                if(i == n-1)
                {
                    cout << n;
                }
            }
            
        }
        cout << '\n';
    }
    return 0;
}