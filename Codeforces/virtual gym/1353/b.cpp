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

int getMinPos(vector<int> &v, int n){
  int i, x=0, minVal = 31;
  fl(i, 0, n){
    if(v[i] < minVal){
      minVal = v[i];
      x = i;
    }
  }
  return x;
}

int getMaxPos(vector<int> &v, int n){
  int i, x=0, maxVal = 0;
  fl(i, 0, n){
    if(v[i] > maxVal){
      maxVal = v[i];
      x = i;
    }
  }
  return x;
}

int main() {
	FAST_IO;
  int t, n, k, i, j;
  cin >> t;

  while(t--){
    cin >> n >> k;
    vi a(n);
    vi b(n);
    fl(i, 0, n) cin >> a[i];
    fl(i, 0, n) cin >> b[i];

    //Consultar posición del mínimo elemento
    while(k--){
      i = getMinPos(a, n);
      j = getMaxPos(b, n);
      if(a[i] < b[j]){
        int aux = a[i];
        a[i] = b[j];
        b[j] = aux;
      }
      else{
        break;
      }
    }
    int res = 0;
    for(int x : a) res += x;
    cout << res << "\n";
  }


	return 0;
}