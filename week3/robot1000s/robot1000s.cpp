#include <bits/stdc++.h>
using namespace std;


int main()
{
  int x, y, err;
  x = 0;
  y = 0;
  int N, E, W, S;
  N = 0;
  E = 0;
  W = 0;
  S = 0;
  string direction;
  cin >> direction;
  for (unsigned int i = 0; i < direction.size(); i++)
  {
    // cout << i << "|";
    switch (direction[i])
    {
    case 'N':
      y++;
      N++;
      break;
    case 'S':
      y--;
      S++;
      break;
    case 'E':
      x++;
      E++;
      break;
    case 'W':
      x--;
      W++;
      break;
    default:
      break;
    }
  }
  cin >> err;
  //cout << x << ',' << y << '\n';
  vector<pair<int,char>> dir;
  dir.push_back({N,'N'});
  dir.push_back({S,'S'});
  dir.push_back({W,'W'});
  dir.push_back({E,'E'});
  sort(dir.begin(),dir.end());
  while(err!= 0 && dir[0].first != 0)
  {
    err--;
    dir[0].first--;
  } 
  while(err!= 0 && dir[1].first != 0)
  {
    err--;
    dir[1].first--;
  } 
  while(err!= 0 && dir[2].first != 0)
  {
    err--;
    dir[2].first--;
  } 
  while(err!= 0 && dir[3].first != 0)
  {
    err--;
    dir[3].first--;
  } 
  cout << (dir[3].first+dir[2].first-dir[0].first-dir[1].first)*2;
  return 0;
}