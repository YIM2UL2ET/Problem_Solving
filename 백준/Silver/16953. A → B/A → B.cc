#include <iostream>
using namespace std;

int bfs(long n, long m, int cnt) {
    if (n == m) return cnt;
    else if (n > m) return -1;
    else {
        int mulTwo = bfs(n * 2, m, cnt + 1);
        int addOne = bfs(n * 10 + 1, m, cnt + 1);
        if (mulTwo != -1 && addOne != -1) return mulTwo < addOne ? mulTwo : addOne; 
        else if (addOne != -1) return addOne;
        else if (mulTwo != -1) return mulTwo;
        else return -1;
    }
}

int main(void) {
    long long n, m;
    cin >> n >> m;
    cout << bfs(n, m, 1);
    return 0;
}