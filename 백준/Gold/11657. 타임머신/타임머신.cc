#include <iostream>
#include <vector>
#define INF 100000000
using namespace std;

struct link {int cur, next, cost;};

bool bellman (vector <link> &info, vector <long long> &result, int size) {
    result[0] = 0;

    for (int i = 1; i < size; i++) {
        for (int j = 0; j < info.size(); j++) {
            int from = info[j].cur - 1;
            int to = info[j].next - 1;
            int cost = info[j].cost;

            if (result[from] != INF && result[to] > result[from] + cost) {
                result[to] = result[from] + cost;
            }
        }
    }
    
    for (int i = 0; i < info.size(); i++) {
        int from = info[i].cur - 1;
        int to = info[i].next - 1;
        int cost = info[i].cost;

        if (result[from] != INF && result[to] > result[from] + cost) return false;
    }

    return true;
}

int main(void) {
    int n, m;
    cin >> n >> m;

    vector <long long> result(n, INF);
    vector <link> info(m);
    for (auto &p : info) {
        cin >> p.cur >> p.next >> p.cost;
    }
    
    if (n == 1) return 0;
    else if (bellman(info, result, n)) {
        for (int i = 1; i < n; i++) {
            if (result[i] != INF) cout << result[i] << '\n';
            else cout << -1 << '\n';
        }
    }
    else cout << -1;
    
    return 0;
}