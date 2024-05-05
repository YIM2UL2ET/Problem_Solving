#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

set <vector <int>> res;
vector <int> nums;

void BackTracking (int cnt, int num, vector <int> &vec) {
    if (cnt == 0 && res.find(vec) == res.end()) {
        res.insert(vec);
        for (int n : vec) {
            cout << n << ' ';
        }
        cout << '\n';
    }
    else if (cnt > 0) {
        for (int n : nums) {
            if (n >= num) {
                vec.push_back(n);
                BackTracking(cnt-1, n, vec);
                vec.pop_back();
            }
        }
    }
}

int main(void) {
    int n, m, c;
    cin >> n >> m;

    set <int> s;
    vector <int> res;

    for (int i = 0; i < n; i++) {
        cin >> c;
        if (s.find(c) == s.end()) {
            nums.push_back(c);
            s.insert(c);
        }
    }
    
    sort(nums.begin(), nums.end());
    BackTracking(m, nums.front(), res);

    return 0;
}