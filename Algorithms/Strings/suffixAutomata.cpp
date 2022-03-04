struct state {
  int len, link;
  map<char, int> next;
};

const int MAXLEN = 100000;
state st[MAXLEN * 2];
int sz, last;

void sa_init() {
  st[0].len = 0;
  st[0].link = -1;
  sz++;
  last = 0;
}

void sa_extend(char& c) {
  int cur = sz++;
  st[cur].len = st[last].len + 1;
  int p = last;
  while (p != -1 && !st[p].next.count(c)) {
    st[p].next[c] = cur;
    p = st[p].link;
  }
  if (p == -1) {
    st[cur].link = 0;
  }
  else {
    int q = st[p].next[c];
    if (st[p].len + 1 == st[q].len) {
      st[cur].link = q;
    }
    else {
      int clone = sz++;
      st[clone].len = st[p].len + 1;
      st[clone].next = st[q].next;
      st[clone].link = st[q].link;
      while (p != -1 && st[p].next[c] == q) {
        st[p].next[c] = clone;
        p = st[p].link;
      }
      st[q].link = st[cur].link = clone;
    }
  }
  last = cur;
}

//Find if T is a substring of S
bool isSubString(string S, string T) {
  bool ans = true;
  //En este caso se crea el automata en la funcion, en caso de que se necesite usar varias veces para verificar sobre el mismo string S crear el automata solo una vez antes de llamar la funcion
  sa_init();
  for (int i = 0; i < S.length(); i++) sa_extend(S[i]);

  int cur = 0;
  for (int i = 0; i < T.length() and ans; i++) {
    if (st[cur].next.count(T[i])) {
      cur = st[cur].next[T[i]];
    }
    else {
      ans = false;
    }
  }

  return ans;
}

//Longest common substring of two strings
string lcs(string S, string T) {
  sa_init();
  for (int i = 0; i < S.size(); i++)
    sa_extend(S[i]);

  int v = 0, l = 0, best = 0, bestpos = 0;
  for (int i = 0; i < T.size(); i++) {
    while (v && !st[v].next.count(T[i])) {
      v = st[v].link;
      l = st[v].length;
    }
    if (st[v].next.count(T[i])) {
      v = st[v].next[T[i]];
      l++;
    }
    if (l > best) {
      best = l;
      bestpos = i;
    }
  }
  return t.substr(bestpos - best + 1, best);
}