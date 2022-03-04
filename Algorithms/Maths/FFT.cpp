using cd = complex<double>;
const double PI = acos(-1);

//Recursion implementation
void fft(vector<cd>& a, bool invert) {
  int n = a.size();
  if (n == 1)
    return;

  vector<cd> a0(n / 2), a1(n / 2);
  for (int i = 0; 2 * i < n; i++) {
    a0[i] = a[2 * i];
    a1[i] = a[2 * i + 1];
  }
  fft(a0, invert);
  fft(a1, invert);

  double ang = 2 * PI / n * (invert ? -1 : 1);
  cd w(1), wn(cos(ang), sin(ang));
  for (int i = 0; 2 * i < n; i++) {
    a[i] = a0[i] + w * a1[i];
    a[i + n / 2] = a0[i] - w * a1[i];
    if (invert) {
      a[i] /= 2;
      a[i + n / 2] /= 2;
    }
    w *= wn;
  }
}

//Number theory transformation
//The number theoretic transform (NTT) has the advantage, that it only works with integer, and therefore the result are guaranteed to be correct. Is slower than the implementation using complex numbers (due to the huge number of modulo operations), but it has some advantages such as less memory usage and no rounding errors.
const int mod = 7340033;
const int root = 5;
const int root_1 = 4404020;
const int root_pw = 1 << 20;

void fft(vector<int>& a, bool invert) {
  int n = a.size();

  for (int i = 1, j = 0; i < n; i++) {
    int bit = n >> 1;
    for (; j & bit; bit >>= 1)
      j ^= bit;
    j ^= bit;

    if (i < j)
      swap(a[i], a[j]);
  }

  for (int len = 2; len <= n; len <<= 1) {
    int wlen = invert ? root_1 : root;
    for (int i = len; i < root_pw; i <<= 1)
      wlen = (int)(1LL * wlen * wlen % mod);

    for (int i = 0; i < n; i += len) {
      int w = 1;
      for (int j = 0; j < len / 2; j++) {
        int u = a[i + j], v = (int)(1LL * a[i + j + len / 2] * w % mod);
        a[i + j] = u + v < mod ? u + v : u + v - mod;
        a[i + j + len / 2] = u - v >= 0 ? u - v : u - v + mod;
        w = (int)(1LL * w * wlen % mod);
      }
    }
  }

  if (invert) {
    int n_1 = inverse(n, mod);
    for (int& x : a)
      x = (int)(1LL * x * n_1 % mod);
  }
}


//Standard to multiply two vectors
vector<int> multiply(vector<int> const& a, vector<int> const& b) {
  vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
  int n = 1;
  while (n < a.size() + b.size())
    n <<= 1;
  fa.resize(n);
  fb.resize(n);

  fft(fa, false);
  fft(fb, false);
  for (int i = 0; i < n; i++)
    fa[i] *= fb[i];
  fft(fa, true);

  vector<int> result(n);
  for (int i = 0; i < n; i++)
    result[i] = round(fa[i].real());
  return result;
}

//Finally normalize the answer
int carry = 0;
for (int i = 0; i < n; i++) {
  result[i] += carry;
  carry = result[i] / 10;
  result[i] %= 10;
}
