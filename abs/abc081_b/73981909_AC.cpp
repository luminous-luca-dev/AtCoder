#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> s(n);
  int ans =100;
  
  for (int &x : s) {
    cin >> x;
    int count = 0;
    while (x > 0 && x % 2 == 0) {
      x /= 2;
      count += 1;
    }
    ans = min(ans, count);
  }
  
  cout << ans << endl;
}