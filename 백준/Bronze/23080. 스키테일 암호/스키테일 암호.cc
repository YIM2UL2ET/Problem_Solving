#include <iostream>
using namespace std;

int main() {
  int n;
  string str;

  cin >> n >> str;
  for (int i = 0; i < str.size(); i++) {
    if (i % n == 0) cout << str[i];
  }
  return 0;
}