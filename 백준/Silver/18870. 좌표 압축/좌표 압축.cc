#include <iostream>
#include <vector>
#include <algorithm>

struct node {int index, value, res;};

int main(void) {
    int n, k;
    std::cin >> n;
    
    std::vector <node> vec(n);
    for (int i = 0; i < n; i++) {
        std::cin >> k;
        vec[i] = {i, k, 0};
    }
    
    std::sort(vec.begin(), vec.end(), [](node n1, node n2) -> bool {return n1.value < n2.value;});
    
    k = 0, vec[0].res = 0;
    for (int i = 1; i < n; i++) {
        if (vec[i-1].value < vec[i].value) k++;
        vec[i].res = k;
    }
    
    std::sort(vec.begin(), vec.end(), [](node n1, node n2) -> bool {return n1.index < n2.index;});
    for (int i = 0; i < n; i++) std::cout << vec[i].res << ' ';
    
    return 0;
}