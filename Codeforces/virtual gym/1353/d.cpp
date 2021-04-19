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

pii getPos(vi &v, int n){
  int maxVal = -1;
  pii res;
  for(int i = 0; i < v.size(); i++){
    if(i == 0 and v[i] != 1){
      if(v[i]-1 > maxVal){
        maxVal = v[i]-1;
        res = {1, v[i]};
      }
    }
    if(i == v.size()-1){
      if(n-v[i] > maxVal){
        maxVal = n-v[i];
        res = {v[i], n};
      }
    }
    if(v[i]-v[i+1] > maxVal and i < v.size()-1){
      maxVal = v[i]-v[i+1];
      res = {v[i+1], v[i]};
    }
  }
  return res;
}

int main() {
	FAST_IO;
  int n, i, t, j;
  cin >> t;

  while(t--){
    cin >> n;
    vi v(n, 0);
    vi pos;
    int l = 1, r = n;
    pii nums;

    for(i = 0; i < n; ++i){
      int p = r-l+1;
      cout << l << " " << r << " " << p << "\n";
      if(p%2 != 0){
        //es impar
        j = (l+r)/2;
        cout << j << "\n";
        v[j-1] = i+1;
        pos.push_back(j);
      }
      else{
        j = (l+r-1)/2;
        cout << j << "\n";
        v[j-1] = i+1;
        pos.push_back(j);
      }
      sort(pos.begin(), pos.end());
      nums = getPos(pos, n);
      l = nums.first, r = nums.second;
    }

    fl(i, 0, n){
      cout << v[i];
      if(i < n-1) cout << " ";
    }
    cout << "\n";
    cout << "- - - - -\n";
  }


	return 0;
}