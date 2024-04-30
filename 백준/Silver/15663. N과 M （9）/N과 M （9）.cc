#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

set<vector <int>> sett;

void backTracking(int cnt, vector <int> &result, vector <int> &nums) {
    if (!cnt && sett.find(result) == sett.end()) {
        sett.insert(result);
        for (auto item : result) cout << item << ' ';
        cout << '\n';
    }
    else if (cnt > 0) {
        for (auto it = nums.begin(); it != nums.end(); it++) {
            int temp = *it;
            result.push_back(*it);
            nums.erase(it);

            backTracking(cnt-1, result, nums);

            result.pop_back();
            nums.insert(it, temp);
        }
    }
}

int main(void) {
    int n, m, num;
    vector <int> seq;
    vector <int> nums;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num;
        nums.push_back(num);
    }
    
    sort(nums.begin(), nums.end());
    backTracking(m, seq, nums);
    return 0;
}