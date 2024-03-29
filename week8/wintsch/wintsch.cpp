#include <bits/stdc++.h>
using namespace std;

int n;
set<pair<int,pair<int,int>>> s_time;
int A[1000];
vector<int> order_ans;
int ans = 0;
int main()
{
    cin >> n;
    int a,b,w;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> w;
        pair<int,pair<int,int>> temp;
        a--;
        b--;
        temp.first = a;
        temp.second.first = b;
        temp.second.second = w;
        s_time.insert(temp);
    }
    // for(auto i: s_time)
    // {
    //     cout << i.first+1 << ',' << i.second.first+1 << ',' << i.second.second << '\n';
    // }
    set<pair<int,pair<int,int>>>::iterator it = s_time.begin();
  
    A[0] = it->second.second;
    for (int i = 0; i < n; i++)
    {
        int max = 0;
        set<pair<int,pair<int,int>>>::iterator it2 = s_time.begin();
        advance(it2,i);
        for (int j = i-1; j > -1; j--)
        {
            set<pair<int,pair<int,int>>>::iterator it1 = s_time.begin();
            advance(it1,j);
            if (A[j] > max && it2->first >= it1->second.first)
            {
                max = A[j];
                continue;
            }
        }
        // cout << '[' << max << ']';
        it = s_time.begin();
        advance(it,i);
        A[i] = max + it->second.second;
        if (A[i] > A[ans])
        {
            ans = i;
        }
    }
    
    // for(auto i: A)
    // {
    //     cout << i << ' ' << '\n';
    // }
    cout << A[ans] << '\n';
    int p = ans;
    it = s_time.begin();
    advance(it, ans);
    order_ans.push_back(it->first + 1);
    for (int i = p - 1; i >= 0; i--)
    {
        set<pair<int,pair<int,int>>>::iterator it1 = s_time.begin();
        advance(it1,p);
        set<pair<int,pair<int,int>>>::iterator it2 = s_time.begin();
        advance(it2,i);
        if (A[i] == A[p]-it1->second.second && it2->second.first <= it1->second.first)
        {
            p = i;
            order_ans.push_back(it2->first + 1);
            continue;
        }
    }
    sort(order_ans.begin(),order_ans.end());
    cout << order_ans.size() << '\n';
    for (auto i : order_ans)
    {
        cout << i << ' ';
    }
    return 0;
}