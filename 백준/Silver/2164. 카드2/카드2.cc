#include <iostream>
#include <queue>

int main(void)
{
    int n;
    std::queue <int> que;

    std::cin >> n;
    for (int i = 1; i <= n; i++) que.push(i);

    while (que.size() > 1) {
        que.pop();
        int tmp = que.front();
        que.pop();
        que.push(tmp);
    }
    
    std::cout << que.front();
    return 0;
}