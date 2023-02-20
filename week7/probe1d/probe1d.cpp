#include "probelib.h"
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;

int n;

main()
{
    int n = probe_init();
    int s = 0;
    for (int i = 0; i<22; i++)
    {
        if (probe_check(s, s + ((n-s)/2)))
        {
            //cout << 'L' << '\n';
            n = n - (n-s)/2;
            if(n == 1 && s == 0)
            {
                if(probe_check(n-1,n-1))
                {
                    probe_answer(n-1);
                }
                if(probe_check(n,n))
                {
                    probe_answer(n);
                }
                n--;
                break;
            }
        }
        else
        {
            //cout << 'R' << '\n';
            s = s + (n-s)/2;
        }
        //cout << s << ' ' << n << '\n';
    }
    probe_answer(n);
}