#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int k, n, data, min, total, w;
    min = 2000000000;
    vector<vector<int>> rent;
    vector<int> carry;
    cin >> k >> n;
    for (int i = 0; i < k; i++)
    {
        vector<int> temp;
        for (int j = 0; j < 3; j++)
        {
            cin >> data;
            temp.push_back(data);
        }
        rent.push_back(temp);
    }
    /*
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << rent[i][j] << ' ';
            }
        cout << '\n';
        }
    */
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        carry.push_back(data);
    }

    for (int i = 0; i < k; i++)
    {
        total = rent[i][0] + rent[i][1];
        w = 0;
        for (int j = 0; j < n; j++)
        {
            if (rent[i][2] < carry[j])
            {
                total = 2000000000;
                break;
            }
            w += carry[j];
            // cout << w << ' ';
            if (w > rent[i][2])
            {
                w = carry[j];
                total += rent[i][1];
            }
        }
        // cout << '\n';
        // cout << total << '\n';
        if (total < min)
        {
            min = total;
        }
    }
    cout << min;
}