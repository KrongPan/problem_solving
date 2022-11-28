#include <iostream>
using namespace std;

int main(){
  int N;
  int person[N];
  for (int i=0;i<N;i++) {
    cin >> person[i];
  }
  while(true){
    
    for (int i=0;i<N;i++) {
      person[i] = person[person[i]];
    } 
  }
}