#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;

class point {
 private:
  ll x = 0, y = 0;

 public:
  point(int _x, int _y) { x = _x, y = _y; };

  point operator-(const point &v) { return point(x - v.x, y - v.y); }

  point operator*(const int &k) { return point(k * x, k * y); }

  ll cross(const point &v) { return x * v.y - y * v.x; }
};

ll ccw(point a, point b) { return a.cross(b); }

ll ccw(point p, point a, point b) { return ccw(p - a, p - b); }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll x, y;
  cin >> x >> y;
  point a(x, y);
  cin >> x >> y;
  point b(x, y);
  cin >> x >> y;
  point c(x, y);

  ll res = ccw(a, b, c);
  if (res > 1) res = 1;
  if (res < -1) res = -1;
  cout << res;
  return 0;
}