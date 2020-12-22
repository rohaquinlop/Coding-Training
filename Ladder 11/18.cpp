#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main(){
  FAST_IO;
  int n, i;

  while(cin >> n){
    vector<int>v(n);
    int maxV=-1, minV=-1, cnt=0;
    for(i=0; i < n; ++i){
      cin >> v[i];
      if(maxV == -1) maxV = v[i];
      if(minV == -1) minV = v[i];

      if(maxV < v[i]){
        cnt++;
        maxV = v[i];
      }
      if(minV > v[i]){
        cnt++;
        minV = v[i];
      }
    }

    cout << cnt << "\n";
  }


  return 0;
}