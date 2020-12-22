#include<bits/stdc++.h>

using namespace std;

int main(){
  string s, k;

  while(cin >> s >> k){
    string m(s.size(), '0');
    for(int i = 0; i < s.size(); ++i){
      if( s[i] != k[i] ) m[i] = '1';
    }
    cout << m << "\n";
  }


  return 0;
}