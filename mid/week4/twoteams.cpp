#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n, m, a, b;
    bool end = false;
    int count = 0;
    cin >> n >> m;
    set<int> teamA;
    set<int> teamB;
    for (int i = 0; i < m; i++)
    {
        /*
        cout << 'A';
        for (auto it = teamA.begin(); it != teamA.end(); ++it)
        {
            std::cout << *it << std::endl;
        }
        cout << 'B';
        for (auto it = teamB.begin(); it != teamB.end(); ++it)
        {
            std::cout << *it << std::endl;
        }
        cout << end << '|' << '\n';
        */
        cin >> a >> b;
        if (end == true)
        {
            continue;
        }
        if (count == 0)
        {
            teamA.insert(a);
            teamB.insert(b);
            count++;
            continue;
        }
        
        if (teamA.find(a) != teamA.end())
        {
            teamB.insert(b);
        }
        else if (teamA.find(b) != teamA.end())
        {
            teamB.insert(a);
        }
        else if (teamB.find(a) != teamB.end())
        {
            teamA.insert(b);
        }
        else if (teamB.find(b) != teamB.end())
        {
            teamA.insert(a);
        }
        else
        {
            teamA.insert(a);
            teamB.insert(b);
        }
        if ((teamA.find(a) != teamA.end() && teamA.find(b) != teamA.end()) || (teamB.find(a) != teamB.end() && teamB.find(b) != teamB.end()))
        {
            end = true;
            continue;
        }
        count++;
    }
    cout << count;
}