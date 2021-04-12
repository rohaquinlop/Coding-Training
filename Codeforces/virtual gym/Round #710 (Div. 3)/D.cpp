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

int solve(map<int, int>& cnt){
  map<int, int> m;
  priority_queue<pii> pq;
  pii p1, p2;
  int diff, ans = 0;

  for(auto &t : cnt){
    m[t.second]++;
  }

  for(auto &t : cnt){
    if( m[t.second] < 2) pq.push({t.second, t.first});
  }

  while(pq.size() > 1){
    p1 = pq.top();
    pq.pop();
    p2 = pq.top();
    pq.pop();

    diff = p1.first-p2.first;

    if(diff > 0) pq.push({diff, p1.second});
  }

  while(!pq.empty()){
    p1 = pq.top();
    pq.pop();

    ans += p1.first;
  }

  return ans;
}

int main() {
	FAST_IO;
  int t, n, i;

  cin >> t;

  while(t--){
    cin >> n;
    vi v(n);
    map<int, int> cnt;

    fl(i, 0, n){
      cin >> v[i];
      cnt[v[i]]++;
    }

    if( cnt.size() == 1 )
      cout << cnt.begin()->second << endl;
    else
      cout << solve(cnt) << endl;
  }


	return 0;
}