#include <bits/stdc++.h>

using namespace std;

string f(string &s, int n){
  string r = "";
  while(n--){
    r += s;
  }
  return r;
}

int main(){
  int n, c = 0;
  cin >> n;

  while(n--){
    c++;
    string s, a = "";
    cin >> s;
    int i;
    for(i = 0; i < s.size(); i++){
      a += s[i];
      if( f(a, s.size()/(i+1)) == s ){
        break;
      }
    }
    if(c > 1) cout << "\n";
    cout << a.size() << "\n";
  }


  return 0;
}