#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    pair<int,int> range;
    vector<vector<pair<int,int>>> ans;
    cin >> n;
    for(int i = 0; i<n ; i++)
    {
        vector<pair<int,int>> temp;
        ans.push_back(temp);
    }
    for(int i = 0; i<n ; i++)
    {
        vector<pair<int,int>> data;
        bool is_con = 0;
        int M;
        cin >> M;
        int L,R;
        cin >> L >> R;
        while (!(L == 0 && R == 0))
        {
            range.first = L;
            range.second = R;
            data.push_back(range);
            cin >> L >> R;
        }
        sort(data.begin(), data.end());;
        int curL = 0, rReach = 0;
        int count = 0;
        while (rReach < M)
        {
            count++;
            if(count > data.size())
            {
                ans[i].clear();
                break;
            }
            if(count > data.size())
            {
                break;
            }
            int newL = curL;
            int farthest = 0;    
            for (int j = 0 ; j < data.size(); ++j)
            {
                if (data[j].first > curL)
                    break;
                else if (data[j].second >= newL)
                {
                    newL = data[j].second;
                    farthest = j;
                }
            }
            if (farthest == 0)
            {
                break;
            }
            ans[i].push_back(data[farthest]);
            curL = rReach = newL;
        }
    }
    for(auto i: ans)
    {
        cout << i.size() << '\n';
            for (int j = 0; j < i.size(); ++j)
            {
                cout << i[j].first << " " << i[j].second << '\n';
            }
        cout << '\n';
    }
    return 0;
}