#include<bits/stdc++.h>

using namespace std;

class State{
public:
  int n;
  int lastVal;
  vector<int> numbers;
  vector<int> visited;

  State(int a, vector<int> b, vector<int> c, int d){
    this->n = a;
    this->numbers = b;
    this->visited = c;
    this->lastVal = d;
  }
};

void solve(int x){
  int i;
  queue<State> states;
  vector<int> ans;

  states.push(State(x, vector<int>(), vector<int>(10, 0), 0));

  while(!states.empty()){
    State s = states.front();
    states.pop();

    if(s.n == 0){
      ans = s.numbers;
      break;
    }

    for(i = s.lastVal+1; i < 10; ++i){
      if( s.n-i >= 0 and !s.visited[i-1] ){
        s.numbers.push_back(i);
        s.visited[i-1] = 1;
        states.push( State(s.n-i, s.numbers, s.visited, i) );
        s.numbers.pop_back();
        s.visited[i-1] = 0;
      }
    }
  }

  if(ans.size()){
    //sort(ans.begin(), ans.end());
    for(int i : ans) cout << i;
    cout << "\n";
  }else cout << "-1\n";
}

int main(){
  int t, x;
  cin >> t;

  while(t--){
    cin >> x;
    solve(x);
  }
  

  return 0;
}