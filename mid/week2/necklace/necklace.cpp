#include <iostream>
#include <array>
using namespace std;

int main() {
  array<int,300001> lace;
  int x,y,a;
  long long total,n;
  cin >> n;
  total = n*(n+1)/2;
  for (int i=1; i<n; i++) {
    cin >> x >> y;
    total-=x;
    if (lace[y] == 0) {
      lace[y] = x;
    } else {
      a = lace[y];
      lace[y] = x;
      while(lace[x] != 0) {
        x = lace[x];
      }
      lace[x] = a;
    }
  }  
  for(int i=0; i<n; i++) {
    a = lace[total];
    cout << total << " ";
    total = a;
  }
}