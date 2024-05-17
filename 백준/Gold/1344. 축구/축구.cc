#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n) {
  vector<int> primeNums{2, 3, 5, 7, 11, 13, 17};
  for (int p : primeNums) {
    if (p == n) return true;
  }
  return false;
}

int main(void) {
  long double A, B;
  cin >> A >> B;

  vector<vector<long double>> ScoreProb(19, vector<long double>(19, 0.0));

  A /= 100.0;
  B /= 100.0;
  ScoreProb[0][0] = 1.0;

  for (int time = 0; time < 18; time++) {
    vector<vector<long double>> temp(19, vector<long double>(19, 0.0));

    for (int i = 0; i <= 18; i++) {
      for (int j = 0; j <= 18; j++) {
        if (j > 0) temp[i][j] += ScoreProb[i][j - 1] * A * (1.0 - B);
        if (i > 0) temp[i][j] += ScoreProb[i - 1][j] * (1.0 - A) * B;
        if (i > 0 && j > 0) temp[i][j] += ScoreProb[i - 1][j - 1] * A * B;
        temp[i][j] += ScoreProb[i][j] * (1.0 - A) * (1.0 - B);
      }
    }

    ScoreProb = temp;
  }

  long double result = 0.0;
  for (int i = 0; i <= 18; i++) {
    for (int j = 0; j <= 18; j++) {
      if (isPrime(i) || isPrime(j)) result += ScoreProb[i][j];
    }
  }
  
  cout << fixed;
  cout.precision(10);
  cout << result;

  return 0;
}