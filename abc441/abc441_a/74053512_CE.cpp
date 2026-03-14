#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  int x, y;
  cin >> x >> y;
  
  if (x < n || y < m){
    cout << "No" << "\n";
  } else if (x < n + 100 && y < m + 100){
    cout << "Yes" << "\n";
  } else {
    cout << "No" << "\n";
  }
  return 0;