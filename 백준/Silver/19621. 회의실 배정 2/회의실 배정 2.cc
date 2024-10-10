#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct meeting { int start, end, people; };

vector <meeting> vec;
vector <int> memo;

int main() {
    // fastIO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // init && input
    int N;
    cin >> N;
    
    vec.resize(N + 1);
    memo.resize(N + 1);
    
    for (int i = 1; i <= N; i++) {
        cin >> vec[i].start >> vec[i].end >> vec[i].people;
    }
    
    // solve
    memo[1] = vec[1].people;
    for (int i = 2; i <= N; i++) {
        memo[i] = max(memo[i - 1], memo[i - 2] + vec[i].people);
    }
    
    // output
    cout << memo[N];
    return 0;
}