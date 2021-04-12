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

void initString(string &s, int &a, int &b){
  int i, n = s.size();

  fl(i, 0, s.size()){

    if(s[i] != '?' and s[n-i-1] == '?'){
      s[n-i-1] = s[i];

      if(s[i] == '0') a--;
      else b--;
    }
  }
}

void fulfill(string &s, int &a, int &b){
  int i, n = s.size();

  fl(i, 0, s.size()){
    if(s[i] == '?'){
      //s[n-i-1] == '?'
      if(a >= 2){
        s[i] = '0';
        s[n-i-1] = '0';
        a-=2;
      }
      else if(b >= 2){
        s[i] = '1';
        s[n-i-1] = '1';
        b-=2;
      }
      else if(a == 1){
        s[i] = '0';
        a--;
      }
      else if(b == 1){
        s[i] = '1';
        b--;
      }
    }
  }
}

bool validate(string &s, int a, int b){
  int cntA = 0, cntB = 0;
  for(char c : s){
    if(c == '?') return false;
    if(c == '0') cntA++;
    else cntB++;
  }

  string tmp = s;
  reverse(tmp.begin(), tmp.end());

  return cntA == a and cntB == b and tmp == s;
}

int main() {
	FAST_IO;
  int t, a, b;
  string s;

  cin >> t;

  while(t--){
    cin >> a >> b >> s;
    int i = a, j = b;

    for(char c : s){
      if(c == '0') a--;
      if(c == '1') b--;
    }

    initString(s, a, b);
    //cout << s << " " << a << " " << b << endl;
    fulfill(s, a, b);
    //cout << s << " " << a << " " << b << endl;

    if( validate(s, i, j) ){
      cout << s << endl;
    }
    else cout << -1 << endl;
  }


	return 0;
}