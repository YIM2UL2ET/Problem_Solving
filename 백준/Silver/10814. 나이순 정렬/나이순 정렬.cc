#include <iostream>
#include <algorithm>
#include <vector>

struct member
{
    int age, order;
    std::string name;
};

bool comp (member first, member second) {
    if (first.age == second.age) return first.order < second.order;
    return first.age < second.age;
}

int main(void)
{
    int n;
    std::cin >> n;

    std::vector <member> list(n);
    for (int i = 0; i < n; i++) {std::cin >> list[i].age >> list[i].name; list[i].order = i;}
    std::sort(list.begin(), list.end(), comp);
    for (int i = 0; i < n; i++) std::cout << list[i].age << " " << list[i].name << "\n";
    
    return 0;
}