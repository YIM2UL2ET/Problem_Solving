#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector <int> parent;

int getParent(int n) {
    if (parent[n] == n) return n;
    return parent[n] = getParent(parent[n]);
}

void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);

    if (a < b) {
        parent[b] = a;
    } else {
        parent[a] = b;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    parent.resize(N + 1);
    for (int i = 0; i <= N; i++) {
        parent[i] = i;
    }
    
    bool is_connect;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> is_connect;
            if (is_connect) {
                unionParent(i, j);
            }
        }
    }
    
    string ans = "YES";
    if (M > 0) {
        int city, root;

        cin >> city;
        root = getParent(city);
        for (int i = 1; i < M; i++) {
            cin >> city;
            if (root != getParent(city)) {
                ans = "NO";
            }
        }
    } else {
        ans = "NO";
    }

    cout << ans;
    return 0;
}