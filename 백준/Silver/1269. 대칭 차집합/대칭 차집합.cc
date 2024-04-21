#include <iostream>
#include <map>
using namespace std;

int main(void) {
    int n, m, num;
    map<int, bool> set;

    cin >> n >> m;
    for (int i = 0; i < n+m; i++) {
        cin >> num;
        // if(set.find(num) != set.end())
        // set.count(num) > 0
        if (set[num] == true) set.erase(num);
        else set[num] = true;
        // set.insert({num, true});
    }
    cout << set.size();
    return 0;
}