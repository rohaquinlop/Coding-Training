#include<bits/stdc++.h>

using namespace std;

int main(){
  int t;
  long long n;

  cin >> t;

  while(t--){
    cin >> n;
    long long res;
    res = n/2;
    if(n%2 == 0) --res;

    cout << res << "\n";
  }


  return 0;
}