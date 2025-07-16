#include <bits/stdc++.h>

using namespace std;

struct Trie {
  bool output;
  Trie *fail, *go[26];

  Trie() : output(false), fail(NULL) { memset(go, NULL, sizeof go); }
  ~Trie() {
    for (int i = 0; i < 26; i++)
      if (go[i]) delete go[i];
  }

  void insert(const string &str) {
    Trie *cur = this;
    for (const auto &ch : str) {
      Trie *&nxt = cur->go[ch - 'a'];
      if (!nxt) nxt = new Trie;
      cur = nxt;
    }
    cur->output = true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  string str;
  Trie *root = new Trie;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> str;
    root->insert(str);
  }

  queue<Trie *> Q;
  root->fail = root;
  Q.push(root);
  while (!Q.empty()) {
    Trie *cur = Q.front();
    Q.pop();

    for (int i = 0; i < 26; i++) {
      Trie *nxt = cur->go[i];
      if (!nxt) continue;

      if (cur == root) {
        nxt->fail = root;
      } else {
        Trie *dst = cur->fail;
        while (dst != root && !dst->go[i]) dst = dst->fail;
        if (dst->go[i]) dst = dst->go[i];
        nxt->fail = dst;
      }

      if (nxt->fail->output) nxt->output = true;
      Q.push(nxt);
    }
  }

  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> str;

    Trie *cur = root;
    bool res = false;
    for (int c = 0; str[c]; c++) {
      while (cur != root && !cur->go[str[c] - 'a']) cur = cur->fail;
      if (cur->go[str[c] - 'a']) cur = cur->go[str[c] - 'a'];
      if (cur->output) {
        res = true;
        break;
      }
    }

    cout << (res ? "YES" : "NO") << '\n';
  }

  delete root;
  return 0;
}