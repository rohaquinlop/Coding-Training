#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n){
  for(int i = 2; i < n; ++i){
    if(n%i == 0) return false;
  }
  return true;
}

int nextPrime(int n){
  bool f = false;
  while(!f){
    if(isPrime(++n)) f = true;
  }
  return n;
}

int main(){
  int n, m, k;

  while( cin >> n >> m){
    k = nextPrime(n);
    if(k == m) cout << "YES\n";
    else cout << "NO\n";
  }


  return 0;
}