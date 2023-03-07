#include <iostream>
using namespace std;

char c[27] = {'\n', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int n;
int c1_sup;
int c3_sup;
int c2_sup;
int c4_sup;
int c1_M;
int c2_M;

int main()
{
    cin >> n;
    string ans;
    int count;
    for (int i = 0; i < n; i++)
    {
        count = 0;
        cin >> ans;
        c1_M = 1;
        c2_M = 1;

        for (auto a : ans)
        {
            c1_sup = c1_M;
            c3_sup = c2_M;
            c2_sup = c1_M;
            c4_sup = c2_M;
            while (true)
            {
                if (c[c1_sup] == a)
                {
                    c1_M = c1_sup;
                    break;
                }
                else if (c[c2_sup] == a)
                {
                    c1_M = c2_sup;
                    break;
                }
                else if (c[c3_sup] == a)
                {
                    c2_M = c3_sup;
                    break;
                }
                else if (c[c4_sup] == a)
                {
                    c2_M = c4_sup;
                    break;
                }
                count++;
                c1_sup += 1;
                c2_sup -= 1;
                c3_sup += 1;
                c4_sup -= 1;
                if (c1_sup > 26)
                {
                    c1_sup = 1;
                }

                if (c3_sup > 26)
                {
                    c3_sup = 1;
                }

                if (c2_sup < 1)
                {
                    c2_sup = 26;
                }

                if (c4_sup < 1)
                {
                    c4_sup = 26;
                }

                cout << '[' << c1_sup << ',' << c2_sup << ',' << c3_sup << ',' << c4_sup << ']' << '\n';
            }
            cout << count << ',' << a << ']' << '\n';
        }
        cout << count << '\n';
    }
}