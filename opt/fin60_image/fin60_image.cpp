#include <bits/stdc++.h>
using namespace std;

int l,h,r;
int t[101][101];
int ans[101][101];
bool is_half;
int main()
{
    cin >> h >> l >> r;
    for(int i = 1; i <= l; i++)
    {
        for(int j = 1; j <= h; j++)
        {
            cin >> t[i][j];
        }
    }
    for(int i = 1; i <= l; i++)
    {
        for(int j = 1; j <= h; j++)
        {
            int c = 0;
            int total = 0;
            is_half = 0;
            int count = 0;
            for(int a = i-r; a <= i+r; a++)
            {
                if(a >= 1 && a <= l)
                {
                    total += t[a][j];
                    count++;
                    for(int n = 1; n <= c; n++)
                    {
                        if(j+n <= h)
                        {
                            total += t[a][j+n];
                            count++;
                        }
                        if(j-n >= 1)
                        {
                            total += t[a][j-n];
                            count++;
                        }                          
                    }
                    
                }
                if(is_half)
                {
                    c--;
                }
                else
                {
                    c++;
                    if(c >= r)
                    {
                        is_half = 1;
                    }
                }
                //cout << '[' << total << ',' << count << ']'; 
            }
            
            ans[i][j] = total/count;
        }
        //cout << '\n';
    }
    for(int i = 1; i <= l; i++)
    {
        for(int j = 1; j <= h; j++)
        {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}