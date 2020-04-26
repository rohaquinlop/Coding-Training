#include<bits/stdc++.h>

using namespace std;

bool isValid(int n){
  unordered_set<int> s;
  int a;
  while(n){
    a = n%10;
    n /= 10;
    if( s.count(a) ) return false;
    else s.insert(a);
  }
  return true;
}

int main(){
  int n;

  while(cin >> n){
    ++n;
    while(true){
      if( isValid(n) ) break;
      else n++;
    }
    cout << n << "\n";
  }


  return 0;
}