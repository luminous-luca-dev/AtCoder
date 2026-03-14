#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, a, b;
  cin >> n >> a >> b;
  int count = 0;
  
  for (int i = 0; i <= n; i++){
    int x = i / 10000;
    int y = (i - 10000*x) / 1000;
    int z = (x - 1000*y) / 100;
    int aa = (y - 100*z) / 10;
    int ab = z - 10*aa;
    int sum = x+y+z+aa+ab
    if (sum >= a && sum <= b){
      count += i;
    }
  }
  
}