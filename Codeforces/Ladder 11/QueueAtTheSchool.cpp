#include<bits/stdc++.h>

using namespace std;

vector<int> updateVector(vector<int> &v, int& n){
  vector<int> r;
  for(int i = 0; i < v.size(); ++i){
    if(v[i] < n-1) r.push_back(v[i]);
  }
  return r;
}

int main(){
  int n, t, i, j;
  string s;

  while(cin >> n >> t){
    cin >> s;
    vector<int> b;

    for(i = 0; i < n-1; ++i){
      if( s[i] == 'B') b.push_back(i);
    }

    while(t-- and b.size()){
      for(i = 0; i < b.size(); ++i){
        j = b[i];
        if( s[j+1] == 'G' ){
          s[j] = 'G', s[j+1] = 'B';
          b[i]++;
        }
      }
      b = updateVector(b, n);
    }
    cout << s << "\n";
  }

  return 0;
}