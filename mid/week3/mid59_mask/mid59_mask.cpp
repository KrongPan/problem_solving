#include <iostream>
using namespace std;
#include <list>

int main()
{
    int n, in, count, max, temp, maxpo;
    max = 0;
    int ab[4];
    int position[4];
    cin >> n;
    list<int> p;
    count = 1;
    for (int i = 0; i < 4 * n; i++)
    {
        cin >> in;
        if (in > max)
        {
            max = in;
            maxpo = i + 1;
        }
        if (count == n)
        {
            ab[((i + 1) / n) - 1] = max;
            position[((i + 1) / n) - 1] = maxpo;
            max = 0;
            count = 1;
        }
        else
        {
            count++;
        }
    }
    if (ab[0] < ab[1])
    {
        temp = position[1];
        position[1] = position[0];
        position[0] = temp;
        temp = ab[1];
        ab[1] = ab[0];
        ab[0] = temp;
    }
    if (ab[2] < ab[3])
    {
        temp = position[2];
        position[2] = position[3];
        position[3] = temp;
        temp = ab[2];
        ab[2] = ab[3];
        ab[3] = temp;
    }
    if (ab[0] < ab[2])
    {
        temp = position[2];
        position[2] = position[0];
        position[0] = temp;
        temp = ab[2];
        ab[2] = ab[0];
        ab[0] = temp;
    }
    cout << position[0] << ' ';
    cout << position[2] << ' ';
    cout << position[1] << ' ';
    cout << position[3];
}