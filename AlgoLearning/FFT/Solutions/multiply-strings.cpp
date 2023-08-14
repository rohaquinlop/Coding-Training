/*
Leetcode: Multiply Strings
https://leetcode.com/problems/multiply-strings/description/

Solution:
https://leetcode.com/problems/multiply-strings/submissions/1020696116/
*/

class Solution {
 public:
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

  vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;

    while (n < a.size() + b.size()) n <<= 1;

    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);

    for (int i = 0; i < n; i++) fa[i] *= fb[i];

    fft(fa, true);

    vector<int> result(n);

    for (int i = 0; i < n; i++) result[i] = round(fa[i].real());

    /*
    Add if multiplying two long numbers
    */
    // Normalize the number
    int carry = 0;
    for (int i = 0; i < n; i++) {
      result[i] += carry;
      carry = result[i] / 10;
      result[i] %= 10;
    }
    // End of normalization

    return result;
  }

  string multiply(string num1, string num2) {
    vector<int> a, b;

    for (int i = num1.size() - 1; i >= 0; i--) a.push_back(num1[i] - '0');
    for (int i = num2.size() - 1; i >= 0; i--) b.push_back(num2[i] - '0');

    vector<int> result = multiply(a, b);

    bool flag = false;
    string ans = "";

    for (int i = result.size() - 1; i >= 0; i--) {
      if (flag) {
        ans += to_string(result[i]);
      } else if (result[i] != 0) {
        flag = true;
        ans = to_string(result[i]);
      }
    }

    if (ans == "") ans = "0";

    return ans;
  }
};
