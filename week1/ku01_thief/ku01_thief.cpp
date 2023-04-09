#include <bits/stdc++.h>
using namespace std;

int N,K,T,loop;
int main(){
  int count;
  count = 1;
  loop = 1;
  cin >> N >> K >> T;
  while(loop != T)
  {
    count++;
    loop += K;
    //cout << loop << "|||";
    if (loop>N)
    {
      loop %= N;
    } 
    else
    {
      loop = loop;
    }
    //cout << loop << "\n";
    if (loop==1)
    {
      count--;
      break;
    }
  }
  cout << count;
  return 0;
}