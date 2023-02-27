#include <bits/stdc++.h>
using namespace std;

vector<int> point;
vector<int> A;
int ans = 0;
int banana(int p, int count);
int main()
{
    int n, b;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> b;
        int temp = 0;
        A.push_back(temp);
        point.push_back(b);
    }
    A[2] = point[2];
    A[1] = 0;
    A[0] = 0;
    int max_p = 0;
    for (int i = 2; i < n; i++)
    {
    
        int max = 0;
        
        for (int j = max_p; j <= i-3; j++)
        {
            if(A[j] >= max)
            {
                max_p = j;
                max = A[j];
            }
        }
        A[i] = max + point[i];
        if(A[i] > A[ans])
        {
            ans = i;
            //cout << '[' << A[ans] << ']';
        }
    }
    cout << A[ans];
}