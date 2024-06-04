#include <iostream>
#include <vector>
using namespace std;

struct node {
  int val = 1;
  vector<int> edge;
};

vector<node> vortexs;

int gcd(int a, int b) {
  if (a < b) swap(a, b);

  while (b > 0) {
    int temp = a;
    a = b;
    b = temp % a;
  }

  return a;
}

void dfs(vector<bool> &isVisit, int index, int value) {
  isVisit[index] = true;
  vortexs[index].val *= value;

  for (int e : vortexs[index].edge) {
    if (!isVisit[e]) {
      dfs(isVisit, e, value);
    }
  }
}

int main(void) {
  int N;
  cin >> N;

  vortexs.resize(N);
  for (int i = 1; i < N; i++) {
    int a, b, p, q;
    cin >> a >> b >> p >> q;

    int gcdVal = gcd(p, q);

    int modA = vortexs[b].val * p / gcdVal;
    int modB = vortexs[a].val * q / gcdVal;
    gcdVal = gcd(modA, modB);

    vector<bool> isVisit(N);
    dfs(isVisit, a, modA / gcdVal);
    dfs(isVisit, b, modB / gcdVal);

    vortexs[a].edge.push_back(b);
    vortexs[b].edge.push_back(a);
  }

  for (auto v : vortexs) {
    cout << v.val << ' ';
  }

  return 0;
}