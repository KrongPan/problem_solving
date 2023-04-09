#include <bits/stdc++.h>
using namespace std;

int n,total;
int a,b,ans;
vector<int> p;
int main()
{
    cin >> n;
    total = 0;
    for(int i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        total += s;
        p.push_back(s);
    }
    a = 0;b = 0;
    sort(p.begin(),p.end(),greater<int>());
    for(int i = 0; i < p.size(); i++)
    {
        if(a > b)
        {
            b+=p[i];
        }
        else if(b > a)
        {
            a+=p[i];
        }
        else if(a == b)
        {
            ans = a;
            a+=p[i];
        }
    }
    if(a == b)
    {
        ans = a;
    }
    cout << ans;
}