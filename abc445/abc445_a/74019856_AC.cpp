#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  char i = s[0];
  char e = s[s.size()-1];
  if (i == e){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}