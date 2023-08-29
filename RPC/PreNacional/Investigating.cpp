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

int main() {
  FAST_IO;
  int n;
  int q;

  cin >> n;

  vi frog_pos(n);
  set<int> empty_leafs;

  for (int& x : frog_pos) cin >> x;

  for (int i = 0; i < len(frog_pos) - 1; i++) {
    int d = frog_pos[i + 1] - frog_pos[i];

    if (d > 1) {
      fl(j, 1, d) empty_leafs.insert(frog_pos[i] + j);
    }
  }

  cin >> q;

  int t;
  int pos;
  int max_pos = frog_pos[len(frog_pos) - 1];

  fl(i, 0, q) {
    cin >> t;
    pos = frog_pos[t - 1];

    empty_leafs.insert(pos);

    // Ahora hay que buscar la proxima hoja libre mayor a pos
    auto it = empty_leafs.upper_bound(pos);

    if (it == empty_leafs.end() or *it == pos) {
      // No hay una hoja libre mayor a pos
      max_pos++;
      cout << max_pos << endl;
      frog_pos[t - 1] = max_pos;
    } else {
      // Hay una hoja libre mayor para esa posicion
      cout << *it << endl;
      frog_pos[t - 1] = *it;
      empty_leafs.erase(it);
    }
  }

  return 0;
}