#include <iostream>
using namespace std;

int main() {
  int n,p,vmax,count,v;
  vmax = 0;
  count = 0;
  cin >> n;
  for (int i=0; i<n; i++) {
    cin >> p >> v;
    if (v>vmax) {
      vmax = v;
      count+=i;
    }
  }
  cout << count;
}