/*
POLYMUL - Multiplying two polynomials
https://www.spoj.com/problems/POLYMUL/
#fft
Accepted: https://www.spoj.com/status/ns=31715825
*/
#include <bits/stdc++.h>

using namespace std;

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
  int t, n;

  cin >> t;

  while (t--) {
    cin >> n;
    vector<long long> a(n + 1), b(n + 1);

    for (int i = n; i >= 0; i--) cin >> a[i];
    for (int i = n; i >= 0; i--) cin >> b[i];

    vector<long long> c = multiply(a, b);
    bool flag = false;

    for (int i = 2 * n; i >= 0; i--) {
      cout << c[i];
      if (i > 0) cout << " ";
    }
    cout << "\n";
  }

  return 0;
}