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

template <typename T> T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T power(T x, T y, ll m = MOD) { T ans = 1; x %= m; while (y > 0) { if (y & 1ll) ans = (ans * x) % m; y >>= 1ll; x = (x * x)%m; } return ans%m;}

/*
let a region be a subset of nodes such that:

1. a region has at least one marked node;
2. if a full path contains a node of a region, then the path contains all **marked** nodes of the region;
3. any two different regions do not intersect.

w(r, p): suma de los pesos de todos los nodos de una region que estan en un full path p.

b(r) = min_{w(r, p)>0} w(r, p) / max_{p} w(r, p)
*/

int main() {
	FAST_IO;
  int g, n, k, m, i, j, l, s, t;

  cin >> g;

  while(g--){
    cin >> n;
    vi w(n);
    vvi graph(n);
    vi marked(n, 0), inDeg(n, 0), outDeg(n, 0);

    for(int& x : w) cin >> x;

    cin >> k;
    fl(i, 0, k){
      cin >> j;
      marked[--j] = 1;
    }

    cin >> m;
    fl(i, 0, m){
      cin >> j >> l;
      j--, l--;
      outDeg[j]++, inDeg[l]++;
      graph[j].push_back(l);
    }

    fl(i, 0, n){
      if(inDeg[i] == 0) s = i;
      if(outDeg[i] == 0) t = i;
    }
  }


	return 0;
}