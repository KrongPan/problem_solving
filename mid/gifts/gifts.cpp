#include <iostream>
using namespace std;

int main() {
  int N,M;
  cin >> N;
  int total;
  total = 0;
  for (int i=0;i<N;i++) {
    cin >> M;
    if (M > 0) {
      total += M; 
    }
  }
  cout << total;
}