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

int dx[] = {0,1,1,0};
int dy[] = {1,1,-1,-1};

int main() {
	FAST_IO;
  int n, q, r, c;
  int i;

  while(cin >> n >> q){
    vector<vector<int>> maze(2, vector<int>(n, 1));
    fl(i, 0, q){
      cin >> r >> c;
      if( maze[r-1][c-1] ) s.insert( {r, c} );
      else s.erase( {r, c} );
      // for(auto x : s) cout << "{" << x.first << ":" << x.second << "}" << endl;
      maze[r-1][c-1] = !maze[r-1][c-1];
      if( isPossible(maze, s, n) ) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
  }


	return 0;
}