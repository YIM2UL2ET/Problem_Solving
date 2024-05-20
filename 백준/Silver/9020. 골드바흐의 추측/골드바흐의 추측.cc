#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // eratos
  vector<int> primeNums;
  vector<bool> isPrime(20000, true);

  isPrime[0] = false;
  isPrime[1] = false;
  for (int i = 2; i <= sqrt(20000); i++) {
    if (isPrime[i]) {
      primeNums.push_back(i);

      for (int j = i * 2; j <= 20000; j += i) {
        isPrime[j] = false;
      }
    }
  }
  for (int i = sqrt(20000) + 1; i <= 20000; i++) {
    if (isPrime[i]) primeNums.push_back(i);
  }

  // goldbach nums find
  unordered_map<int, int> map;
  vector<pair<int, int>> mapInfo;

  int infoSize = 0;
  for (int p1 : primeNums) {
    for (int p2 : primeNums) {
      if (map[p1 + p2] == false) {
        map[p1 + p2] = infoSize++;
        mapInfo.push_back({p1, p2});
      } else {
        int index = map[p1 + p2];
        if (abs(mapInfo[index].first - mapInfo[index].second) > abs(p1 - p2)) {
          mapInfo[index].first = p1;
          mapInfo[index].second = p2;
        }
      }
    }
  }

  // solve
  int T, N;
  cin >> T;

  for (int i = 0; i < T; i++) {
    cin >> N;
    cout << mapInfo[map[N]].first << ' ' << mapInfo[map[N]].second << '\n';
  }

  return 0;
}