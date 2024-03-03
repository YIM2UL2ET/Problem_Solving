#include <iostream>
#define MAX_STACK_SIZE 10002

class stack
{
private:
    int ntop;
    int ary[MAX_STACK_SIZE];
public:
    stack() {ntop = -1;}
    ~stack() {};

    int empty(void) {
        if (ntop == -1) return 1;
        else return 0;
    }

    void push(int n) {
        ary[++ntop] = n;
    }

    int pop(void) {
        if (empty()) return -1;
        else return ary[ntop--];
    }

    int top(void) {
        if (empty()) return -1;
        else return ary[ntop];
    }

    int size(void) {
        return ntop+1;
    }
};


int main(void)
{
    int n;
    std::string str;
    stack stk;
    
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> str;
        if (str == "push") {
            int e;
            std::cin >> e;
            stk.push(e);
        }
        else if (str == "pop") std::cout << stk.pop() << std::endl;
        else if (str == "size") std::cout << stk.size() << std::endl;
        else if (str == "empty") std::cout << stk.empty() << std::endl;
        else if (str == "top") std::cout << stk.top() << std::endl;
    }
}