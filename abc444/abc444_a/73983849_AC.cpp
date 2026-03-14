#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int x = n / 100;
  int y = (n- 100*x) /10;
  int z = n%10;
  if (x==y && y==z){
    cout <<"Yes"<<endl;
  } else {
    cout <<"No"<<endl;
  }
  
}