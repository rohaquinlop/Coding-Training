/*
MAXMATCH - Maximum Self-Matching
https://www.spoj.com/problems/MAXMATCH/
#fft
Accepted: https://www.spoj.com/status/ns=31719469
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd>& a, bool invert) {
  int n = a.size();

  for (int i = 1, j = 0; i < n; i++) {
    int bit = n >> 1;
    for (; j & bit; bit >>= 1) j ^= bit;
    j ^= bit;

    if (i < j) swap(a[i], a[j]);
  }

  for (int len = 2; len <= n; len <<= 1) {
    double ang = 2 * PI / len * (invert ? -1 : 1);
    cd wlen(cos(ang), sin(ang));
    for (int i = 0; i < n; i += len) {
      cd w(1);
      for (int j = 0; j < len / 2; j++) {
        cd u = a[i + j], v = a[i + j + len / 2] * w;
        a[i + j] = u + v;
        a[i + j + len / 2] = u - v;
        w *= wlen;
      }
    }
  }

  if (invert) {
    for (cd& x : a) x /= n;
  }
}

vector<long long> multiply(vector<long long> const& a,
                           vector<long long> const& b) {
  vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
  int n = 1;

  while (n < a.size() + b.size()) n <<= 1;

  fa.resize(n);
  fb.resize(n);

  fft(fa, false);
  fft(fb, false);

  for (int i = 0; i < n; i++) fa[i] *= fb[i];

  fft(fa, true);

  vector<long long> result(n);

  for (int i = 0; i < n; i++) result[i] = round(fa[i].real());

  return result;
}

int main() {
  string s;

  cin >> s;

  int N = s.size();
  vll a(N, 0), a_inv(N, 0);
  vll ans(N, 0);

  for (int i = 0; i < N; i++) {
    a[i] = a_inv[N - i - 1] = s[i] == 'a' ? 1 : 0;
  }

  vll res = multiply(a, a_inv);

  for (int i = 1; i < N; i++) {
    ans[i] = res[N - 1 + i];
  }

  a = vll(N, 0), a_inv = vll(N, 0);
  for (int i = 0; i < N; i++) {
    a[i] = a_inv[N - i - 1] = s[i] == 'b' ? 1 : 0;
  }

  res = multiply(a, a_inv);

  for (int i = 1; i < N; i++) {
    ans[i] += res[N - 1 + i];
  }

  a = vll(N, 0), a_inv = vll(N, 0);
  for (int i = 0; i < N; i++) {
    a[i] = a_inv[N - i - 1] = s[i] == 'c' ? 1 : 0;
  }

  res = multiply(a, a_inv);

  for (int i = 1; i < N; i++) {
    ans[i] += res[N - 1 + i];
  }

  ll maximal_ms = 0;

  for (int i = 1; i < N; i++) maximal_ms = max(maximal_ms, ans[i]);

  vll idx;

  for (int i = 1; i < N; i++) {
    if (ans[i] == maximal_ms) idx.push_back(i);
  }

  cout << maximal_ms << "\n";

  for (int i = 0; i < idx.size(); i++) {
    cout << idx[i];
    if (i < idx.size() - 1) cout << " ";
  }
  cout << "\n";

  return 0;
}
