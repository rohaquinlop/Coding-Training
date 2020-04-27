#include <bits/stdc++.h>

using namespace std;

int main(){
  string s;

  while(cin >> s){
    string res;
    int i = 0;

    while(i < s.size()){
      if( s[i] == '.') res += '0';
      else{
        if( s[++i] == '.' ) res += '1';
        else res += '2';
      }
      i++;
    }
    cout << res << "\n";
  }


  return 0;
}