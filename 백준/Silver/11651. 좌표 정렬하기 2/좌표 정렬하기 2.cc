#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp (pair <int, int> p1, pair <int, int> p2) {
  if (p1.second == p2.second) return p1.first < p2.first;
  return p1.second < p2.second;
}

int main (void) {
  int n;
  cin >> n;

  vector <pair <int, int>> points(n);
  for (auto &point : points) {
    cin >> point.first >> point.second;
  }

  sort(points.begin(), points.end(), comp);

  for (auto &point : points) {
    cout << point.first << ' ' << point.second << '\n';
  }
  
  return 0;
}