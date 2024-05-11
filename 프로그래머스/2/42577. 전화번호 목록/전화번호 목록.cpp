#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    unordered_set <string> set;
    for (string number : phone_book) {
        set.insert(number);
    }

    for (string number : phone_book) {
        for (int size = 0; size < number.size(); size++) {
            if (set.find(number.substr(0, size)) != set.end()) return false; 
        }
    }
    return true;
}