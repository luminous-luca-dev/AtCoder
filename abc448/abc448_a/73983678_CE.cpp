#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,p;
  cin >> n >> p;
  vector<int> s;
  cin >> s;
  
  while (int &x : s){
    if (x < p){
      p = x;
      cout<<1<<endl;
    } else {
      cout << 0 <<endl;
    }
  }
}