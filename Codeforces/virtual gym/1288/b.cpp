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

ll conc(int a, int b){
	int res = b;
	while(res > 0){
		res /= 10;
		a *= 10;
	}
	return a + b;
}

ll calc(int a, int b){
	return (a*b) + a + b;
}

int main() {
	FAST_IO;
	ll cases, i, j, k, l, n, m, a, b;
	ll cnt;

	cin >> cases;

	while(cases--){
		cin >> a >> b;
		cnt = 0;

		i = 9;
		while(i <= b){
			cnt++;
			i *= 10;
			i += 9;
		}
		cout << a*cnt << endl;
	}

	return 0;
}