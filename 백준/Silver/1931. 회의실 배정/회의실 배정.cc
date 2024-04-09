#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool comp(pair <int, int> p1, pair <int, int> p2) {
    if (p1.second == p2.second) return p1.first < p2.first;
    return p1.second < p2.second;
}

int main(void) {
    int n, res = 0, end = 0;
    cin >> n;

    vector <pair <int, int>> meetings(n);
    for (int i = 0; i < n; i++) cin >> meetings[i].first >> meetings[i].second;
    
    sort(meetings.begin(), meetings.end(), comp);
    for (int i = 0; i < n; i++) {
        if (end <= meetings[i].first) res++, end = meetings[i].second;
    }
    
    cout << res;
    return 0;
}