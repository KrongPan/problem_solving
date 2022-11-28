#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int main() {
  int N,total;
  total = 0;
  cin >> N;
  int size;
  int bowl[300];
  for (int i=0;i<300;i++) {
    bowl[i] = 0;
  }
  for (int i=0;i<N;i++) {
    cin >> size;
    size -= 1;
    bowl[size] += 1;
  }
  cout << *max_element(begin(bowl), end(bowl));
}