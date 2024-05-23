#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct lectore {
  int a, b, c;
};

int main(void) {
  int N, K, temp, ans;
  cin >> N >> K;

  vector<lectore> lectures(N);
  for (auto &lec : lectures) {
    cin >> lec.a >> lec.b >> lec.c;
  }

  ans = 0;

  temp = 0;
  sort(lectures.begin(), lectures.end(),
       [](lectore lec1, lectore lec2) -> bool {
         return lec1.a + lec1.b > lec2.a + lec2.b;
       });
  for (int i = 0; i < K; i++) {
    temp += lectures[i].a;
    temp += lectures[i].b;
  }
  if(ans < temp) ans = temp;

  temp = 0;
  sort(lectures.begin(), lectures.end(),
       [](lectore lec1, lectore lec2) -> bool {
         return lec1.b + lec1.c > lec2.b + lec2.c;
       });
  for (int i = 0; i < K; i++) {
    temp += lectures[i].b;
    temp += lectures[i].c;
  }
  if(ans < temp) ans = temp;

  temp = 0;
  sort(lectures.begin(), lectures.end(),
       [](lectore lec1, lectore lec2) -> bool {
         return lec1.a + lec1.c > lec2.a + lec2.c;
       });
  for (int i = 0; i < K; i++) {
    temp += lectures[i].a;
    temp += lectures[i].c;
  }
  if(ans < temp) ans = temp;
  
  cout << ans;

  return 0;
}