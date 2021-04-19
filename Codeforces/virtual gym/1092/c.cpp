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

bool cmp(string &a, string &b){
  return len(a) < len(b);
}

vi used;

int position(vs &pos, string n){
  int i;
  int fake;
  fl(i, 0, len(pos)){
    if( pos[i] == n and !used[i]){
      used[i] = 1;
      return i;
    }
  }
  return 0;
}

int main() {
	FAST_IO;
  int t;
  int n, k, i, j;
  string a;

  while(cin >> n){
    used = vi(200, 0);
    vs w(2*n-2);
    string l = "";
    fl(i, 0, 2*n-2) cin >> w[i];
    vs aux = w;
    sort(aux.begin(), aux.end(), cmp);
    map<string, int> m;
    map<string, vi> vals;
    i = 0;
    k = 2*(n-1)-1;
    while(i < n-1){
      a = aux[i]+aux[k];
      m[a]++;
      int p1 = position(w, aux[i]);
      int p2 = position(w, aux[k]);
      vals[a].pb(p1);
      vals[a].pb(p2);
      a = aux[k]+aux[i];
      vals[a].pb(p2);
      vals[a].pb(p1);
      m[a]++;
      i++;
      k--;
    }
    int max = 1;
    string a = "";
    for(auto it : m){
      if( it.second > max ){
        max = it.second;
        a = it.first;
      }
    }

    // cout << a << endl;

    if( a == "" ){
      //funciona cualquiera
      bool p = false;
      fl(i, 0, 2*(n-1)){
        if(p) cout << 'P';
        else cout << 'S';
        p = !p;
      }
      cout << endl;
    }
    else{
      // i = vals[a][0];
      // k = vals[a][1];
      bool p = true;
      vi res(2*(n-1), 0);
      vi nums = vals[a];
      int tam = len(nums);
      j = 0;
      while(j < tam){
        i = nums[j];
        k = nums[j+1];
        res[i] = 1;
        res[k] = 2;
        j += 2;
      }
      fl(i, 0, 2*(n-1)){
        if( res[i] == 1 ) cout << 'P';
        else if( res[i] == 2 ) cout << 'S';
        else{
          if(p) cout << 'P';
          else cout << 'S';
          p = !p;
        }
      }
      cout << endl;
    }
  }


	return 0;
}