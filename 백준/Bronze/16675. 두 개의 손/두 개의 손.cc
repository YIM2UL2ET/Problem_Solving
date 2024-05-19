#include <iostream>
using namespace std;

bool isCWin(char p, char c1, char c2) {
  if (p == 'S' && (c1 == 'R' || c2 == 'R')) {
    return true;
  } else if (p == 'R' && (c1 == 'P' || c2 == 'P')) {
    return true;
  } else if (p == 'P' && (c1 == 'S' || c2 == 'S')) {
    return true;
  } else {
    return false;
  }
}

int main(void) {
  char m1, m2, t1, t2;
  cin >> m1 >> m2 >> t1 >> t2;

  if (m1 == m2 && t1 == t2) {
    if (isCWin(m1, t1, t2)) {
      cout << "TK";
    } else if (isCWin(t1, m1, m2)) {
      cout << "MS";
    } else {
      cout << "?";
    }
  } else if (m1 == m2) {
    if (isCWin(m1, t1, t2)) {
      cout << "TK";
    } else {
      cout << "?";
    }
  } else if (t1 == t2) {
    if (isCWin(t1, m1, m2)) {
      cout << "MS";
    } else {
      cout << "?";
    }
  } else {
    cout << "?";
  }

  return 0;
}