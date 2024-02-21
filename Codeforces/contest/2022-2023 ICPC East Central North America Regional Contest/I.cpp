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

const int INF = 1000000000;

void dijkstra(int s, vector<vpii> &graph, vi &d, vector<vpii> &p) {
    int n = len(graph);
    d.assign(n, INF);
    p = vector<vpii>(n);
    vector<bool> u(n, false);

    d[s] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!u[j] && (v == -1 || d[j] < d[v])) v = j;
        }

        if (d[v] == INF) break;

        u[v] = true;
        for (pii &edge : graph[v]) {
            int to = edge.first;
            int l = edge.second;

            if (d[v] + l < d[to]) {
                d[to] = d[v] + l;
                p[to] = vpii();
                p[to].push_back({v, l});
            }

            if (d[v] + l == d[to]) {
                d[to] = d[v] + l;
                p[to].push_back({v, l});
            }
        }
    }
}

int main() {
    FAST_IO;

    int n, m, a, b, j, k, l, total = 0;
    int v, u;

    cin >> n >> m >> a >> b;

    vector<vpii> graph(n);
    vi d;
    vector<vpii> p;

    fl(i, 0, m) {
        cin >> j >> k >> l;
        total += l;

        graph[j - 1].pb({k - 1, l});
        graph[k - 1].pb({j - 1, l});
    }

    dijkstra(a - 1, graph, d, p);

    queue<int> q;
    q.push(b - 1);
    map<pii, bool> visited;

    while (!q.empty()) {
        v = q.front();
        q.pop();

        for (pii &e : p[v]) {
            if (!visited[{v, e.fr}]) {
                total -= e.sc;
                q.push(e.fr);
                visited[{v, e.fr}] = true;
            }
        }
    }

    cout << total << endl;

    return 0;
}
