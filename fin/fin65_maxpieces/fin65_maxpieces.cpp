#include <bits/stdc++.h>
using namespace std;
int n,q;
vector<int> p;
int total[100000];
int main()
{
    cin >> n >> q;
    int c;
    for(int i = 0; i < n; i++)
    {
        cin >> c;
        p.push_back(c);
    }
    sort(p.begin(),p.end());
    for(int i = 0; i < n; i++)
    {
        if(i == 0)
        {
            total[i] = p[i];
        }
        else
        {
            total[i] = p[i]+total[i-1];
        }
    }
    int x, y;
    for(int i = 0; i < q; i++)
    {
        cin >> x >> y;
        int count = 0;
        int k = 0;
        while(y > p[k])
        {
            k++;
            x+=p[k];
            count--;
        }
        int j = k;
        while(x>=total[j])
        {
            j++;
            count++;
        }
        cout << count << '\n';
    }
    return 0;
}