#include <iostream>
using namespace std;

int main(void) {
    int n, ans;
    string str, target;

    cin >> target >> n;

    ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> str;
        str += str;
        if (str.find(target) != string::npos) ans++;
    }

    cout << ans;
    
    return 0;
}