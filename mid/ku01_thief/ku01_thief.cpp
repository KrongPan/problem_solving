#include <iostream>
using namespace std;

int main(){
  int N,K,T,loop,count;
  count = 1;
  loop = 1;
  cin >> N >> K >> T;
  while(loop != T){
    count++;
    loop += K;
    //cout << loop << "|||";
    if (loop>N){
      loop %= N;
    } else{
      loop = loop;
    }
    //cout << loop << "\n";
    if (loop==1){
      count--;
      break;
    }
  }
  cout << count;
}