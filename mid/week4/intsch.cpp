#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, s, e;
    vector<int> t[1000];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> e;
        t[e - 1].push_back(s - 1);
    }

    int count = 0;
    int start = 0;
    for (int i = 0; i < 1000; i++)
    {
        if (!t[i].empty() && i >= start)
        {
            // cout << '[' << i+1 << ']';
            bool can = false;
            for (int j = 0; j < t[i].size(); j++)
            {
                // cout  << t[i][j]+1 << ',';
                if (t[i][j] >= start)
                {

                    can = true;
                }
            }
            if (can == true)
            {
                start = i;
                // cout <<start+1;
                count++;
            }
        }
    }
    cout << count;
}