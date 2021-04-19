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

vi memo;
vi visits;

int dfs(int node, vvi &g, int &l){
  ll count = 0;
  int i, tam = len(g[node]);

  fl(i, 0, tam){
    int act = g[node][i];
    if( act > l-1 ){
      count = (count+1)%MOD;
      visits[act] = 1;
    }
    else{
      if( memo[act] != -1 ) count = (count + memo[act])%MOD;
      else{
        memo[act] = dfs(act, g, l);
        count = (count + memo[act])%MOD;
      }
    }
  }

  return count%MOD;
}

int main() {
	FAST_IO;
  int n, l, i, k, j, aux;

  while(cin >> n >> l){
    vvi g(l);
    memo = vi(l, -1);
    visits = vi(n, 0);
    fl(i, 0, l){
      cin >> k;
      fl(j, 0, k){
        cin >> aux;
        g[i].pb(aux-1);
      }
    }

    int count = dfs(0, g, l);
    int uniques = 0;
    fl(i, 0, len(visits)) if( visits[i] ) uniques++;

    cout << count << " " << uniques << endl;
  }


	return 0;
}