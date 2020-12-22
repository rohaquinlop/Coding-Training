#include<bits/stdc++.h>

using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int main(){
  FAST_IO;
  vector<vector<int>> v(3, vector<int>(3, 1));
  int a, i, j;
  for(i = 0; i < 3; ++i){
    for(j = 0; j < 3; ++j){
      cin >> a;
      a %= 2;
      if(a){
        v[i][j] = !v[i][j];
        for(int k = 0; k < 4; ++k){
          int x = j+dx[k], y = i+dy[k];
          if( (x >= 0 and x < 3) and (y >= 0 and y < 3)){
            v[y][x] = !v[y][x];
          }
        }
      }
    }
  }

  for(i = 0; i < 3; ++i){
    for(j = 0; j < 3; ++j){
      cout << v[i][j];
    }
    cout << "\n";
  }

  return 0;
}