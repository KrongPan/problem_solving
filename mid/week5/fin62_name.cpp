#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name;
    char c;
    int i = 0;
    int count = 0;
    getline(cin, name);
    int l = size(name);
    c = getchar();
    while (c != '\n')
    {
        if (c == name[i])
        {
            i++;
            if (i == l - 1)
            {
                i = 0;
                count++;
            }
        }
        c = getchar();
    }
    cout << count;
    return 0;
}