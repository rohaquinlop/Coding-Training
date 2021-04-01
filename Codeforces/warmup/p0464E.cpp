#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int binPow(int a, int b){
  if(b == 0) return 1;
  if(b == 1) return a%MOD;
  else{
    if(b%2 == 0){
      int ans = binPow(a, b/2)%MOD;
      return (ans*ans)%MOD;
    }
    else{
      return ((a%MOD)*(binPow(a, b-1)%MOD))%MOD;
    }
  }
}

void dijkstra(int s, map<int, int>& d, map<int, int>& p, vector<vector<pair<int, int>>>& graph){
  int u, i, v, w;

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, s});
  d[s] = 0;

  while(!pq.empty()){
    u = pq.top().second;
    pq.pop();
    for(i = 0; i < graph[u].size(); ++i){
      v = graph[u][i].first;
      w = binPow(2, graph[u][i].second);
      if( d[v] > (d[u]%MOD+w)%MOD ){
        d[v] = (d[u]%MOD+w)%MOD;
        p[v] = u;
        pq.push({d[v], v});
      }
    }
  }
}

vector<int> restore_path(int s, int t, map<int, int>& p) {
  vector<int> path;
  if( p.find(t) == p.end() || p[t] == -1) return path;

  for (int v = t; v != s; v = p[v])
    path.push_back(v);
  path.push_back(s);

  reverse(path.begin(), path.end());
  return path;
}

int main(){
  FAST_IO;
  int n, m, i, u, v, x, w, s, t;
  vector<vector<pair<int, int>>> graph;

  while(cin >> n >> m){
    graph = vector<vector<pair<int, int>>>(n);
    map<int, int> d, p;

    for(i = 0; i < m; ++i){
      cin >> u >> v >> x;
      u--, v--;

      graph[u].push_back({v, x});
      graph[v].push_back({u, x});
      p[u] = -1;
      p[v] = -1;
      d[u] = MOD;
      d[v] = MOD;
    }
    cin >> s >> t;
    s--, t--;

    vector<int> path;

    dijkstra(s, d, p, graph);
    path = restore_path(s, t, p);

    if(path.size()){
      cout << d[t] << "\n";
      cout << path.size() << "\n";
      for(i = 0; i < path.size(); ++i){
        cout << path[i]+1;
        if(i < path.size()-1) cout << " ";
      }
      cout << "\n";
    }
    else cout << "-1\n";
  }

  return 0;
}