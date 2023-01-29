#include <iostream>
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
  if (x > 0 && y > 0)
  {
    if (S + W < err)
    {
      err = -1 * (err - (S + W));
    }
  }
  else if (x < 0 && y < 0)
  {
    if (N + E < err)
    {
      err = -1 * (err - (N + E));
    }
  }
  else if (x >= 0 && y < 0)
  {
    if (S + E < err)
    {
      err = -1 * (err - (S + E));
    }
  }
  else if (x < 0 && y >= 0)
  {
    if (N + W < err)
    {
      err = -1 * (err - (N + W));
    }
  }
  else
  {
    if (S + W < err)
    {
      err = N+S+W+E-err;
    }
  }
  cout << 2 * (abs(x) + abs(y) + err);
  return 0;
}