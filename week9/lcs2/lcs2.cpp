#include <bits/stdc++.h>
using namespace std;

string X;
string Y;
int A[201][201];
list<char> ans;
int main()
{
    cin >> X >> Y;
    int a,b;
    a = X.size();
    b = Y.size();
    for(int i = 1; i <= a; i++)
    {
        for(int j = 1; j <= b; j++)
        {
            int A1 = 0,A2,A3,A4;
            if(X[i-1] == Y[j-1])
            {
                A1 = A[i-1][j-1] + 1;
            }
            A2 = A[i-1][j];
            A3 = A[i][j-1];
            A2 = max(A2,A3);
            A[i][j] = max(A1,A2);
        }
    }
    // for(int i = 0; i <= a; i++)
    // {
    //     for(int j = 0; j <= b; j++)
    //     {
    //         cout << A[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    int i = a, j = b;
  
    //ans.push_front(X[i]);
    while(i >= 0 && j >= 0)
    {      
        if(A[i][j]-1 == A[i-1][j-1] && X[i-1] == Y[j-1])
        {
            ans.push_front(X[i-1]);
            i--;j--;
        }
        else
        {
            if(A[i-1][j] == A[i][j])
            {
                i--;
            }
            else if(A[i][j-1] == A[i][j])
            {
                j--;
            }
        }
    }
    
    cout << A[a][b];
    cout << '\n';
    for(auto i: ans){
        cout << i;
    }
}