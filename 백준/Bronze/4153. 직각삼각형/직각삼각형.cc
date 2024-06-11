#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  vector<int> v(3);

  cin >> v[0] >> v[1] >> v[2];
  while (v[0] != 0 && v[1] != 0 && v[2] != 0) {
    sort(v.rbegin(), v.rend());

    if (v[0] * v[0] == v[1] * v[1] + v[2] * v[2]) {
      cout << "right\n";
    } else {
      cout << "wrong\n";
    }
    cin >> v[0] >> v[1] >> v[2];
  }

  return 0;
}