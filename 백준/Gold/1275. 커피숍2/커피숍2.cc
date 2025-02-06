#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

vector <ll> tree;

void update(int n, int s, int e, int p, ll v) {
    if (p < s || e < p) return;

    if (s == e) {
        tree[n] = v;
    } else {
        update(n * 2, s, (s + e) / 2, p, v);
        update(n * 2 + 1, (s + e) / 2 + 1, e, p, v);
        tree[n] = tree[n * 2] + tree[n * 2 + 1];
    }
}

ll sum(int n, int s, int e, int l, int r) {
    if (r < s || e < l) return 0;

    if (l <= s && e <= r) {
        return tree[n];
    } else {
        return sum(n * 2, s, (s + e) / 2, l, r) + sum(n * 2 + 1, (s + e) / 2 + 1, e, l, r);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    tree.resize(N * 4);

    int x, y, a;
    ll b;
    for (int i = 1; i <= N; i++) {
        cin >> b;
        update(1, 1, N, i, b);
    }

    for (int i = 0; i < Q; i++) {
        cin >> x >> y >> a >> b;
        if (x > y) swap(x, y);
        cout << sum(1, 1, N, x, y) << '\n';
        update(1, 1, N, a, b);
    }

    return 0;
}