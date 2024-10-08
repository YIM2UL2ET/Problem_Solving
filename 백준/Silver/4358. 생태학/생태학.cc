#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cout << fixed; cout.precision(4);

    int cnt = 0;
    string str;
    unordered_map <string, int> trees;

    while (getline(cin, str)) {
        cnt++;
        if (trees.find(str) == trees.end()) {
            trees.insert({str, 1});
        } else {
            trees[str]++;
        }
    }

    vector <pair <string, int>> vec(trees.begin(), trees.end());
    sort (vec.begin(), vec.end());

    for (auto &el : vec) {
        cout << el.first << ' ' << el.second / double(cnt) * 100 << '\n';
    }

    return 0;
}