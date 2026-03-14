#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> s(n);
  for (int i = 0; i < s.size(); i++) {
    cin >> s[i];
  }
  int count = 0;
  bool tf = true;
  while (tf == true) {
    for (int i = 0; i < s.size(); i++) {
      if (s[i] % 2 == 0) {
        s[i] /= 2;
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