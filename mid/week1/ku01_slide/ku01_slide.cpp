#include <iostream>
using namespace std;

int main(){
  int N,total,jum;
  total = 0;
  cin >> N;
  int penguin[N];
  for (int i=0;i<N;i++){
    cin >> penguin[i];
    jum = penguin[i];
    for (int j=0;j<i;j++){
      if (penguin[j]<jum) {
        total++;
      }
    }
  }
  cout << total;
}