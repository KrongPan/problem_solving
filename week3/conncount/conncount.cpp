#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main()
{
    vector<int> graph[100000];
    bool visited[100000];
    list<int> in;
    vector<int>::iterator it;
    int N, M, A, B, position;
    int count = 0;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> A >> B;
        graph[A - 1].push_back(B - 1);
        graph[B - 1].push_back(A - 1);
    }
    for (int i = 0; i < N; i++)
    {
        if (visited[i] == false)
        {
            visited[i] = true;
            count++;
            in.push_back(i);
            while (true)
            {
                position = *in.begin();
                visited[position] = true;
                in.erase(in.begin());
                for (it = graph[position].begin(); it != graph[position].end(); it++)
                {
                    if (visited[*it] == false)
                    {
                        in.push_back(*it);
                        visited[*it] = true;
                    }
                }
                if (in.size() == 0)
                {
                    break;
                }
            }
        }
    }
    cout << count;
}