#include <iostream>
using namespace std;

int main(void) {
    int tmp, h, d;
    h = INT32_MAX, d = INT32_MAX;
    for (int i = 0; i < 3; i++) {
        cin >> tmp;
        if (h > tmp) h = tmp;
    }
    for (int i = 0; i < 2; i++) {
        cin >> tmp;
        if (d > tmp) d = tmp;
    }
    cout << h + d - 50;
    return 0;
}