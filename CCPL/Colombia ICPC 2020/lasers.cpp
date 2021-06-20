#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<vi> vvi;
typedef vector<vc> vvc;

char direction(char actD, char mirror) {
  if (actD == 'U') {
    if (mirror == '/') return 'R';
    else return 'L';
  }

  if (actD == 'D') {
    if (mirror == '/') return 'L';
    else return 'R';
  }

  if (actD == 'R') {
    if (mirror == '/') return 'U';
    else return 'D';
  }

  if (actD == 'L') {
    if (mirror == '/') return 'D';
    else return 'U';
  }
}

void moveSim(char mov, int& r, int& c) {
  if (mov == 'R') c++;
  else if (mov == 'L') c--;
  else if (mov == 'U') r--;
  else r++;
}

int solve(vvc& graph, int R, int C) {
  vvi visited(R + 1, vi(C + 1, 0));

  //Primera parte
  int r = 0, c = 0;
  char actD = 'R';

  while (r >= 0 and r < R and c >= 0 and c < C) {
    if (graph[r][c] == '.') {
      visited[r][c] += 2;
      moveSim(actD, r, c);
    }
    else {
      actD = direction(actD, graph[r][c]);
      moveSim(actD, r, c);
    }
  }

  if (r == R - 1 and c == C) return 1;

  r = R - 1, c = C - 1;
  actD = 'L';
  while (r >= 0 and r < R and c >= 0 and c < C) {
    if (graph[r][c] == '.') {
      visited[r][c] += 3;
      if (visited[r][c] % 5 == 0) return 2;

      moveSim(actD, r, c);
    }
    else {
      actD = direction(actD, graph[r][c]);
      moveSim(actD, r, c);
    }
  }

  return 3;
}

int main() {
  int R, C;

  while (cin >> R >> C and R and C) {
    vvc graph(R + 1, vc(C + 1));

    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) cin >> graph[i][j];
    }

    int ans = solve(graph, R, C);

    if (ans == 1) cout << "It works\n";
    else if (ans == 2) cout << "I can fix it\n";
    else cout << "Send help\n";
  }
}