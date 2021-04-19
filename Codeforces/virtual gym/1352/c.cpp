#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main(){
  FAST_IO;
  int t, n, a, k;
  cin >> t;

  while(t--){
    cin >> n >> k;
    // long long cnt = 0, a = n, i = 0;
    // while(cnt < k){
    //   ++i;
    //   a *= i;
    //   cnt = a-i;
    // }
    // cout << a-(cnt-k)-1 << "\n";
    double i = k/(n-1);
    a = n*i;
    int m = n*i-i;
    int res = a - (m-k);
    if(res%n == 0) res--;
    cout << res << "\n";
  }


  return 0;
}