#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
    int n, m, row, col;
    string floor;

    row = 0;
    cin >> n >> m;
    vector <bool> colGuard(m, false);
    for (int i = 0; i < n; i++) {
        cin >> floor;
        for (int j = 0; j < m; j++) {
            if (floor[j] == 'X') colGuard[j] = true;
        }
        if (floor.find('X') == string::npos) row++;
    }
    col = count(colGuard.begin(), colGuard.end(), false);
    cout << max(row, col);

    return 0;
}