#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  int n;
  cin >> n;

  vector<int> v(n);
  for (int &i : v) {
    cin >> i;
  }

  sort(v.rbegin(), v.rend());

  for (int i : v) {
    cout << i << '\n';
  }
  return 0;
}