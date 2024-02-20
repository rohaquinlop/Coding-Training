#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

typedef vector<pii> vpii;
typedef vector<pll> vpll;

typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

#define fl(i, a, b) for (int i = a; i < b; ++i)

#define all(v) (v).begin(), (v).end()
#define srt(v) sort(all(v))

#define pb push_back
#define mp make_pair

#define dig(i) (s[i] - '0')
#define slen(s) s.length()

#define fr first
#define sc second

#define len(x) x.size()
#define fill(x, y) memset(x, y, sizeof(x))
#define clr(a) fill(a, 0)
#define endl '\n'

#define PI 3.14159265358979323

#define trace1(x1) cerr << #x1 << ": " << x1 << endl;
#define trace2(x1, x2) \
    cerr << #x1 << ": " << x1 << " | " << #x2 << ": " << x2 << endl;
#define trace3(x1, x2, x3)                                                  \
    cerr << #x1 << ": " << x1 << " | " << #x2 << ": " << x2 << " | " << #x3 \
         << ": " << x3 << endl;

#define FAST_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)

const ll MOD = 1000000007LL;
const ll MAX = 100010LL;

template <typename T>
T gcd(T a, T b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
template <typename T>
T power(T x, T y, ll m = MOD) {
    T ans = 1;
    x %= m;
    while (y > 0) {
        if (y & 1ll) ans = (ans * x) % m;
        y >>= 1ll;
        x = (x * x) % m;
    }
    return ans % m;
}

string generate_pea_pattern(string &s) {
    string ans;
    map<char, int> freq;

    for (char &c : s) freq[c]++;

    for (auto &p : freq) {
        ans += to_string(p.second);
        ans += p.first;
    }

    return ans;
}

string solve(string &n, string &m) {
    int total = 0;
    string current, next;

    queue<string> q;
    map<string, bool> visited;

    q.push(n);
    visited[n] = true;

    while (!q.empty()) {
        total++;
        current = q.front();
        q.pop();

        if (total > 100) return "I'm bored";
        if (current == m) return to_string(total);

        next = generate_pea_pattern(current);

        if (!visited[next]) {
            q.push(next);
            visited[next] = true;
        }
    }

    return "Does not appear";
}

int main() {
    FAST_IO;

    string n, m;

    cin >> n >> m;

    cout << solve(n, m) << endl;

    return 0;
}
