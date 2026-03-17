#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  int a, b, c, d, e, f;
  int count = 0;
  
  for (int i=0;i<n;i++){
    a = i / 100000;
    b = (i-100000*a) / 10000;
    c = (a-10000*b) / 1000;
    d = (b-1000*c) / 100;
    e = (c-100*d) / 10;
    f = n % 10;
    if (a+b+c+d+e+f == m){
      count += 1;
    }
  }
  cout << count <<"\n";
  
  

  return 0;
}