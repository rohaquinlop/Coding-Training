#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef vector <int> vi;
typedef vector <ll> vll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

typedef vector < pii > vpii;
typedef vector < pll > vpll;

typedef vector <string> vs;
typedef vector < vi > vvi;
typedef vector < vll > vvll;

#define fl(i, a, b)	for (int i(a); i < (b); i ++)

#define all(v) 	(v).begin(), (v).end()
#define srt(v)	sort (all (v))

#define pb push_back
#define mp make_pair

#define dig(i)	(s[i] - '0')
#define slen(s)	s.length()

#define fr first
#define sc second

#define len(x) ((int) (x).size())
#define fill (x, y)	memset(x, y, sizeof(x))
#define clr(a)	fill(a, 0)
#define endl '\n'

#define PI 3.14159265358979323

#define trace1(x1)					cerr << #x1 << ": " << x1 << endl;
#define trace2(x1, x2)				cerr << #x1 << ": " << x1 << " | " << #x2 << ": " << x2 << endl;
#define trace3(x1, x2, x3)			cerr << #x1 << ": " << x1 << " | " << #x2 << ": " << x2 << " | " << #x3 << ": " << x3 << endl;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

const ll MOD = 1000000007LL;
const ll MAX = 100010LL;

template <typename T> T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }
template <typename T> T power(T x, T y, ll m = MOD) { T ans = 1; x %= m; while (y > 0) { if (y & 1ll) ans = (ans * x) % m; y >>= 1ll; x = (x * x) % m; } return ans % m; }

bool isPrime(int n) {
  bool ans = true;

  for (int i = 2; i * i <= n and ans; i++) {
    if (n % i == 0) ans = false;
  }

  return ans;
}

vi getValues(int n) {
  vi ans;
  //see https://codeforces.com/blog/entry/20766

  for (int p = n - 1; p > 1; p--) {
    if (isPrime(p)) {
      for (int q = n - p; q > 1; q--) {
        if (isPrime(q)) {
          for (int r = n - p - q; r > 1; r--) {
            if (isPrime(r) and r + p + q == n) {
              ans.pb(p);
              ans.pb(q);
              ans.pb(r);
              return ans;
            }
          }
        }
      }
    }
  }

  return ans;
}


int main() {
  FAST_IO;

  int n;

  cin >> n;

  //Determine if is n is prime
  if (isPrime(n)) {
    cout << 1 << endl << n << endl;
  }
  else {
    vi ans = getValues(n);

    cout << ans.size() << endl;

    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i];
      if (i < ans.size() - 1) cout << " ";
    }
  }

  return 0;
}