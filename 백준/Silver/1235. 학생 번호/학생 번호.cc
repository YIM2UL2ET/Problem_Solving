#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
    bool res_find = false;
    int n, cnt, str_size;
    cin >> n;

    vector <string> str_list(n);
    vector <string> str_tmp(n);
    for (string &str : str_list) cin >> str;

    cnt = 0;
    str_size = str_list.front().size();
    while (!res_find) {
        cnt++;
        res_find = true;
        for (string str : str_list) {
            auto tmp = str.substr(str_size - cnt, cnt);
            if (find(str_tmp.begin(), str_tmp.end(), tmp) == str_tmp.end()) {
                str_tmp.push_back(tmp);
            }
            else {
                res_find = false;
                break;
            }
        }
        str_tmp.clear();
    }
    cout << cnt;
    return 0;
}