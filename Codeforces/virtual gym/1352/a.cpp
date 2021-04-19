#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

vector<int> f(int n){
  vector<int> v;
  int i = 1, a;
  while(n){
    a = n%10;
    n /= 10;
    if(a*i) v.push_back(a*i);
    i *= 10;
  }
  return v;
}

int main(){
  FAST_IO;
  int t, n, a;

  cin >> t;

  while(t--){
    cin >> n;
    vector<int> v = f(n);
    cout << v.size() << "\n";
    for(int i = 0; i < v.size(); ++i){
      cout << v[i];
      if(i < v.size()-1) cout << " ";
    }
    cout << "\n";
  }


  return 0;
}