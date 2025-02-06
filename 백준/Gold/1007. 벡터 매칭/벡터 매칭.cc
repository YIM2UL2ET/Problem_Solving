#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

typedef long double ld;

vector <ld> Xvec;
vector <ld> Yvec;

ld len(ld curX, ld curY) {
    return sqrt((curX * curX) + (curY * curY));
}

ld minV(int i, int N, int addCnt, int subCnt, ld curX, ld curY) {
    if (addCnt > N / 2 || subCnt > N / 2) return 1e6 * 2;

    if (i == N) return len(curX, curY);

    auto a = minV(i + 1, N, addCnt + 1, subCnt, curX + Xvec[i], curY + Yvec[i]);
    auto s = minV(i + 1, N, addCnt, subCnt + 1, curX - Xvec[i], curY - Yvec[i]);
    return min(a, s);
}

void solve() {
    int N;
    cin >> N;

    Xvec.resize(N);
    Yvec.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> Xvec[i] >> Yvec[i];
    }

    cout << minV(0, N, 0, 0, 0, 0) << '\n';

    Xvec.clear();
    Yvec.clear();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << fixed;
    cout.precision(7);

    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}