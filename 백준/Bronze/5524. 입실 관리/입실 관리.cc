#include <iostream>
#include <cctype>
using namespace std;

int main(void) {
    int n;
    string str;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str;
        for (char ch : str) cout << char(tolower(ch));
        cout << '\n';
    }
    return 0;
}