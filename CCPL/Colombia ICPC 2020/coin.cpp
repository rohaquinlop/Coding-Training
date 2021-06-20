#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

int N, M;

struct Compare {
  bool operator()(int a, int b) {
    int diffa = abs(M - (a % M));
    int diffb = abs(M - (b % M));

    return diffa < diffb;
  }
};

long int solve(priority_queue<int, vi, Compare> pq) {
  long int ans = 0;

  while (!pq.empty()) {
    int a = pq.top();
    pq.pop();

    if (a % M != 0) {
      //Tomar el ultimo elemnto
      int b;

      priority_queue<int, vi, Compare> aux = pq;
      pq = priority_queue<int, vi, Compare>();

      while (!aux.empty()) {
        b = aux.top();
        aux.pop();

        if (aux.size() > 1) {
          pq.push(b);
        }
      }

      int extraVal = a % M;
      int need = M - (b % M);

      if (need >= extraVal) b += extraVal, ans += extraVal, pq.push(b);
      else a -= need, pq.push(a), ans += need;
    }
  }

  return ans;
}

int main() {
  int a, accum;

  while (cin >> N >> M and N and M) {
    accum = 0;

    priority_queue<int, vi, Compare> pq;

    for (int i = 0; i < N; i++) {
      cin >> a;
      accum += a;

      if (a % M != 0) pq.push(a);
    }

    if (accum % M != 0) cout << "Impossible\n";
    else cout << solve(pq) << "\n";
  }


  return 0;
}