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

int dx[] = {1, 0};
int dy[] = {0, 1};
char m[] = {'E', 'S'};

class Point{
public:
  int x;
  int y;
  int s = 0;
  string a;

  Point( int vX, int vY, string vA, int vS){
    this->x = vX;
    this->y = vY;
    this->a = vA;
    this->s = vS;
  }
};

map< pair<int, int>, pair<int, int> > getPath(string s){
  map< pair<int, int>, pair<int, int> >m;
  int x = 0, y = 0, i;
  fl(i, 0, len(s)){
    if( s[i] == 'S' ){
      pii a = mp(x, y);
      pii b = mp(x, y+1);
      m[a] = b;
      y++;
    }
    else{
      pii a = mp(x, y);
      pii b = mp(x+1, y);
      m[a] = b;
      x++;
    }
  }
  return m;
}

int main() {
	FAST_IO;
  int t, n, c = 0, i;
  string line;

  cin >> t;

  while(t--){
    c++;
    cin >> n;
    cin >> line;
    string res;
    queue<Point> cola;
    vvi visited(n, vector<int>(n, 0));
    map< pair<int, int>, pair<int, int> > path = getPath(line);
    cola.push( Point(0, 0, "", 0) );

    while(!cola.empty()){
      Point node = cola.front(); cola.pop();
      pii a = mp(node.x, node.y);
      //Validate if it's in the end of the graph
      if( node.x == n-1 and node.y == n-1 ){
        if( node.a != line and len(node.a) == 2*n-2 ){
          res = node.a;
          break;
        }
      }
      else{
        fl(i, 0, 2){
          int x = node.x+dx[i];
          int y = node.y+dy[i];
          string aux = node.a+m[i];
          pii b = mp(x, y);

          //Validate it doesn't exceed the string length
          if( x <= n-1 and y <= n-1 and len(aux) <= 2*n-2 and path[a] != b){
            cola.push( Point(x, y, aux, node.s+1) );
          }
        }
      }
    }

    cout << "Case #" << c << ": " << res << endl;
  }
	return 0;
}