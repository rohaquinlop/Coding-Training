#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  string s;

  while(cin >> n){
    cin >> s;
    stack<char> p;
    int cnt = 0;
    for(char c : s){
      if( p.empty() ){
        p.push(c);
      }
      else{
        if(p.top() == c) cnt++;
        else p.push(c);
      }
    }
    cout << cnt << "\n";
  }


  return 0;
}