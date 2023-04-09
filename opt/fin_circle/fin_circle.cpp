#include <bits/stdc++.h>
using namespace std;

int n, h;
vector<int> s;
int c;
int max_s;
int main()
{
    int max_s = 0;
    cin >> n >> h;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        s.push_back(temp);
    }
    int H;
    int j;
    int c;
    for (int i = 0; i < n; i++)
    {
        H = h;
        j = i;
        c = 0;
        while (H > 0)
        {
            H -= s[j];
            if(H < 0)
            {
                break;
            }
            j++;
            c++;
            if (j >= n)
            {
                j = 0;
            }
            if (j == i)
            {
                break;
            }
        }
        if (c > max_s)
        {
            max_s = c;
        }
        H = h;
        j = i;
        c = 0;
        while (H > 0)
        {
            H -= s[j];
            if(H < 0)
            {
                break;
            }
            j--;
            c++;
            if (j < 0)
            {
                j = n - 1;
            }
            if (j == i)
            {
                break;
            }
        }
        if (c > max_s)
        {
            max_s = c;
        }
    }
    cout << max_s;
    return 0;
}