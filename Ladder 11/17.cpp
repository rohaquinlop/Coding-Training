#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main(){
  FAST_IO;
  int n, i;

  while(cin >> n){
    int a, b;
    int lOpen=0, rOpen=0;
    for(i = 0; i < n; ++i){
      cin >> a >> b;
      if(a){
        lOpen++;
      }
      if(b){
        rOpen++;
      }
    }
    int res = min(lOpen, n-lOpen)+min(rOpen, n-rOpen);
    cout << res << "\n";
  }


  return 0;
}