#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main(){
  FAST_IO;
  int k, l, m, n, d;

  while(cin >> k >> l >> m >> n >> d){
    int cnt = 0;
    for(int i = 1; i <= d; ++i){
      if(i%k == 0 || i%l == 0 || i%m==0 || i%n == 0) cnt++;
    }
    cout << cnt << "\n";
  }


  return 0;
}