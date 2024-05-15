#include <iostream>
using namespace std;

int main(void) {
  int N;
  string str;
  
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> str;
    for (char &ch : str) {
      if (ch != 'l' && ch != 'o') ch = 'x';
    }

    if (str.find("lol") != string::npos) {
      cout << 0 << '\n';
    } else if(str.find("lo") != string::npos) {
      cout << 1 << '\n';
    } else if (str.find("ol") != string::npos) {
      cout << 1 << '\n';
    } else if (str.find("ll") != string::npos) {
      cout << 1 << '\n';
    } else if (str.find("lxl") != string::npos) {
      cout << 1 << '\n';
    } else if (str.find("l") != string::npos) {
      cout << 2 << '\n';
    } else if (str.find("o") != string::npos) {
      cout << 2 << '\n';
    } else {
      cout << 3 << '\n';
    }
  }
  
  return 0;
}