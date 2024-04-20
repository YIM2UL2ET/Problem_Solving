#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void print(vector <int> set) {
    for (int item : set) cout << item << ' ';
    cout << '\n';
}

void dfs(vector <int> &set, vector <int> &res, int cnt) {
    if (!cnt) print(res);
    else {
        for (int i = 0; i < set.size(); i++) {
            int tmp = set[i];
            res.push_back(set[i]);
            set.erase(set.begin()+i);
            dfs(set, res, cnt-1);
            set.insert(set.begin()+i, tmp);
            res.pop_back();
        }
    }
}

int main(void) {
    int n, m;
    cin >> n >> m;

    vector <int> set(n);
    vector <int> res;

    for (int &item : set) cin >> item;
    sort(set.begin(), set.end());

    dfs(set, res, m);
    return 0;
}