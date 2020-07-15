/*
* Implementación del algoritmo de Tarjan
* Este algoritmo cuenta la cantidad de SCC´s en un grafo
* Lo que hace es hacer un toposort y despues empieza a desapilar los elementos
*/
#include<bits/stdc++.h>

using namespace std;

int SCC = 0;
vector<int>visited1;
vector<int>visited2;
vector<vector<int>>graph;
vector<vector<int>>graphT;
vector<vector<int>>sccNodes;
vector<int> nodeSCC;
vector<int> SCCVal;
stack<int> pila;

void DFS1(int n){
  visited1[n] = 1;
  for(int i = 0; i < graph[n].size(); ++i){
    if( !visited1[graph[n][i]] ) DFS1( graph[n][i] );
  }
  pila.push(n);
}

void DFS2(int n){
  visited2[n] = 1;
  for(int i = 0; i < graphT[n].size(); ++i){
    if( !visited2[graphT[n][i]] ) DFS2( graphT[n][i] );
  }
  sccNodes[SCC].push_back(n);
  nodeSCC[n] = SCC;
}

void Kosaraju(){
  int node;
  for(int i = 0; i < graph.size(); ++i){
    if(!visited1[i]) DFS1(i);
  }

  while (!pila.empty()){
    node = pila.top();
    pila.pop();
    if(!visited2[node]){
      DFS2(node);
      ++SCC;
    }
  }
}

vector<vector<int>> getTranspose(vector<vector<int>> g){
  vector<vector<int>> T(g.size());
  for(int i = 0; i < g.size(); ++i){
    for(int j = 0; j < g[i].size(); ++j){
      int node = g[i][j];
      T[node].push_back(i);
    }
  }
  return T;
}

int dfs3(int n, vector<int> &visited){
  visited[nodeSCC[n]] = 1;
  int res = sccNodes[nodeSCC[n]].size();
  unordered_set<int> s;
  for(int i = 0; i < graph[n].size(); ++i){
    int node = graph[n][i];
    if( nodeSCC[node] != nodeSCC[n] ){
      s.insert(node);
    }
  }
  for(int i : s){
    if(SCCVal[nodeSCC[i]] == 0){
      SCCVal[nodeSCC[i]] = dfs3(i, visited);
    }
    res += SCCVal[nodeSCC[i]];
  }
  return res;
}

int main(){
  int n, m, i, j, l, t;

  cin >> t;

  while(t--){
    cin >> n >> m;
    graph = vector<vector<int>>(n, vector<int>(0));

    for(i = 0; i < m; ++i){
      cin >> j >> l;
      graph[j-1].push_back(l-1);
    }

    graphT = getTranspose(graph);
    sccNodes = vector<vector<int>>(n);
    visited1 = vector<int>(n, 0);
    visited2 = vector<int>(n, 0);
    nodeSCC = vector<int>(n, -1);
    Kosaraju();

    SCCVal = vector<int>(SCC+1, 0);
    vector<int> visitedSCC(SCC+1, -1);
    int maxVal = -1;

    for(i = 0; i < n; ++i){
      if( visitedSCC[nodeSCC[i]] == -1 ){
        SCCVal[nodeSCC[i]] = dfs3(i, visitedSCC);
      }
    }
    for(int i : SCCVal){
      maxVal = max(i, maxVal);
    }
    cout << maxVal << "\n";
  }

  return 0;
}