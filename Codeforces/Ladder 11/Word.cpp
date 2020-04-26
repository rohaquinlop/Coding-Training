#include<bits/stdc++.h>

using namespace std;

int main(){
  string s;

  while(cin >> s){
    int a = 0, b = 0, i;
    //counting
    for(i = 0; i < s.size(); ++i){
      if( s[i] >= 'a' and s[i] <= 'z' ) ++a;
      else ++b;
    }

    //convert string
    if(b > a){
      //To upper
      for(i = 0; i < s.size(); ++i){
        s[i] = ::toupper(s[i]);
      }
    }
    else{
      //To lower
      for(i = 0; i < s.size(); ++i){
        s[i] = ::tolower(s[i]);
      }
    }

    cout << s << "\n";
  }


  return 0;
}