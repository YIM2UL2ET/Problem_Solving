#include <iostream>
void func1(int n, int m)
{
    for (int i = 0; i < m; i++) std::cout << "* ";
    for (int i = 0; i < 4*(n-1)+1; i++) std::cout << "*";
    for (int i = 0; i < m; i++) std::cout << " *";
    std::cout << "\n";
}

void func2(int n, int m)
{
    for (int i = 0; i < m; i++) std::cout << "* ";
    std::cout << "*";
    for (int i = 0; i < 4*(n-1)-1; i++) std::cout << " ";
    std::cout << "*";
    for (int i = 0; i < m; i++) std::cout << " *";
    std::cout << "\n";
}

void func(int n, int m, char* commend)
{
    if (commend == "front") {
        func1(n, m);
        func2(n, m);
    }
    else {
        func2(n, m);
        func1(n, m);
    }
}

void star(int n, int m)
{
    if (n == 1) {
        for (int i = 0; i < (n+m)*2-1; i++) std::cout << "* ";
        std::cout << "\n";
    }
    else {
        func(n, m, "front");
        star(n-1, m+1);
        func(n, m, "back");
    }

}

int main(void)
{
    int n;
    std::cin >> n;
    star(n, 0);
    return 0;
}