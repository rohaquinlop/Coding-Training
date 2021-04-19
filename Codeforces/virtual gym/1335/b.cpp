#include<bits/stdc++.h>

using namespace std;

int main(){
  int t, n, a, b;

  cin >> t;

  while(t--){
    cin >> n >> a >> b;
    string s="";
    int cnt=0;
    for(int i = 0; i < n; ++i){
      if(cnt == 26 or cnt == b) cnt = 0;
      s += 'a'+cnt;
      cnt++;
    }

    cout << s << "\n";
  }



  return 0;
}