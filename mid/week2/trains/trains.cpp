#include <iostream>
using namespace std;
#include <list>

int main() {
  int n,x,m;
  char order;
  cin >> n;
  list<int> platform[100001];
  list<int>::iterator it;
  for (int i=0; i<n; i++) {
    cin >> order >> x >> m;
    if (order == 'N') {
      platform[m].push_back(x); 
    } else if (order == 'M') {
      platform[m].splice(platform[m].end(),platform[x]);

    }
  }
  for (int i=0;i<100001;i++) {
    if (platform[i].size() == 0) {
      continue;
    }
    for (it = platform[i].begin();it != platform[i].end();it++) {
      cout << *it << "\n";
    }
  }
  return 0;
}