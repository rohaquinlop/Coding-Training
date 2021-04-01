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

template <typename T> T gcd(T a, T b) { if (a == 0) return b; return gcd(b%a, a);}
template <typename T> T power(T x, T y, ll m = MOD) { T ans = 1; x %= m; while (y > 0) { if (y & 1ll) ans = (ans * x) % m; y >>= 1ll; x = (x * x)%m; } return ans%m;}
template <typename T> T lcm(T a, T b) { return (((a*b)/(gcd(a, b)))); }


int main() {
	FAST_IO;

  int n, m, i, x, j;

  cin >> n >> m;

  vi v(n);
  vi ans(n, MOD);
  vi tmp(n);
  vi tmp1(n);

  fl(i, 0, n){
    cin >> v[i];
    ans[0] = min(v[i], ans[0]);
  }

  tmp = v;

  //Precalculate the LCM on range
  fl(j, 1, n){
    fl(i, 0, n-j){
      tmp1[i] = (int)(lcm<ll>(tmp[i], tmp[i+1]))%MOD;
      ans[j]  = min(ans[j], tmp1[i]);
    }
    tmp = tmp1;
  }


  fl(i, 0, m){
    cin >> x;
    cout << ans[x-1] << endl;
  }
  


	return 0;
}