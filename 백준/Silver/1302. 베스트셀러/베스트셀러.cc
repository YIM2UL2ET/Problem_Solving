#include <iostream>
#include <algorithm>
#include <vector>

struct book {
    std::string name;
    int s_volume;
};

bool comp (book b1, book b2) {
    if (b1.s_volume == b2.s_volume) return b1.name < b2.name;
    return b1.s_volume > b2.s_volume;
}


int main(void)
{
    int n;
    std::string book_name;
    std::vector <book> list;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int cnt;
        std::cin >> book_name;
        for (cnt = 0; cnt < list.size(); cnt++) {
            if (list[cnt].name == book_name) {
                list[cnt].s_volume++;
                break;
            }
        }
        if (cnt == list.size()) list.push_back({book_name, 1});
    }
    
    std::sort(list.begin(), list.end(), comp);
    std::cout << list[0].name;
    return 0;
}