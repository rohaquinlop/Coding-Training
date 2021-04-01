#include <bits/stdc++.h>
using namespace std;

void solve(int sz, vector<int>& b){
  int n = 1, lft = 0, rght = sz-1;
  bool turnSel = true;

  while(n <= sz){
    if(turnSel){
      cout << b[lft++];
    }
    else{
      cout << b[rght--];
    }
    turnSel = !turnSel;
    if(n < sz) cout << " ";
    n++;
  }
  cout << "\n";
}

int main() {
  int t, n, i;

  cin >> t;
  
  while(t--){
    cin >> n;
    vector<int> b(n);

    for(i = 0; i < n; i++) cin >> b[i];
    solve(n, b);
  }


	return 0;
}