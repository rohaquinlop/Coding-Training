#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main(){
  FAST_IO;
  int n, i, a, b;

  while(cin >> n){
    int actCapacity=0, maxCapacity=0;
    for(i=0;i<n;++i){
      cin >> a >> b;
      actCapacity -= a;
      actCapacity += b;
      if(actCapacity > maxCapacity){
        maxCapacity = actCapacity;
      }
    }

    cout << maxCapacity << "\n";
  }


  return 0;
}