#include <bits/stdc++.h>
using namespace std;

string rna;
int A[201][201];
int main()
{
    cin >> rna;
    int ans = 0;
    int l = rna.size();
    int count = 0;
    for (int a = rna.size(); a > 0; a--)
    {
        for (int b = 1; b <= a; b++)
        {
            int i = b;
            int j = i+count;
            if(j <= i+4)
            {
                A[i][j] = 0;
            }
            else 
            {
                int max = 0;
                if((rna[i-1] == 'A' && rna[j-1] == 'U') || (rna[i-1] == 'U' && rna[j-1] == 'A') || (rna[i-1] == 'C' && rna[j-1] == 'G') || (rna[i-1] == 'G' && rna[j-1] == 'C'))
                {
                    for(int k = i; k < j; k++)
                    {
                        if(A[i][k-1]+A[k+1][j-1]+1 > max && k < j-4 && ((rna[k-1] == 'A' && rna[j-1] == 'U') || (rna[k-1] == 'U' && rna[j-1] == 'A') || (rna[k-1] == 'C' && rna[j-1] == 'G') || (rna[k-1] == 'G' && rna[j-1] == 'C')))
                        {
                            max = A[i][k-1]+A[k+1][j-1]+1;
                        }
                    }
                    
                }
                else
                {
                    max = A[i][j-1];
                }
                if(max > ans)
                {
                    ans = max;
                }
                if(max > A[i][j])
                {
                    A[i][j] = max;
                }
            }
        }
        count++;
    }
    cout << A[1][l] << '\n';
    for(int i = 1; i <= l; i++)
    {
        for(int j = 1; j <= l; j++)
        {
            cout << A[i][j] << ' ';
        }
        cout << '\n';
    }
}