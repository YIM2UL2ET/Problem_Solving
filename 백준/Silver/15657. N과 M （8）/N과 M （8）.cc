#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> set;

void func(vector <int> &result, int cnt, int idx) {
    if (!cnt) {
        for (auto item : result) cout << item << ' ';
        cout << '\n';
    }
    else {
        for (int i = idx; i < set.size(); i++) {
            result.push_back(set[i]);
            func(result, cnt-1, i);
            result.pop_back();
        }
    }
}

int main(void) {
    int n, m;
    vector <int> result;

    cin >> n >> m;
    set.resize(n);
    for (auto &item : set) cin >> item;

    sort(set.begin(), set.end());
    func(result, m, 0);
    return 0;
}