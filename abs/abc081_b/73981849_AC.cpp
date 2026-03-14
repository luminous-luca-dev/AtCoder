#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> s(n);
  for (int &x : s) {
    cin >> x;
  }
  int count = 0;
  bool tf = true;
  while (tf == true) {
    for (int &x : s) {
      if (x % 2 == 0) {
        x /= 2;
      } else {
        tf = false;
        break;
      }
    }
    if (tf == true) {
      count += 1;
    }
  }
  cout << count << endl;
}