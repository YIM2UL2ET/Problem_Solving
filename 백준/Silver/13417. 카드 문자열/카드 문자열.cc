#include <iostream>
#include <deque>

using namespace std;

void solve() {
    int n;
    char ch, min = 'z';
    deque <char> deq;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ch;
        if (min >= ch) {
            deq.push_front(ch);
            min = ch;
        } else {
            deq.push_back(ch);
        }
    }
    
    for (char c : deq) {
        cout << c;
    }
    cout << '\n';
}

int main() {
    int cnt;
    cin >> cnt;
    
    for (int i = 0; i < cnt; i++) {
        solve();
    }
    
    return 0;
}