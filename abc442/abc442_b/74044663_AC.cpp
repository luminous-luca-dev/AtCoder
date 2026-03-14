#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int vol = 0;
  int onoff = 0;
  
  for (int i = 0; i < n; i++){
    int act;
    cin >> act;
    
    if (act == 1){
      vol += 1;
    } else if (act == 2){
      if (vol >= 1){
        vol -= 1;
      }
    } else {
      if (onoff == 1){
        onoff = 0;
      } else {
        onoff = 1;
      }
    }
    if (onoff == 1 && vol >= 3){
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  
  return 0;
}