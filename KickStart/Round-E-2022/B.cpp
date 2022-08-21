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

#define trace1(x1)					cerr << #x1 << ": " << x1 << endl;
#define trace2(x1, x2)				cerr << #x1 << ": " << x1 << " | " << #x2 << ": " << x2 << endl;
#define trace3(x1, x2, x3)			cerr << #x1 << ": " << x1 << " | " << #x2 << ": " << x2 << " | " << #x3 << ": " << x3 << endl;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

const ll MOD = 1000000007LL;
const ll MAX = 100010LL;

template <typename T> T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T power(T x, T y, ll m = MOD) { T ans = 1; x %= m; while (y > 0) { if (y & 1ll) ans = (ans * x) % m; y >>= 1ll; x = (x * x)%m; } return ans%m;}



int main() {
	FAST_IO;
  int t, n, c = 0, i, r;

  cin >> t;

  while(t--){
    c++;
    cin >> n;

    vi v(n), tmp;
    map<int, int> cnt;

    for(int &x : v){
      cin >> x;
      cnt[x] += 1;
      tmp.push_back(x);
    }

    srt(tmp);

    cout << "Case #" << c << ": ";

    for(int j = 0; j < len(v); j++){
      int x = v[j];
      i = lower_bound(tmp.begin(), tmp.end(), 2*x) - tmp.begin()-1;

      if( i < n-1 and tmp[i+1] <= 2*x) i++;

      if( x == tmp[i] ){
        if(cnt[x] > 1) cout << x;
        else{
          if( i > 0) cout << tmp[i-1];
          else cout << -1;
        };
      }
      else{
        cout << tmp[i];
      }

      if(j < len(v)-1) cout << " ";
    }
    cout << endl;
  }


	return 0;
}