#include<bits/stdc++.h>

using namespace std;

int main(){
  int n;
  while(cin >> n){
    vector<int>v(n);
    int maxVal = 0, minVal = INT_MAX, maxPos = 0, minPos = n-1;
    for(int i = 0; i < n; ++i){
      cin >> v[i];
      if(v[i] > maxVal){
        maxVal = v[i];
        maxPos = i;
      }
      if(v[i] <= minVal){
        minVal = v[i];
        minPos = i;
      }
    }
    minPos++;
    maxPos++;

    int ans = (n-minPos)+(maxPos-1);

    if(minPos < maxPos){
      cout << ans-1 << "\n";
    }
    else{
      cout << ans << "\n";
    }

  }


  return 0;
}