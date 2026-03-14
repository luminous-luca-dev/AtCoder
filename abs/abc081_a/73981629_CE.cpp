#include <iostream>
#include <vector>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  vector<int> s = {a, b, c};
  int count=0;
  for (int i = 0; i < s.size(); i++) {
    if (vector[i] == 1) {
      count += 1;
    }
  }
  cout << count << endl;
}