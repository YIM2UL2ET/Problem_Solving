#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  int target, primeNumSumSize;
  cin >> target;

  vector<bool> isPrime(target + 1, true);
  vector<int> primeNumSum(1);

  primeNumSumSize = 1;
  isPrime[0] = false;
  isPrime[1] = false;
  for (int i = 2; i <= sqrt(target); i++) {
    if (isPrime[i]) {
      primeNumSum.push_back(primeNumSum[primeNumSumSize - 1] + i);
      primeNumSumSize++;

      int k = i;
      while (k <= target) {
        isPrime[k] = false;
        k += i;
      }
    }
  }
  for (int i = sqrt(target); i <= target; i++) {
    if (isPrime[i]) {
      primeNumSum.push_back(primeNumSum[primeNumSumSize - 1] + i);
      primeNumSumSize++;
    }
  }

  int left, right, result;

  left = 0;
  right = 0;
  result = 0;
  while (right < primeNumSumSize) {
    if (target <= primeNumSum[right] - primeNumSum[left]) {
      if (target == primeNumSum[right] - primeNumSum[left]) {
        result++;
      }
      left++;
    } else {
      right++;
    }
  }

  cout << result;

  return 0;
}