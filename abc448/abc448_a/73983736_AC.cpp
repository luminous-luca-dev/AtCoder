#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,p;
  cin >> n >> p;
  vector<int> s(n);
  
  for (int i = 0; i<n; i++){
    cin >> s[i];
    if (s[i] < p){
      p = s[i];
      cout<<1<<endl;
    } else {
      cout << 0 <<endl;
    }
  }
}