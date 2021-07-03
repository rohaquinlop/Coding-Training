#include <bits/stdc++.h>

using namespace std;

int m;
vector<int> vec;

void solve(int i, int anterior, int x, int N) {
  if (i + 1 < N) {
    if (vec[i + 1] - vec[i] <= x)
      anterior++;
    else
      anterior = 1;
    m = max(anterior, m);
    solve(i + 1, anterior, x, N);
  }
}

int main() {

  int N, X, aux1;

  while (cin >> N >> X) {
    vec = vector<int>();
    m = 1;
    for (int i = 0; i < N; i++) {
      cin >> aux1;
      vec.push_back(aux1);
    }
    solve(0, 1, X, N);
    cout << m << endl;
  }
  return 0;
}