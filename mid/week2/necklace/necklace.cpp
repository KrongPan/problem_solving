#include <iostream>
#include <array>
using namespace std;

int main() {
  array<int,300000> lace;
  array<int,300000> end;//เริ่มที่ตำเเหน่ง จบที่เลขที่เก็บ
  array<int,300000> start;
  int n,x,y,a,total;
  cin >> n;
  total = n*(n+1)/2;
  for (int i=1; i<n; i++) {
    cin >> x >> y;
    total-=x;
    if (lace[y] == 0) {
      lace[y] = x;
      if (lace[x] == 0) {
        end[y] = x;
      } else {
        end[y] = end[x];
      }
      if (start[y] != 0) {
        start[end[y]] = start[y]; 
        end[start[end[y]]] = end[y];
      } else {
        start[end[y]] = y;
      } 
    } else {
      a = lace[y];
      if (lace[x] == 0) {
        end[y] = x;
      } else {
        
      }
      lace[y] = x;
      lace[end[x]] = a;
    }
  }  
  for(int i=0; i<n; i++) {
    a = lace[total];
    cout << total << " ";
    total = a;
  }
}