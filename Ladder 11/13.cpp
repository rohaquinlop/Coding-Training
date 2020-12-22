#include <bits/stdc++.h>

using namespace std;


int main(){
  int n;

  while(cin >> n){
    //Create permutation
    if(n%2 != 0) cout << "-1\n";
    else{
      vector<int> v(n, 0);
      for(int i = 0; i < n; i += 2){
        v[i] = i+2;
        v[i+1] = i+1;
      }
      for(int i = 0; i < n; ++i){
        cout << v[i];
        if(i < n-1) cout << " ";
      }
      cout << "\n";
    }
  }


  return 0;
}