#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    vector<int> v = {1, 1, 2, 2, 2, 8};
    for (int i = 0; i < 6; i++) {
        cin >> n;
        cout << v[i] - n << ' ';
    }
    return 0;
}