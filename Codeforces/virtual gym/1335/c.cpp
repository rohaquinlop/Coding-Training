#include<bits/stdc++.h>

using namespace std;

int main(){
  int t, n;

  cin >> t;

  while(t--){
    cin >> n;
    map<int, int> m;
    vector<int> v(n);
    vector<int> visited(n, -1);
    for(int i = 0; i < n; ++i){
      cin >> v[i];
      m[ v[i] ]++;
    }

    if(m.size() == 1) cout << 0 << "\n";
    else{
      int maxVal = -1;
      int val;
      for(auto x : m){
        if( x.second > maxVal ){
          maxVal = x.second;
          val = x.first;
        }
      }

      if(m.size() == maxVal){
        maxVal--;
      }

      cout << maxVal << "\n";
    }
  }

  return 0;
}