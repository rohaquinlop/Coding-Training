#include<bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

bool commonString(vector<string> &vs){
  string s = vs[0];
  for(int i = 1; i < vs.size(); ++i){
    if( s.find( vs[i] ) == string::npos ) return false;
  }
  return true;
}

bool cmp(string &a, string &b){
  return a.size() > b.size();
}

int main(){
  FAST_IO;
  int t, c=0, n;
  string s;

  cin >> t;

  while(t--){
    ++c;
    cin >> n;
    vector<string> preffix;
    vector<string> suffix;
    for(int i = 0; i <n; ++i){
      cin >> s;
      string aux = "";
      bool f = false;
      for(char c : s){
        if(c == '*'){
          f = true;
          if(aux != ""){
            preffix.push_back(aux);
            aux = "";
          }
        }
        else aux += c;
      }
      if(aux != ""){
        suffix.push_back(aux);
      }
    }

    //Despues de tener los sufijos y prefijos lo que se hace es verificar que un string sea substring y en ese caso se elimina el substring
    sort(preffix.begin(), preffix.end(), cmp);
    sort(suffix.begin(), suffix.end(), cmp);
    string a, b;
    string res = "";
    if(preffix.size() ){
      if( commonString(preffix) ){
        a = preffix[0];
      }else{
        res = "*";
      }
    }
    if(res == ""){
      if( suffix.size() ){
        if( commonString(suffix) ){
          b = suffix[0];
        }
        else{
          res = "*";
        }
      }
    }

    cout << "Case #" << c << ": ";

    if(res == ""){
      if( a.find( b ) != string::npos ) cout << a << "\n";
      else if( b.find( a ) != string::npos ) cout << b << "\n";
      else cout << a << b << "\n";
    }
    else{
      cout << "*\n";
    }
  }



  return 0;
}