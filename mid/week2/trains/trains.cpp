#include <iostream>
using namespace std;
#include <list>
#include <array>

int main() {
  int n,x,m;
  char order;
  cin >> n;
  array<list<int>,100000> platform;
  list<int>::iterator it;
  for (int i=0; i<n; i++) {
    cin >> order >> x >> m;
    if (order == 'N') {
      platform[m-1].push_back(x); 
    } else if (order == 'M') {
      platform[m-1].splice(platform[m-1].end(),platform[x-1]);

    }
  }
  for (int i=0;i<100000;i++) {
    if (platform[i].size() == 0) {
      continue;
    }
    for (int j=0;j<platform[i].size();j++) {
      it = platform[i].begin();
      advance(it,j);
      cout << *it << "\n";
    }
  }
}