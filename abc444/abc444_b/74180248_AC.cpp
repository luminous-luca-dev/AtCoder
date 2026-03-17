#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  int count = 0;
  
  for (int i = 0; i < n; i++){
    int sum = 0;
    int unit = i+1;
    
    while (unit > 0){
      sum += unit % 10;
      unit /= 10; 
    }
    
    if (sum == m){
      count += 1;
    }
  }
  cout << count << "\n";
  
  

  return 0;
}