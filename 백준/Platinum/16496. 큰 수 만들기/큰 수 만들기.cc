#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector <string> vec(N);
    for (auto &s : vec) {
        cin >> s;
    }

    sort(vec.begin(), vec.end(), [](string &s1, string &s2) -> bool {
        return s1 + s2 > s2 + s1;
    });

    bool isPrint = false;
    for (auto &s : vec) {
        if (s == "0" && !isPrint) {
            continue;
        } else {
            isPrint = true;
            cout << s;
        }
    }
    if (!isPrint) cout << '0';

    return 0;
}