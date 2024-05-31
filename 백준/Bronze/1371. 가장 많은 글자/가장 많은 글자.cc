#include <iostream>
#include <cctype>
#include <vector>
using namespace std;

int main(void) {
    vector<int> v(26);
    string str;

    char c;;
    while(cin >> c) {
        if(isalpha(c)) v[c - 'a']++;
    }

    vector<int> ans(1, 0);
    for (int i = 1; i < 26; i++) {
        if (v[ans.front()] < v[i]) {
            ans.clear();
            ans.push_back(i);
        } else if (v[ans.front()] == v[i]) {
            ans.push_back(i);
        }
    }
    
    for (int idx : ans) {
        cout << char(idx + 'a');
    }
    return 0;
}