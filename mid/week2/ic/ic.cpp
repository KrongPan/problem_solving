#include <iostream>
using namespace std;
#include <list>
#include <algorithm>

int main(){
  list<int> numlist;
  list<int>::iterator it;
  int n,data;
  string order;
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> order;
    if (order == "ri" || order == "li") {
      cin >> data;
    } else if ((order == "lr" || order == "rr")&&numlist.size() == 0) {
      continue;
    }   
    //cout << '[' << order << ',' << data << ']' << '\n';
    if (order == "ri") {
      numlist.push_back(data);
    }else if (order == "lr") {
      it = numlist.begin();
      numlist.push_back(*it);
      numlist.erase(it);
    } else if (order == "li") {
      numlist.push_front(data);
    } else if (order == "rr") {
      it = numlist.begin();
      advance(it,numlist.size()-1);
      numlist.push_front(*it);
      numlist.erase(it);
    }
    //for_each(numlist.begin(),numlist.end(), [](const int n) {cout << n << ' ';});
    //cout << '.' << '\n';
  }
  for_each(numlist.begin(),numlist.end(), [](const int n) {cout << n << '\n';});
}