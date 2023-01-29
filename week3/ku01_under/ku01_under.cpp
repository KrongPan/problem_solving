#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

int main()
{
    int N, L, A, B;
    array<int, 300> road;
    for (int i = 0; i < 300; i++)
    {
        road[i] = 0;
    }
    cin >> L >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A >> B;
        for (int j = A - 1; j < B - 1; j++)
        {
            road[j]++;
        }
    }
    sort(road.begin(), road.end(), greater<int>());
    cout << road[0];
    return 0;
}