#include<bits/stdc++.h>

using namespace std;

int main(){
  int i, n, a, b, c, x, y, z;

  while(cin >> n){
    x=0, y=0, z=0;
    for(i = 0; i < n; ++i){
      cin >> a >> b >> c;
      x += a, y += b, z += c;
    }

    if(!x and !y and !z) cout << "YES\n";
    else cout << "NO\n";
  }


  return 0;
}