#include <iostream>
using namespace std;

int main() {
  int N,K,min,count;
  count = 0;
  min = 1000000001;
  cin >> N >> K;
  double time[N];
  for (int i=0;i<N;i++) {
    cin >> time[i];
    if (time[i]<min) {
      min = time[i];
    }
  }
  if (K==1) {
    //cout << "sus";
    cout << N;
    return 0;
  } else {
    for (int i=0;i<N;i++) {
    //cout << "am in";
    time[i] = min/time[i]*K;
    //cout << "->" << time[i] << "\n";
    if (time[i]>K-1){
      count++;
    }
  }
  cout << count;
  return 0;
  }
}