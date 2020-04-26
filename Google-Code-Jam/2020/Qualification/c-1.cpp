#include<bits/stdc++.h>

using namespace std;

struct Num{
  int start;
  int end;
  int index;

  Num(int start, int end, int index): start(start), end(end), index(index){}
};

struct NumOrder{
  bool operator()(Num const& s, Num const& t){
    if(s.start == t.start)
      return s.end > t.end;
    return s.start > t.start;
  }
};

void updateVector(vector<int> &v, int a, int b){
  for(int i = a; i <= b; ++i){
    v[i] = 1;
  }
}

bool verifyLiberty(vector<int> &v, int a, int b){
  for(int i = a; i <= b; ++i){
    if( v[i] == 1 and (i != a) ) return false;
  }
  return true;
}

int main(){
  int n, t, c=0, i, j, a, b;

  cin >> t;
  while(t--){
    cin >> n;
    ++c;
    vector<int> cameron(1441, 0);
    vector<int> jamie(1441, 0);
    priority_queue<Num, vector<Num>, NumOrder> cola;
    string s(n, '0');

    for(i = 0; i < n; ++i){
      cin >> a >> b;
      cola.push( Num(a, b, i) );
    }

    while(!cola.empty()){
      a = cola.top().start;
      b = cola.top().end;
      i = cola.top().index;
      cola.pop();

      if( verifyLiberty(cameron, a, b) ){
        s[i] = 'C';
        updateVector(cameron, a, b);
      }
      else if( verifyLiberty(jamie, a, b) ){
        s[i] = 'J';
        updateVector(jamie, a, b);
      }
      else{
        s = "IMPOSSIBLE";
        break;
      }
    }

    cout << "Case #" << c << ": " << s << "\n";
  }


  return 0;
}