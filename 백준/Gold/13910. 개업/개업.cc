#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

vector<int> dp;
vector<int> vec;
unordered_set<int> set;

int func(int n) {
  if(dp[n] == 0) {
    if (set.find(n) != set.end()) {
      dp[n] = 1;
    } else {
      int minValue = INT32_MAX;

      for (int item : vec) {
        if (n > item && func(n - item) != -1){
          minValue = min(minValue, func(n - item));
        }
      }

      if(minValue == INT32_MAX) {
        dp[n] = -1;
      } else {
        dp[n] = minValue + 1;
      }
    }
  } 
  return dp[n];
}

int main(void) {
  int N, M;
  cin >> N >> M;

  dp.resize(N + 1);

  vector<int> woks(M);
  for (int &wok : woks) {
    cin >> wok;
  }

  for (int i = 0; i < M; i++) {
    if(set.find(woks[i]) == set.end()) {
      vec.push_back(woks[i]);
      set.insert(woks[i]);
    }

    for (int j = i + 1; j < M; j++) {
      if(set.find(woks[i] + woks[j]) == set.end()) {
        vec.push_back(woks[i] + woks[j]);
        set.insert(woks[i] + woks[j]);
      }
    }
  }
  
  int ans = func(N);
  if (ans == 0) {
    cout << -1;
  } else {
    cout << ans;
  }

  return 0;
}