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

int main(){
  int n, k, i, j, l;
  cin >> n >> k;
  graph = vector<vector<int>>(n, vector<int>(0));

  for(i = 0; i < k; ++i){
    cin >> j >> l;
    graph[j].push_back(l);
  }

  graphT = getTranspose(graph);
  sccNodes = vector<vector<int>>(n);
  visited1 = vector<int>(n, 0);
  visited2 = vector<int>(n, 0);
  Kosaraju();

  cout << "Total SCC´s: " << SCC << "\n";

  //Printing SCC´s
  for(i = 0; i < SCC; ++i){
    cout << "SCC #" << i+1 << ": ";
    for(j = 0; j < sccNodes[i].size(); ++j){
      cout << sccNodes[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}