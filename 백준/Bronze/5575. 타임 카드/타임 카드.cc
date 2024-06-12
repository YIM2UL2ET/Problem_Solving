#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  int ah, am, as, lh, lm, ls;
  for (int i = 0; i < 3; i++) {
    cin >> ah >> am >> as >> lh >> lm >> ls;
    int ans = (lh * 3600 + lm * 60 + ls) - (ah * 3600 + am * 60 + as);

    int h = ans / 3600;
    int m = (ans % 3600) / 60;
    int s = (ans % 3600) % 60;

    cout << h << ' ' << m << ' ' << s << '\n';
  }

  return 0;
}