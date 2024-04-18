#include <iostream>
#include <vector>
using namespace std;

void dfs(int n, int k, int m, vector <int> vec) {
    if (vec.size() == m) {
        for (auto item : vec) cout << item << ' ';
        cout << '\n';
    }
    else {
        for (int i = k; i <= n; i++) {
            vec.push_back(i);
            dfs(n, i+1, m, vec);
            vec.pop_back();
        }
    }
}

int main(void) {
    int n, m;
    cin >> n >> m;
    vector <int> vec;
    dfs(n, 1, m, vec);
    return 0;
}