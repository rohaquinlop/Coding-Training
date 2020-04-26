#include<bits/stdc++.h>

using namespace std;

int main(){
  int t, n, a, d = 0, i, j, rows, columns;

  cin >> t;

  while(t--){
    ++d;
    cin >> n;
    vector< vector<int> >v(n, vector<int>(n));
    vector< vector<int> > r(n, vector<int>(n, 0));
    vector< vector<int> > c(n, vector<int>(n, 0));
    vector<int> vR(n, 0);
    vector<int> vC(n, 0);
    a = 0, rows = 0, columns = 0;

    for(i = 0; i < n; ++i){
      for(j = 0; j < n; ++j){
        cin >> v[i][j];
        if( i == j){
          a += v[i][j];
        }
        c[ v[i][j]-1 ][j]++;
        r[ v[i][j]-1 ][i]++;
        if( c[ v[i][j]-1 ][j] == 2 and !vR[j]){
          columns++;
          vR[j]++;
        }
        if( r[ v[i][j]-1 ][i] == 2 and !vC[i]){
          rows++;
          vC[i]++;
        }
      }
    }

    cout << "Case #" << d << ": " << a << " " << rows << " " << columns << "\n";
  }


  return 0;
}