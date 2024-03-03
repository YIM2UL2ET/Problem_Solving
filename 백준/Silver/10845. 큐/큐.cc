#include <iostream>

class queue
{
private:
    int nfront, rear;
    int ary[2000001];
public:
    queue() {nfront = 0, rear = 0;}
    ~queue() {};

    int empty(void) {
        if (rear == nfront) return 1;
        return 0;
    }

    void push(int n) {
        ary[rear++] = n;
    }

    int pop(void) {
        if (empty()) return -1;
        return ary[nfront++];
    }

    int front(void) {
        if (empty()) return -1;
        return ary[nfront];
    }

    int back(void) {
        if (empty()) return -1;
        return ary[rear-1];
    }

    int size(void) {
        return rear - nfront;
    }
};


int main(void)
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(NULL);

    int n, e;
    std::string str;
    queue que;
    
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> str;
        if (str == "push") {
            std::cin >> e;
            que.push(e);
        }
        else if (str == "pop") std::cout << que.pop() << '\n';
        else if (str == "size") std::cout << que.size() << '\n';
        else if (str == "empty") std::cout << que.empty() << '\n';
        else if (str == "front") std::cout << que.front() << '\n';
        else if (str == "back") std::cout << que.back() << '\n';
    }
}