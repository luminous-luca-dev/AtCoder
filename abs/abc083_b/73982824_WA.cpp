#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, a, b;
  cin >> n >> a >> b;
  int count = 0;
  
  for (int i = 0; i <= n; i++){
    int x = i / 10;
    int y = i - 10*x;
    if (x+y >= a && x+y <= b){
      count += i;
    }
  }
  
}