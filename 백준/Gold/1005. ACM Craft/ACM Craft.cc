#include <iostream>
#include <vector>

using namespace std;

vector <int> memo;
vector <int> build_t;
vector <vector <int>> edges;

int dfs(int idx) {
	if (memo[idx] == -1) {
		memo[idx] = build_t[idx];
		for (auto &node : edges[idx]) {
			memo[idx] = max(memo[idx], dfs(node) + build_t[idx]);
		}
	}
	return memo[idx];
}

void solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// input
	int N, K, target, u, v;
	cin >> N >> K;

	edges.resize(N);
	build_t.resize(N);
	memo.resize(N, -1);
	
	for (auto &t : build_t) {
		cin >> t;
	}

	for (int i = 0; i < K; i++) {
		cin >> u >> v;
		edges[v - 1].push_back(u - 1);
	}

	cin >> target;

	//solve
	cout << dfs(target - 1) << '\n';

	//clear
	edges.clear();
	build_t.clear();
	memo.clear();
}

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		solve();
	}

	return 0;
}