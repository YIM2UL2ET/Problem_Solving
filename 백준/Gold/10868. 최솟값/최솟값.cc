#include <iostream>
#include <vector>

using namespace std;

vector <int> segtree;
vector <int> seq;

int minValue(int n, int s, int e, int l, int r) {
    if (r < s || e < l) return 1e9 + 1;

    if (l <= s && e <= r) {
        return segtree[n];
    } else {
        return min(minValue(n * 2, s, (s + e) / 2, l, r), minValue(n * 2 + 1, (s + e) / 2 + 1, e, l, r));
    }
}

void initTree(int n, int s, int e) {
    if (s == e) {
        segtree[n] = seq[s];
    } else {
        initTree(n * 2, s, (s + e) / 2);
        initTree(n * 2 + 1, (s + e) / 2 + 1, e);
        segtree[n] = min(segtree[n * 2], segtree[n * 2 + 1]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    seq.resize(N + 1);
    segtree.resize(N * 4);

    for (int i = 1; i <= N; i++) {
        cin >> seq[i];
    }

    initTree(1, 1, N);

    int l, r;
    for (int i = 0; i < Q; i++) {
        cin >> l >> r;
        cout << minValue(1, 1, N, l, r) << '\n';
    }
    return 0;
}