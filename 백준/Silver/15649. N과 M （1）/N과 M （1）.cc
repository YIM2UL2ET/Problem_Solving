#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void dfs(int cnt, int n, vector <int> seq) {
    if (cnt == 0) {
        for (int item : seq) cout << item << ' ';
        cout << '\n';
    }
    else {
        for (int i = 1; i <= n; i++) {
            if (find(seq.begin(), seq.end(), i) == seq.end()) {
                seq.push_back(i);
                dfs(cnt-1, n, seq);
                seq.pop_back();
            }
        }
    }
}

int main(void) {
    int n, m;
    vector <int> seq;

    cin >> n >> m;
    dfs(m, n, seq);
    return 0;
}