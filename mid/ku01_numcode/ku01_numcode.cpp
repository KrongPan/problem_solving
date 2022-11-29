#include <iostream>
using namespace std;

int main(){
  int N,T;
  cin >> N >> T;
  int data[N];
  if (T == 2){
    for (int i=0;i<N;i++){
      cin >> data[i];
      if (i==0){
      } else if(data[i]-data[i-1]>data[i-1]){
        data[i] -= data[i-1]*2;
      }else {
        data[i] -= data[i-1];
      }
    }
  }else{
    for (int i=0;i<N;i++){
      cin >> data[i];
    }
  }
  /*
  for (int i=0;i<N;i++){
      cout << data[i] << " ";
    }
  cout << "\n";
  */
  for (int i=0;i<N;i++) {
    if (i==0) {
      if (N-1==data[i]){
        cout << '0' << "\n";
      } else if (N+1==data[i]) {
        cout << '1' << "\n";
      }
    } else if (data[i]==data[i-1]+1) {
      cout << '1' << "\n";
    } else if (data[i]==data[i-1]-1) {
      cout << '0' << "\n";
    }
  }
}