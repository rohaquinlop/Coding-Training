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

int main() {
	FAST_IO;
  ll a, b, i, j;

  while(cin >> a >> b){
    map<ll, ll> visited;
    map<ll, ll> route;
    queue<ll> cola;
    visited[a] = true;
    cola.push(a);
    bool flag = false;

    while(!cola.empty()){
      i = cola.front();
      cola.pop();

      //cout << i << endl;

      if(i == b){
        flag = true;
        break;
      }

      j = 2*i;
      if( j <= b and !visited[j]){
        cola.push(j);
        route[j] = i;
        visited[j] = 1;
      }
      j = 10*i+1;
      if( j <= b and !visited[j]){
        cola.push(j);
        route[j] = i;
        visited[j] = 1;
      }
    }

    if( !flag ) cout << "NO\n";
    else{
      int k = 0;
      i = b;
      vi v;

      while(i != a){
        v.push_back(i);
        i = route[i];
      }
      v.push_back(a);

      cout << "YES\n" << v.size() << "\n";

      for(i = v.size()-1; i >= 0; --i){
        cout << v[i];
        if(i > 0) cout << " ";
      }
      cout << "\n";
    }
  }


	return 0;
}