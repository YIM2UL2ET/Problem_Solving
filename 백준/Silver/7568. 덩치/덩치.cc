#include <iostream>
#include <vector>

struct dsize
{
    int weight, height;
};


int main(void)
{
    int n;
    std::cin >> n;

    std::vector <dsize> vec(n);
    for (int i = 0; i < n; i++) std::cin >> vec[i].height >> vec[i].weight;

    for (int i = 0; i < n; i++) {
        int res = 1;
        for (int j = 0; j < n; j++) {
            if (i != j && vec[i].height < vec[j].height && vec[i].weight < vec[j].weight) res++; 
        }
        std::cout << res << " ";
    }
    return 0;
}