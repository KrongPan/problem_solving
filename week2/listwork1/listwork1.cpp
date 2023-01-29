#include <iostream>
using namespace std;
#include <list>
#include <algorithm>

int main(){
  list<int> numlist;
  list<int>::iterator it;
  int n,data;
  char order;
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> order >> data;
    //cout << '[' << order << ',' << data << ']' << '\n';
    if (order == 'I') {
      numlist.push_front(data);
    }else if (order == 'D' && data <= numlist.size()) {
      it = numlist.begin();
      advance (it,data-1);
      numlist.erase(it);
    }
  }
  for_each(numlist.begin(),numlist.end(), [](const int n) {cout << n << '\n';});
}