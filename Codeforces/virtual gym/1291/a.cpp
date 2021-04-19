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

int sumD(string &s){
  int i, cnt = 0;

  fl(i, 0, len(s)) if( s[i] != 'a' ) cnt += s[i]-'0';

  return cnt;
}

string removeLastDigit(string s){
  int i = len(s)-1;
  int n = s[i]-'0';

  while(n%2 == 0 and i >= 0){
    s[i] = 'a';
    i--;
    n = s[i]-'0';
  }
  string aux = "";
  for(char c : s){
    if( c != 'a' ) aux += c;
    else break;
  }
  return aux;
}

int main() {
	FAST_IO;
  int t, n, i, v, lastD;
  string num;

  cin >> t;

  while(t--){
    cin >> n;
    cin >> num;
    if( n == 1 ) cout << "-1" << endl;
    else{
      num = removeLastDigit(num);
      v = sumD(num);
      int cnt = 0;

      while(v%2 != 0 and n > cnt){
        fl(i, 0, n-1){
          if( num[i] != 'a' ){
            int j = num[i]-'0';
            if( j%2 == v%2 ){
              num[i] = 'a';
              cnt++;
              v -= j;
              break;
            }
          }
        }
      }

      if( v%2 == 0 and n > cnt){
        string aux = "";
        for( char c : num) if(c != 'a') aux += c;
        if( aux[len(aux)-1]%2 != 0 ) cout << aux << endl;
        else cout << "-1" << endl;
      }
      else cout << "-1" << endl;
    }

  }


	return 0;
}