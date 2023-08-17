/*
ADAMATCH - Ada and Nucleobase
https://www.spoj.com/problems/ADAMATCH/
#fft
Accepted: Pending - WA
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
  string s, r;

  cin >> s;
  cin >> r;

  vll a(r.size()), b(s.size());
  vll v_ans;

  // A

  for (int i = 0; i < r.size(); i++) a[i] = r[i] == 'A' ? 1 : 0;

  for (int i = 0; i < s.size(); i++) b[s.size() - 1 - i] = s[i] == 'A' ? 1 : 0;

  vll res = multiply(a, b);

  for (ll x : res) v_ans.push_back(x);

  // C

  for (int i = 0; i < r.size(); i++) a[i] = r[i] == 'C' ? 1 : 0;

  for (int i = 0; i < s.size(); i++) b[s.size() - 1 - i] = s[i] == 'C' ? 1 : 0;

  res = multiply(a, b);

  for (int i = 0; i < res.size(); i++) v_ans[i] += res[i];

  // T

  for (int i = 0; i < r.size(); i++) a[i] = r[i] == 'T' ? 1 : 0;

  for (int i = 0; i < s.size(); i++) b[s.size() - 1 - i] = s[i] == 'T' ? 1 : 0;

  res = multiply(a, b);

  for (int i = 0; i < res.size(); i++) v_ans[i] += res[i];

  // G

  for (int i = 0; i < r.size(); i++) a[i] = r[i] == 'G' ? 1 : 0;

  for (int i = 0; i < s.size(); i++) b[s.size() - 1 - i] = s[i] == 'G' ? 1 : 0;

  res = multiply(a, b);

  for (int i = 0; i < res.size(); i++) v_ans[i] += res[i];

  ll ans = r.size();

  for (int i = r.size() - 1; i < v_ans.size(); i++)
    ans = min(ans, (ll)r.size() - v_ans[i]);

  cout << ans << "\n";

  return 0;
}
