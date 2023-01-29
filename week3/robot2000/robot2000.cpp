#include <iostream>
using namespace std;

int printR(int dir, int ro)
{
    while (dir != ro)
    {
        cout << 'R';
        dir++;
        if (dir == 4)
        {
            dir %= 4;
        }
    }
    return dir;
}

int main()
{
    char order;
    int x, y, dir = 0;
    while (true)
    {
        order = getchar();
        if (order == '\n')
        {
            break;
        }
        if (order == 'N')
        {
            dir = printR(dir, 0);
            cout << 'F';
        }
        else if (order == 'E')
        {
            dir = printR(dir, 1);
            cout << 'F';
        }
        else if (order == 'S')
        {
            dir = printR(dir, 2);
            cout << 'F';
        }
        else if (order == 'W')
        {
            dir = printR(dir, 3);
            cout << 'F';
        }
        else
        {
            cout << 'Z';
            dir = 0;
        }
    }
    return 0;
}