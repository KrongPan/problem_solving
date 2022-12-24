#include <iostream>
#include <list>
using namespace std;

int main() {
  int n,p,c,v;
  list<int> eff;
  eff.push_front(1000000001);
  c = 0;
  cin >> n;
  for (int i=0; i<n; i++) {
    cin >> p >> v;
    while(*eff.begin() < v) {
      c++;
      eff.erase(eff.begin());
    }
    eff.push_front(v);
  }
  cout << c;
}
// c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0c=0