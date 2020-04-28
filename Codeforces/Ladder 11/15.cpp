#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  while(cin >> n){
    double accum = 0;
    double tmp;
    for(int i = 0; i < n; ++i){
      cin >> tmp;
      accum += tmp;
    }
    tmp = (accum/(double)n);

    cout << fixed << setprecision(12) << tmp << "\n";
  }


  return 0;
}