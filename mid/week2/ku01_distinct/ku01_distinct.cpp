#include <iostream>
#include <list>
using namespace std;
#include <set>

int main() {
  int n,c;
  cin >> n;
  list<int> b;
  set<int> total;
  list<int>::iterator it;
  list<int>::iterator it2;
  for (int i=0; i<n; i++) {
    cin >> c;
    b.push_back(c);
  }
  for (it=b.begin(); it!=b.end(); it++) {
    n = 0;
    for (it2=it; it2!=b.end(); it2++) {
      n+=*it2;
      total.insert(n);
    }
  }
  cout << total.size();
}