#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int ans = 100;
  
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x > 0) {
      ans = min(ans, __builtin_ctz(x));
    }
  }
  cout << ans << endl;
  return 0;
}