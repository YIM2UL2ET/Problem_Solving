#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, num;
    string ans;
    stack <int> stk;
    
    cin >> N;
    
    int k = 1;
    for (int i = 0; i < N; i++) {
        cin >> num;
        while (1) {
            if (!stk.empty() && stk.top() == num) {
                stk.pop();
                ans += '-';
                break;
            } else if (k <= num){
                stk.push(k++);
                ans += '+';
            } else {
                cout << "NO";
                return 0;
            }
        }
    }
    
    for (auto &el : ans) {
        cout << el << '\n';
    }
    
    return 0;
}