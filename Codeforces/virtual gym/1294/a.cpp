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

int minNum(vi &v){
	int m = v[0];
	int i;
	fl(i, 0, len(v)) if( v[i] < m ) m = v[i];
	return m;
}

int maxNum(vi &v){
	int m = v[0];
	int i;
	fl(i, 0, len(v)) if( v[i] > m ) m = v[i];
	return m;
}

int main() {
	FAST_IO;
	ll a, b, c;
	ll t, n, m, i, j;

	cin >> t;

	while(t--){
		cin >> a >> b >> c >> n;
		vll nums(3);
		nums[0] = a;
		nums[1] = b;
		nums[2] = c;
		srt(nums);

		ll diff1 = nums[2]-nums[0];
		ll diff2 = nums[2]-nums[1];

		if( n < diff1+diff2 ) cout << "NO" << endl;
		else{
			n -= (diff1+diff2);
			if( n%3 == 0 ) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}


	return 0;
}