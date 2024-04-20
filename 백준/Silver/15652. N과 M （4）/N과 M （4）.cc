#include <iostream>
#include <vector>
using namespace std;

void print(vector <int> set) {
    for (int item : set) cout << item << ' ';
    cout << '\n';
}

void dfs(vector <int> &set, int start, int end, int cnt) {
    if (!cnt) print(set);
    else {
        for (int i = start; i <= end; i++) {
            set.push_back(i);
            dfs(set, i, end, cnt-1);
            set.pop_back();
        }
    }
}

int main(void) {
    int n, m;
    vector <int> set;

    cin >> n >> m;

    dfs(set, 1, n, m);
    return 0;
}