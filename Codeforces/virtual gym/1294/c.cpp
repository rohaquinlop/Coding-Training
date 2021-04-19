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

#define fl(i, a, b)	for (int i = a; i < b; ++i)

#define all(v) 	(v).begin(), (v).end()
#define srt(v)	sort (all (v))

#define pb push_back
#define mp make_pair

#define dig(i)	(s[i] - '0')
#define slen(s)	s.length()

#define fr first
#define sc second

#define len(x) x.size()
#define fill(x, y)	memset(x, y, sizeof(x))
#define clr(a)	fill(a, 0)
#define endl '\n'

#define PI 3.14159265358979323

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

const ll MOD = 1000000007LL;
const ll MAX = 100010LL;

template <typename T> T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T power(T x, T y, ll m = MOD) { T ans = 1; x %= m; while (y > 0) { if (y & 1ll) ans = (ans * x) % m; y >>= 1ll; x = (x * x)%m; } return ans%m;}

int main() {
	FAST_IO;
  int t, n, m, i, j;

  cin >> t;

  while(t--){
    cin >> n;
    int m = n;
    vi v(3, 2);
    i = 0;

    while(n > 1 and i < 3 and n >= v[i]){
      if( n%v[i] == 0 ){
        n /= v[i];
        v[i+1] = v[i]+1;
        i++;
      }
      else v[i]++;
    }

    if( v[0] != v[1] and v[0] != v[2] and v[1] != v[2] and v[0]*v[1]*v[2] == m){
      cout << "YES" << endl;
      cout << v[0] << " " << v[1] << " " << v[2] << endl;
    }
    else cout << "NO" << endl;
  }

	return 0;
}