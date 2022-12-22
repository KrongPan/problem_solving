#include <iostream>
#include <list>
using namespace std;

int main() {
  int N,c;
  c = 1;
  list<int> coaB;
  list<int> station;
  list<string> ans;
  list<string>::iterator it;
  list<int>::iterator it2;
  while (true) {
    while (true) {
      cin >> c;
      coaB.push_back(c);
      if(getchar() == '\n') {
        break;
      }
    }
    if (c == 0) {
      coaB.clear();
      if (N == -1) {
        break;
      }
      N = -1;
      ans.push_back("\n");
      continue;
    } else if (c != 0 && coaB.size() == 1){
      coaB.clear();
      N = c;
      continue;
    }
    for (int i=1; i<=N; i++) {
      while (*coaB.begin() == *station.begin()) {
        coaB.erase(coaB.begin());
        station.erase(station.begin());
      }
      if (i == *coaB.begin()) {
        coaB.erase(coaB.begin());
      } else {
        station.push_front(i);
      }
    }
    if (coaB == station) {
      ans.push_back("Yes");
      ans.push_back("\n");
    } else {
      ans.push_back("No");
      ans.push_back("\n");
    }
    coaB.clear();
    station.clear();
  }
  for (it = ans.begin(); it != ans.end(); it++) {
    cout << *it;
  }
}