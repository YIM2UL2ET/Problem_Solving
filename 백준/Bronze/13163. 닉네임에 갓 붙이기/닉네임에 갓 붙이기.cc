#include <iostream>
#include <sstream>
using namespace std;

int main() {
  int n;
  cin >> n;

  stringstream ss;
  string str;

  getchar();
  for (int i = 0; i < n; i++) {
    getline(cin, str);

    ss.str(str);
    ss >> str;

    cout << "god";
    while (ss >> str) {
      cout << str;
    }
    cout << '\n';
    ss.clear();
  }
  return 0;
}