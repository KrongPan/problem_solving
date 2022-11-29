#include <iostream>
using namespace std;

int main(){
  int N,count_group,jum,max;
  max = 0;
  cin >> N;
  int object[N];
  int person[N];
  for (int i=0;i<N;i++) {
    person[i] = 0;
    cin >> object[i];
  }
  for (int i=0;i<N;i++) {
    if (person[i]==1) {
      continue;
    } else {
      jum = object[i];
      count_group = 1;
      person[i] = 1;
      while (i+1 != jum) {
        person[jum-1] = 1;
        jum = object[jum-1];
        count_group++;
      }
    }
    if (max < count_group) {
      max = count_group;
    }
  }
  cout << max;
  return 0;
}