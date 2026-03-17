#include <bits/stdc++.h>
using namespace std;

int main(){

  int n;
  cin >> n;
  vector<int> A(n+1);
  for (int i=1; i<=n; i++){
    cin >> A[i];
  }
  
  for (int s = 1; s <= n; s++){
    int unit = s;
    for (int i = 0; i < n; i++){
      unit = A[unit];
    }
    
    cout << unit <<"\n";
  }
  return 0;

}