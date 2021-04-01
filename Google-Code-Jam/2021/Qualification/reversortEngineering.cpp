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

int reverSortCost(vector<int> v){
  int ans = 0, j;
  vector<int>::iterator it;

  for(int i = 0; i < v.size(); i++){
    it = min_element(v.begin()+i, v.end());

    for(int k = v.size()-1; k >= 0; k--){
      if( v[k] ==  *it){
        j = k;
        break;
      }
    }

    reverse(v.begin()+i, v.begin()+j+1);
    ans += (j-i)+1;
  }

  return ans-1;
}

int main() {
	FAST_IO;
  int t, n, c, cases = 0;

  cin >> t;

  while(t--){
    cin >> n >> c;
    cases++;

    vector<int> v(n), ans(n);
    for(int i = 0; i < n; i++) v[i] = i+1;

    cout << "Case #" << cases << ":";

    if( c < n-1 or c > ((n*(n+1))/2)-1 ){
      cout << " IMPOSSIBLE" << endl;
    }
    else{
      //cout << "n: " << n << " c: " << c << endl;
      do{
        int cost = reverSortCost(v);
        //cout << cost << endl;
        if( cost == c ){
          ans = v;
          break;
        }
      }while( next_permutation(v.begin(), v.end()) );
      //cout << endl;

      if( ans[0] != 0){
        for(int i = 0; i < n; i++)
          cout << " " << ans[i];
        cout << endl;
      }
      else{
        cout << " IMPOSSIBLE" << endl;
      }
    }

  }

	return 0;
}