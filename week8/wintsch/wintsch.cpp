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
        A[i] = 0;
        a--;
        b--;
        temp.first = a;
        temp.second.first = b;
        temp.second.second = w;
        s_time.insert(temp);
    }
    set<pair<int,pair<int,int>>>::iterator it = s_time.begin();
    A[0] = it->second.second;
    for (int i = 0; i < n; i++)
    {
        int max = 0;

        for (int j = 0; j < i; j++)
        {
            it = s_time.begin();
            advance(it,j);
            if (A[j] > max && i >= it->second.first)
            {
                max = A[j];
            }
        }
        //cout << '[' << max << ']';
        it = s_time.begin();
        advance(it,i);
        A[i] = max + it->second.second;
        if (A[i] > A[ans])
        {
            ans = i;
            
        }
    }
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
        if (A[i] == A[p]-it1->second.second && it2->second.first <= p)
        {
            p = i;
            order_ans.push_back(it2->first + 1);
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