#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

unordered_set <string> set;
vector <string> board(5, "     ");
vector <pair <int, int>> offset{{0,1}, {0,-1}, {1,0}, {-1,0}};

void dfs(int r, int c, string res) {
    res += board[r][c];
    if (res.size() == 6) {
        if (set.find(res) == set.end()) {
            set.insert(res);
        }
    }
    else {
        for (auto set : offset) {
            int nr = set.first + r, nc = set.second + c;
            if (nr >= 0 && nr < 5 && nc >= 0 && nc < 5) {
                dfs(nr, nc, res);
            }
        }
    }
}

int main(void) {
    for (string &row : board) {
        for (char &ch : row) cin >> ch;
    }
    
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            dfs(r, c, "");
        }
    }
    
    cout << set.size();
    return 0;
}