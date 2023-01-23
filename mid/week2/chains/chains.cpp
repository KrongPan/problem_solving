#include <iostream>
using namespace std;

int main() {
  int be[10001];
  int fo[10001];
  int L,N,M,count,robot,c,temp;
  robot = 1;
  char order;
  count = 1;
  cin >> L >> N;
  for (int i=0; i<L; i++) {
    cin >> M;
    for (int j=0 ; j < M; j++) {
      if (j == 0) {
        be[count] = 0;
        fo[count] = count+1;
      } else if (M-j == 1) {
        fo[count] = count-1;
        be[count] = count-1;
      }else {
        fo[count] = count+1;
        fo[count] = count-1;
        be[count+1] = count;
        be[count] = count-1;
      }
      count++;
    }
  }
  for (int i=0; i<N; i++) {
    //cout << robot;
    cin >> order;
    if (order == 'B') {
      if (robot != 1) {
        robot = be[robot];
      }
    } else if (order == 'F'){
      if (fo[robot] != 0) {
        robot = fo[robot];
      }
    } else if (order == 'C') {
      cin >> c;
      temp = c;
      be[fo[robot]] = 0;
      fo[robot] = c;
      robot = temp;
    }
  }
  robot = 1;
  while (fo[robot] != 0) {
    cout << robot << '\n';
    robot = fo[robot];
  }
  cout << robot;
}