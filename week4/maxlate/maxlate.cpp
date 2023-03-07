#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int,int>> task;
int main()
{
    cin >> n;
    int a, b;
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b;
        pair<int,int> temp;
        temp.first = a;
        temp.second = b;
        task.push_back(temp);
    }
    sort(task.begin(), task.end());
    int x = 0;
    int max = 0;
    for(auto i:task)
    {
        int pay;
        x += i.second;
        pay = (x-i.first-10)*1000;
        if(pay > max)
        {
            max = pay;
        }
    }
    cout << max;
    return 0;
}