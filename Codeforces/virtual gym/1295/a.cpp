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

int maxEven(int n2, int n4, int n6){
	if( n2 > n4 and n2 > n6  ) return 2;
	if( n4 > n2 and n4 > n6 ) return 4;
	if( n6 > n2 and n6 > n4 ) return 6;
	else{
		if( n2 == n4 and n2 == n6 ){
			if( n4 > n6 ) return 4;
			return 6;
		}
		if( n4 == n2 and n4 == n6){
			if( n2 > n6 ) return 6;
			return 2;
		}
		if( n6 == n2 and n6 == n4 ){
			if( n2 > n4 ) return 2;
			return 4;
		}
	}
}

int maxOdd(int n3, int n5, int n7){
	if( n3 > n5 and n3 > n7  ) return 2;
	if( n5 > n3 and n5 > n7 ) return 4;
	if( n7 > n3 and n7 > n5 ) return 6;
	else{
		if( n3 == n5 and n3 == n7 ){
			if( n5 > n7 ) return 4;
			return 6;
		}
		if( n5 == n3 and n5 == n7){
			if( n3 > n7 ) return 6;
			return 2;
		}
		if( n7 == n3 and n7 == n5 ){
			if( n3 > n5 ) return 2;
			return 4;
		}
	}
}

int main() {
	FAST_IO;
	int t, n, i, num, j;
	map<int, string> m;
	m[2] = "1";
	m[3] = "7";
	m[4] = "4";
	m[5] = "9";
	m[6] = "6";
	m[7] = "8";

	cin >> t;

	while(t--){
		cin >> n;
		string res = "";
		while(n > 1){
			if( n%2 == 0 ){
				int n2 = n/2, n4 = n/4, n6 = n/6;
				num = maxEven(n2, n4, n6);
				if( num == 2) j = n2;
				if(num == 4) j = n4;
				if(num == 6) j = n6;
				string aux = m[num];

				fl(i, 0, j){
					res += aux;
				}
				n -= num*j;
			}
			else{
				if( n%3 == 0  and n%5 == 0 and n%7 == 0 ){
					//
					int n3 = n/3, n5 = n/5, n7 = n/7;
					num = maxOdd(n3, n5, n7);
					if( num == 3) j = n3;
					if(num == 5) j=n5;
					if(num == 7) j=n7;
					string aux = m[num];

					fl(i, 0, j){
						res += aux;
					}
					n -= num*j;
				}
				else if( n%3 == 0 and n%5 == 0 ){
					//
					int n3 = n/3, n5 = n/5;
					num = maxOdd(n3, n5, -1);
					if( num == 3) j = n3;
					if(num == 5) j = n5;
					string aux = m[num];

					fl(i, 0, j){
						res += aux;
					}
					n -= num*j;
				}
				else if( n%3 == 0 and n%7 == 0 ){
					//
					int n3 = n/3, n7 = n/7;
					num = maxOdd(n3, -1, n7);
					if( num == 3) j = n3;
					if(num == 7) j = n7;
					string aux = m[num];

					fl(i, 0, j){
						res += aux;
					}
					n -= num*j;
				}
				else if( n%5 == 0 and n%7 == 0 ){
					//
					int n5 = n/5, n7 = n/7;
					num = maxOdd(-1, n5, n7);
					if(num == 5) j=n5;
					if(num == 7) j=n7;
					string aux = m[num];

					fl(i, 0, j){
						res += aux;
					}
					n -= num*j;
				}
				else if( n%3 == 0 ){
					//
					j = n/3;
					string aux = m[3];
					fl(i, 0, j) res += aux;

					n -= j*3;
				}
				else if( n%5 == 0 ){
					//
					j = n/5;
					string aux = m[5];
					fl(i, 0, j) res += aux;

					n -= j*5;
				}
				else if( n%7 == 0 ){
					//
					j = n/7;
					string aux = m[7];
					fl(i, 0, j) res += aux;

					n -= j*7;
				}
				else{
					n--;
				}
			}
		}

		reverse(res.begin(), res.end());

		cout << res << endl;
	}

	return 0;
}