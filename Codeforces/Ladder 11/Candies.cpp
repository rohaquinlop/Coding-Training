#include <bits/stdc++.h>

using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

long long binpow(long long a, long long b) {
  if (b == 0)
    return 1;
  long long res = binpow(a, b / 2);
  if (b % 2)
    return res * res * a;
  else
    return res * res;
}

int main(){
  FAST_IO;
  long long t, sn, b, k, accum;
  double a;
  cin >> t;
  while(t--){
    cin >> sn;
    bool f = false;
    k = 2;
    accum = 3;

    while(!f){
      a = (double)sn/accum;
      b = sn/accum;
      if(a-b == 0){
        f = true;
      }
      else{
        accum += binpow(2, k);
        ++k;
      }
    }
    cout << b << "\n";
  }

  return 0;
}