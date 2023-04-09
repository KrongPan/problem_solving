#include <bits/stdc++.h>
//#include <Windows.h>
using namespace std;

int n,m;
int tree[1001];
bool check_p(int a, int b);
int main()
{
    cin >> n >> m;
    for(int i = 2; i <= n; i++)
    {
        cin >> tree[i];
    }
    int a, b;
    for(auto i: tree)
    {
        //cout << '[' << i << ']';
    }
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        if(check_p(a,b))
        {
            cout << b;
        }
        else if(check_p(b,a))
        {
            cout << a;
        }
        else
        {
            cout << -1;
        }
        cout << '\n';
    }
    return 0;
}

bool check_p(int a, int b)
{
    while(a != 0)
    {
        //cout << a;
        //Sleep(200);
        if(tree[a] == b)
        {
            return true;
        }
        a = tree[a];
    }
    return false;
}