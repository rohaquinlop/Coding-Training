#include<bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
string moveC = "NSEW";

long long binpow(long long a, long long b) {
  if (b == 0)
    return 1;
  long long res = binpow(a, b / 2);
  if (b % 2)
    return res * res * a;
  else
    return res * res;
}

class Dot{
public:
  long long x;
  long long y;
  long long j;
  string path;

  Dot(long long a, long long b, long long c, string s){
    this->x = a;
    this->y = b;
    this->j = c;
    this->path = s;
  }
};

int main(){
  FAST_IO;
  int t, c=0;
  long long x, y, nx, ny, j, tmp;
  string aux;
  map< pair<long long, long long>, int> visited;

  cin >> t;

  while(t--){
    c++;
    cin >> x >> y;
    pair<long long, long long> p;

    //Do BFS
    queue<Dot> cola;
    cola.push( Dot(0, 0, 0, "") );
    p = {0, 0};
    visited[p] = 1;
    bool flag = false;

    cout << "Case #" << c << ": ";

    if( (abs(x)+abs(y))%2 != 0 ){
      while(!cola.empty()){
        nx = cola.front().x;
        ny = cola.front().y;
        j = cola.front().j;
        aux = cola.front().path;

        if( nx == x and ny == y ){
          flag = true;
          break;
        }

        cola.pop();

        for(int i = 0; i < 4; ++i){
          tmp = binpow(2, j);
          p = {nx+(dx[i]*tmp), ny+(dy[i]*tmp)};
          if( visited[p] != 1 ){
            visited[p] = 1;
            cola.push( Dot(nx+(dx[i]*tmp), ny+(dy[i]*tmp), j+1, aux+moveC[i]) );
          }
        }
      }
      cout << aux << "\n";
    }
    else cout << "IMPOSSIBLE\n";
    visited.clear();

  }



  return 0;
}