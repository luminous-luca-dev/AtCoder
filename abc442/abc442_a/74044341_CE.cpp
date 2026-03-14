#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int count = 0;
  
  for (int i = 0; i < s.size(); i++){
    if (s[i] == "i" or s[i] == "j"){
      count += 1;
    }
  }
  cout << count << endl;
  return 0;
}