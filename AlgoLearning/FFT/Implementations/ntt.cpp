/*
We still want to multiply two polynomials in O(nlogn) time, but we want to do it
modulo some prime number p.

The NTT has the advantage, that it only works with integer, and therefore the
result are guaranteed to be correct.
*/

const long long mod = 998244353;     // 7340033
const long long root = 3;            // 5
const long long root_1 = 332748118;  // 4404020
const long long root_pw = 1 << 23;   // 1 << 20

int inverse(int i, int m) {
  return i <= 1 ? i : m - (long long)(m / i) * inverse(m % i, m) % m;
}

void ntt(vector<long long>& a, bool invert) {
  int n = a.size();

  for (int i = 1, j = 0; i < n; i++) {
    int bit = n >> 1;
    for (; j & bit; bit >>= 1) j ^= bit;
    j ^= bit;

    if (i < j) swap(a[i], a[j]);
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
    for (int& x : a) x = (int)(1LL * x * n_1 % mod);
  }
}
