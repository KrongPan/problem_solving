#include <iostream>
using namespace std;

int main(){
  int x,y;
  x = 0;
  y = 0;
  string direction;
  cin >> direction;
  for (int i=0;i<direction.size();i++){
    //cout << i << "|";
    switch (direction[i])
    {
    case 'N':
      y++;
      break;
    case 'S':
      y--;
      break;
    case 'E':
      x++;
      break;
    case 'W':
      x--;
      break;
    case 'Z':
      x = 0;
      y = 0;
      break;
    default:
      break;
    }
  }
  cout << x << " " << y; 
}