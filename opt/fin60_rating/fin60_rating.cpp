#include <bits/stdc++.h>
using namespace std;

int n,m,ans_c,ans_r;
int c[100001];
vector<int> s;

int main()
{
    cin >> n >> m;
    int r;
    for(int i = 0; i < n; i++)
    {
        cin >> r;
        s[r] = 0;
        c[r]++;
        if(q.front() == r)
        {
            q.pop_front();
            s[r] = 0;
        }
        for(auto j: q)
        {
            s[j]++;
        }
        if(q.front() > 5)
        {
            s[q.front()] = 0;
            c[q.front()] = 0;
            q.pop_front();
        }
        if(c[r] > ans_c)
        {
            ans_c = c[r];
            ans_r = r;
        }
        else if(c[r] == ans_c)
        {
            if(ans_r > r)
            {
                ans_r = r;
            }
        }
    }
    cout << ans_r  << ' ' << ans_c;
    return 0;
}