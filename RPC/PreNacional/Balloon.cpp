#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

typedef vector<pii> vpii;
typedef vector<pll> vpll;

typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

#define fl(i, a, b) for (int i = a; i < b; ++i)

#define all(v) (v).begin(), (v).end()
#define srt(v) sort(all(v))

#define pb push_back
#define mp make_pair

#define dig(i) (s[i] - '0')
#define slen(s) s.length()

#define fr first
#define sc second

#define len(x) x.size()
#define fill(x, y) memset(x, y, sizeof(x))
#define clr(a) fill(a, 0)
#define endl '\n'

#define PI 3.14159265358979323

#define trace1(x1) cerr << #x1 << ": " << x1 << endl;
#define trace2(x1, x2) \
  cerr << #x1 << ": " << x1 << " | " << #x2 << ": " << x2 << endl;
#define trace3(x1, x2, x3)                                                \
  cerr << #x1 << ": " << x1 << " | " << #x2 << ": " << x2 << " | " << #x3 \
       << ": " << x3 << endl;

#define FAST_IO                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)

const ll MOD = 1000000007LL;
const ll MAX = 100010LL;

template <typename T>
T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <typename T>
T power(T x, T y, ll m = MOD) {
  T ans = 1;
  x %= m;
  while (y > 0) {
    if (y & 1ll) ans = (ans * x) % m;
    y >>= 1ll;
    x = (x * x) % m;
  }
  return ans % m;
}

struct line_equation {
  int A, B, C;
};

line_equation get_line_equation(pii &p, pii &q) {
  line_equation l;

  l.A = p.sc - q.sc;
  l.B = q.fr - p.fr;
  l.C = -1 * (l.A * p.fr) - (l.B * p.sc);

  return l;
}

bool solve(int n, int k, vpii v) {
  if (n <= k) return true;
  if (k == 0) return false;

  bool ans = false;

  vector<line_equation> vle;
  vpii not_match_points;
  int e, flag;

  fl(i, 0, k) fl(j, i + 1, k + 1) vle.pb(get_line_equation(v[i], v[j]));

  for (line_equation &le : vle) {
    vpii tmp;
    for (pii &p : v) {
      e = le.A * p.fr + le.B * p.sc + le.C;
      if (e != 0) {
        tmp.pb(p);
      }
    }
    ans = ans or solve(len(tmp), k - 1, tmp);
  }

  return ans;
}

int main() {
  FAST_IO;

  int n, x, y;

  cin >> n;

  vpii v(n);

  for (pii &x : v) cin >> x.fr >> x.sc;

  if (solve(n, 3, v))
    cout << "possible" << endl;
  else
    cout << "impossible" << endl;

  return 0;
}
