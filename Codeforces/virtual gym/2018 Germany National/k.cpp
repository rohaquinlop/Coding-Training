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

class Employee{
public:
  string n;
  int s;
  Employee(string n, int s){
    this->n = n;
    this->s = s;
  }

  bool operator <(const Employee &e){
    return this->s > e.s;
  }
};

int main() {
	FAST_IO;
  int n, d, k, i, j;
  string line;

  while(cin >> n >> d >> k){
    int cant = 0;
    int fired = 0;
    vector<Employee> v;
    fl(i, 0, n){
      cin >> line;
      cin >> j;
      v.pb( Employee(line, j)  );
    }

    sort(v.begin(), v.end());

    vs res;
    bool f = false;

    fl(i, 0, n){
      line = v[i].n;
      j = v[i].s;
      cant += j;
      fired++;
      res.pb(line);
      if( cant >= d and fired <= k ){
        f = true;
        break;
      }
      else if(fired == k and cant < d) break;
    }

    if( f ){
      cout << len(res) << endl;
      fl(i, 0, len(res)){
        cout << res[i] << ", YOU ARE FIRED!" << endl;
      }
    }
    else{
      cout << "impossible" << endl;
    }
  }

	return 0;
}