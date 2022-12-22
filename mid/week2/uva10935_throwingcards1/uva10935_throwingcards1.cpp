#include <iostream>
#include <list>
using namespace std;

int main() {
  int n,z;
  list<int> deck;
  while(true) {
    cin >> n;
    if (n == 0) {
      break;
    } else {
      deck.push_back(n);
    }

  }
  while(deck.size() != 0) {
    z = 0;
    list<int> card;
    for (int i=0;i<*deck.begin();i++) {
      card.push_back(i+1);
    }
    deck.erase(deck.begin());
    cout << "Discarded cards:";
    while(card.size() != 1) {
      if(z!=0) {
        cout << ',';
      } else {
        z = 1;
      }
      cout << " " ;
      cout << *card.begin();
      card.erase(card.begin());
      card.push_back(*card.begin());
      card.erase(card.begin());
    }
    cout << '\n' << "Remaining card: " << *card.begin() << '\n';
  }
}