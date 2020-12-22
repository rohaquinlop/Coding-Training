#include<bits/stdc++.h>

using namespace std;

bool verifyFunction(int n){
  if(n == 0) return false;
  while(n){
    if(n%10 != 4 and n%10 != 7 ) return false;
    n /= 10;
  }
  return true;
}

int countDigits(string &s){
  int cnt = 0;
  for(int i = 0; i < s.size(); ++i){
    if( s[i] == '4' or s[i] == '7' ) cnt++;
  }
  return cnt;
}

int main(){
  string s;

  while(cin >> s){
    if( verifyFunction(countDigits(s)) ) cout << "YES\n";
    else cout << "NO\n";
  }

  return 0;
}