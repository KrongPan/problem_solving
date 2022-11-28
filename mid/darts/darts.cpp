#include <iostream>
using namespace std;
#include <cmath>

int main() {
  int count,x,y,score;
  double use;
  score = 0;
  cin >> count;
  for (int i = 0; i < count; i++) {
    cin >> x >> y;
    use = sqrt(pow(x,2) + pow(y,2));
    if (use <= 2) {
      score += 5;
    } else if (use <= 4) {
      score += 4;
    } else if (use <= 6) {
      score += 3;
    } else if (use <= 8) {
      score += 2;
    } else if (use <= 10) {
      score += 1;
    } else {
      score += 0;
    }
  }
  cout << score;
}