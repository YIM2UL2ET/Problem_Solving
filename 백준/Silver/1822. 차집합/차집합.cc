#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;

    vector <int> A(n);
    vector <int> B(m);
    vector <int> result;
    for (int &a : A) cin >> a;
    for (int &b : B) cin >> b;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    auto ait = A.begin();
    auto bit = B.begin();
    while (ait != A.end() && bit != B.end()) {
        if (*ait < *bit) {
            result.push_back(*ait);
            ait++;
        }
        else if (*ait > *bit) bit++;
        else ait++;
    }
    while (ait != A.end()) {
        result.push_back(*ait);
        ait++;
    }

    cout << result.size() << '\n';
    for (int num : result) cout << num << ' ';

    return 0;   
}