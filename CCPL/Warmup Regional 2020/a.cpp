#include <bits/stdc++.h>

using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb(x) push_back(x) 
#define N 100005 
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;

int main() {
  fastIO;

  int n, arcs[N], sumup = 0;
  cin >> n;

  set<int> cum;
  for (int i = 0; i < n; i++) {
    cin >> arcs[i];
    sumup += arcs[i];
    cum.insert(sumup);
  }
  cum.erase(sumup);
  cum.insert(0);
  if (sumup & 1) {
    cout << 'N' << endl;
    return 0;
  }
  int half = sumup / 2, pairs = 0, sumup2 = 0;
  for (int i = 0; i < n; i++) {
    sumup2 += arcs[i];
    if (cum.find((sumup2 + half) % sumup) != cum.end())
      pairs++;
  }
  if (pairs >= 4)
    cout << 'Y' << endl;
  else
    cout << 'N' << endl;
  return 0;
}