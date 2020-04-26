#include<bits/stdc++.h>

using namespace std;

bool verifyFunction(string &s){
  for(int i = 0; i < s.size(); ++i){
    if( s[i] != '4' and s[i] != '7' ) return false;
  }
  return true;
}

int main(){
  string s;

  while(cin >> s){
    if( verifyFunction(s) ) cout << "YES\n";
    else cout << "NO\n";
  }

  return 0;
}