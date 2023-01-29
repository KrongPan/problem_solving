#include <iostream>
#include <list>
using namespace std;

int main() {
  char c;
  int z = 0;// 0 เติมหน้า 1 เติมหลัง
  list<char> text;
  list<char> subtext;
  list<char> subtext2;
  list<char>::iterator it;
  while (true) {
    c = getchar();
    if (c == EOF) {
      break;
    }
    if (c == '[') {
      if (z == 0) {
        subtext.splice(subtext.begin(),subtext2);
      } else {
        subtext.splice(subtext.end(),subtext2);
      }
      subtext2.clear();
      z = 0;
      continue;
    } else if (c == ']') {
      if (z == 0) {
        subtext.splice(subtext.begin(),subtext2);
      } else {
        subtext.splice(subtext.end(),subtext2);
      }
      subtext2.clear();
      z = 1;
      continue;
    } else if (c == '\n') {
      if (z == 0) {
        subtext.splice(subtext.begin(),subtext2);
      } else {
        subtext.splice(subtext.end(),subtext2);
      }
      z = 0;
      subtext2.clear();
      subtext.push_back('\n');
      text.splice(text.end(),subtext);
      subtext.clear();
      continue;
    }
    subtext2.push_back(c);
  }
  for (it = text.begin();it!=text.end();it++) {
    cout << *it;
  }
}