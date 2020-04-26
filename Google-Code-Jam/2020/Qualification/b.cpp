#include<bits/stdc++.h>

using namespace std;

class Num{
public:
  int n;
  string s;

  Num(int i, string m){
    n = i;
    s = m;
  }
};

string createRes(int n){
  if(n == 0) return "0";
  string s = "";
  for(int i = 0; i < n; ++i) s += "(";
  s += '0' + n;
  for(int i = 0; i < n; ++i) s += ")";

  return s;
}

Num sumNum(Num a, Num b){
  string s;
  if( a.n == 0){
    s = a.s;
    s += b.s;
    return Num(b.n, s);
  }
  if(b.n == 0){
    s = a.s;
    s += "0";
    return Num(0, s);
  }
  else{
    int cRemove = min(a.n, b.n);
    int t = cRemove;
    s = a.s;
    while(t--){
      s.pop_back();
    }

    string m = b.s;
    for(int i = cRemove; i < m.size(); ++i)
      s += m[i];
    return Num(b.n, s);
  }
}

int main(){
  int t, c = 0;
  string s;

  cin >> t;
  while(t--){
    ++c;
    cin >> s;

    queue<Num> cola;

    for(int i = 0; i < s.size(); ++i)
      cola.push( Num(s[i]-'0', createRes(s[i]-'0')) );

    int temp = 0;
    Num lastP(0, "0");

    while(!cola.empty()){
      if(!temp){
        lastP = cola.front();
        cola.pop();
        temp++;
      }
      else{
        lastP = sumNum(lastP, cola.front());
        cola.pop();
        temp++;
      }
    }

    cout << "Case #" << c << ": "  << lastP.s << "\n";
  }


  return 0;
}