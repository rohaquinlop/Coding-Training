#include<bits/stdc++.h>

using namespace std;

int main(){
  int a;
  int i, j, m, n;

  for(i = 0; i < 5; ++i){
    for(j = 0; j < 5; ++j){
      cin >> a;
      if(a == 1){
        m = i+1;
        n = j+1;
      }
    }
  }

  // cout << max(3, m)-min(3, m)+max(3, n)-min(3, n) << "\n";

  cout << abs(3-m)+abs(3-n) << "\n";


  return 0;
}